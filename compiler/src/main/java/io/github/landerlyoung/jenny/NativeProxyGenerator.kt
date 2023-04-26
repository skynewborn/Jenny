/**
 * Copyright 2016 landerlyoung@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package io.github.landerlyoung.jenny

import io.github.landerlyoung.jenny.extensions.capitalize
import io.github.landerlyoung.jenny.models.CppClass
import io.github.landerlyoung.jenny.models.FieldRecord
import io.github.landerlyoung.jenny.models.MethodRecord
import java.io.IOException
import java.util.*
import javax.lang.model.element.*
import kotlin.collections.component1
import kotlin.collections.component2

/**
 * Author: landerlyoung@gmail.com
 * Date:   2016-06-05
 * Time:   00:30
 * Life with Passion, Code with Creativity.
 */
class NativeProxyGenerator(env: Environment, clazz: TypeElement, nativeProxy: NativeProxyConfig) :
    AbsCodeGenerator(env, clazz) {

    data class NativeProxyConfig(
        val allMethods: Boolean,
        val allFields: Boolean,
        val namespace: String,
        val onlyPublic: Boolean
    ) {
        constructor(proxy: NativeProxy)
                : this(proxy.allMethods, proxy.allFields, proxy.namespace, false)
    }

    //what we need to generate includes
    //---------- id ----------
    //constructor
    //method
    //field
    //-------- getXxxId -------
    //constructor
    //method
    //field
    //------- newInstance ------
    //constructor
    //------- callXxxMethod -----
    //method
    //------ get/setXxxField ----
    //field

    private val mConstructors = mutableListOf<MethodRecord>()
    private val mMethodSimpleName = mutableSetOf<String>()
    private val mMethods = mutableListOf<MethodRecord>()

    //    private val mFields = mutableListOf<VariableElement>()
    private val mFields = mutableListOf<FieldRecord>()
    private val mConstants: MutableSet<VariableElement> = LinkedHashSet()
    private val mNativeProxyConfig = nativeProxy
    private val mNamespaceHelper = NamespaceHelper(mNativeProxyConfig.namespace)
    private val mHeaderName: String
    private val mSourceName: String

    private val cppClassName: String = mSimpleClassName + "Proxy"

    init {
        mHeaderName = mNamespaceHelper.fileNamePrefix + "${cppClassName}.h"
        mSourceName = mNamespaceHelper.fileNamePrefix + "${cppClassName}.cpp"
    }

    private fun init() {
        findConstants()
        findConstructors()
        findMethods()
        findFields()
    }

    override fun doGenerate(): CppClass {
        init()

        log("write native proxy file [$mHeaderName]")
        val cppClass =
            CppClass(mHelper, mClazz, cppClassName, mNamespaceHelper.namespaceNotation, mHeaderName)

        val vars = HashMap<String, Any>().apply {
            put("threadSafe", mEnv.configurations.threadSafe)
            put(
                "errorLogger",
                if (mEnv.configurations.errorLoggerFunction.isNullOrBlank()) false else mEnv.configurations.errorLoggerFunction
            )
            put("class", cppClass)
            put("className", cppClassName)
            put("slashClassName", mSlashClassName)
            put("fullClassName", mClassName)
            put("javaClassName", mSimpleClassName)
            put("namespaces", mNamespaceHelper.namespaces)
            put("constants", getConstantsIdDeclare())
            put("constructors", mConstructors)
            put("methods", mMethods)
            put("fields", mFields)
        }
        val content = mEnv.renderTemplate("templates/proxy_header.vm", vars)
        mEnv.createOutputFile(Constants.JENNY_GEN_DIR_PROXY_FILES, mHeaderName).use { out ->
            try {
                out.write(content.toByteArray(Charsets.UTF_8))
            } catch (e: IOException) {
                warn("generate header file $mHeaderName failed!")
            }
        }

        return cppClass
    }

    private fun getConstantsIdDeclare(): List<String> {
        return mConstants.map {
            mHelper.getConstexprStatement(it)
        }
    }

    private fun shouldGenerateMethod(m: ExecutableElement): Boolean {
        val annotation = m.getAnnotation(NativeMethodProxy::class.java)
        return annotation?.enabled ?: mNativeProxyConfig.allMethods
    }

    private fun shouldGenerateField(f: Element): Boolean {
        return !hasGetterSetter(f).isEmpty()
    }

    private enum class GetterSetter {
        GETTER, SETTER
    }

    private fun hasGetterSetter(field: Element): EnumSet<GetterSetter> {
        var getter = false
        var setter = false

        var auto = mNativeProxyConfig.allFields
        val annotation = field.getAnnotation(NativeFieldProxy::class.java)
        if (annotation != null) {
            auto = false
            getter = annotation.getter
            setter = annotation.setter
        } else {
            if (mConstants.contains(field)) {
                auto = false
                //don't generate
                getter = false
                setter = false
            }
        }

        if (auto) {
            val camelCaseName = field.simpleName.toString().capitalize()
            setter = !mMethodSimpleName.contains("set$camelCaseName")

            val type = mHelper.toJNIType(field.asType())
            getter = !mMethodSimpleName.contains("get$camelCaseName")
            if ("jboolean" == type) {
                getter = getter and !mMethodSimpleName.contains("is$camelCaseName")
            }
        }

        return if (getter && setter) {
            EnumSet.of(GetterSetter.GETTER, GetterSetter.SETTER)
        } else if (getter) {
            EnumSet.of(GetterSetter.GETTER)
        } else if (setter) {
            EnumSet.of(GetterSetter.SETTER)
        } else {
            EnumSet.noneOf(GetterSetter::class.java)
        }
    }


    private fun findConstructors() {
        mClazz.enclosedElements
            .asSequence()
            .filter { it.kind == ElementKind.CONSTRUCTOR }
            .map { it as ExecutableElement }
            .filter { visibilityMatched(it) && shouldGenerateMethod(it) }
            .toList()
            .let {
                MethodOverloadResolver(mHelper, this::getJniMethodParamTypes).resolve(it)
                    .let { mConstructors.addAll(it) }
            }
    }

    private fun findMethods() {
        mClazz.enclosedElements
            .asSequence()
            .filter { it.kind == ElementKind.METHOD }
            .map { it as ExecutableElement }
            .filter { visibilityMatched(it) && shouldGenerateMethod(it) }
            .groupBy { it.simpleName.toString() }
            .forEach { (simpleName, methodList) ->
                mMethodSimpleName.add(simpleName)
                MethodOverloadResolver(mHelper, this::getJniMethodParamTypes).resolve(methodList)
                    .let {
                        mMethods.addAll(it)
                    }
            }
    }

    private fun findConstants() {
        mClazz.enclosedElements
            .asSequence()
            .filter {
                it.kind.isField && visibilityMatched(it)
                        && it.modifiers.containsAll(listOf(Modifier.STATIC, Modifier.FINAL))
                        && (it as VariableElement).constantValue != null
            }
            .forEach { mConstants.add(it as VariableElement) }
    }

    private fun findFields() {
        mClazz.enclosedElements
            .asSequence()
            .filter { it.kind.isField && shouldGenerateField(it) && visibilityMatched(it) }
            .forEachIndexed { index, element ->
                val getterSetter = hasGetterSetter(element)
                mFields.add(FieldRecord(mHelper, element as VariableElement, index,
                    getterSetter.contains(GetterSetter.GETTER),
                    getterSetter.contains(GetterSetter.SETTER)))
            }
    }

    private fun visibilityMatched(element: Element): Boolean {
        if (mNativeProxyConfig.onlyPublic) {
            return element.modifiers.contains(Modifier.PUBLIC)
        }
        return true
    }

    private fun getJniMethodParamTypes(m: ExecutableElement) = buildString {
        var needComma = false
        if (mHelper.isNestedClass(mClazz)) {
            val enclosingElement = mClazz.enclosingElement
            // nested class has an this$0 in its constructor
            append(mHelper.toJNIType(enclosingElement.asType()))
            needComma = true
        }
        m.parameters.forEach { p ->
            if (needComma) append(", ")
            append(mHelper.toJNIType(p.asType()))
            needComma = true
        }
    }

}
