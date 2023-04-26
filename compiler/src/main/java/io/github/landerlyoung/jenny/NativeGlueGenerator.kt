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

import io.github.landerlyoung.jenny.models.CppClass
import io.github.landerlyoung.jenny.models.MethodRecord
import java.io.IOException
import java.util.*
import javax.lang.model.element.*

/**
 * Author: landerlyoung@gmail.com
 * Date:   2014-12-17
 * Time:   16:03
 * Life with passion. Code with creativity!
 */
class NativeGlueGenerator(env: Environment, clazz: TypeElement) : AbsCodeGenerator(env, clazz) {
    private lateinit var mNamespaceHelper: NamespaceHelper

    // header file name
    private lateinit var mHeaderName: String

    // source file Name
    private lateinit var mSourceName: String
    private val mMethods: MutableList<MethodRecord> = LinkedList()
    private val mNativeClassAnnotation: NativeClass =
        clazz.getAnnotation(NativeClass::class.java)
            ?: AnnotationResolver.getDefaultImplementation(NativeClass::class.java)

    private val cppClassName: String = mSimpleClassName

    override fun doGenerate(): CppClass {
        if (init() && mMethods.isNotEmpty()) {
            generateHeader()
            generateSource()
        }
        return CppClass(mHelper, mClazz, cppClassName, mNamespaceHelper.namespaceNotation, mHeaderName)
    }

    private fun init(): Boolean {
        if (mClazz.kind != ElementKind.CLASS) return false

        mNamespaceHelper = NamespaceHelper(mNativeClassAnnotation.namespace)

        mHeaderName = mNamespaceHelper.fileNamePrefix + "$cppClassName.h"
        mSourceName = mNamespaceHelper.fileNamePrefix + "$cppClassName.cpp"
        log("jenny begin generate glue code for class [$mClassName]")
        log("header: [$mHeaderName], source: [$mSourceName]")

        findNativeMethods()

        return true
    }

    private fun findNativeMethods() {
        mClazz.enclosedElements
            .asSequence()
            .filter { it.kind == ElementKind.METHOD }
            .map { e ->
                if (!e.modifiers.contains(Modifier.NATIVE) && e.getAnnotation(NativeCode::class.java) != null) {
                    error(
                        "Annotation @" + NativeCode::class.java.simpleName
                                + " should only be applied to NATIVE method! found at:${mClassName}.${e}"
                    )
                }
                e as ExecutableElement
            }
            .filter { it.modifiers.contains(Modifier.NATIVE) }
            .groupBy { it.simpleName.toString() }
            .forEach { (_, methods) ->
                MethodOverloadResolver(mHelper) { "" }.resolve(methods).let {
                    mMethods.addAll(it)
                }
            }
    }

    private fun generateHeader() {
        log("write header file [$mHeaderName]")

        try {
            val vars = HashMap<String, Any>().apply {
                put("className", cppClassName)
                put("slashClassName", mSlashClassName)
                put("fullClassName", mClassName)
                put("namespaces", mNamespaceHelper.namespaces)
                put("constants", getConstants())
                put("methods", mMethods)
            }
            val content = mEnv.renderTemplate("templates/jni_header.vm", vars)
            mEnv.createOutputFile(Constants.JENNY_GEN_DIR_GLUE_HEADER, mHeaderName).use { out ->
                out.write(content.toByteArray(Charsets.UTF_8))
            }
        } catch (e: IOException) {
            warn("generate header file $mHeaderName failed!")
        }
    }

    private fun generateSource() {
        log("write source file [$mSourceName]")

        try {
            val vars = HashMap<String, Any>().apply {
                put("className", cppClassName)
                put("fullClassName", mClassName)
                put("headerName", mHeaderName)
                put("namespaces", mNamespaceHelper.namespaces)
                put("methods", mMethods)
            }
            val content = mEnv.renderTemplate("templates/jni_source.vm", vars)
            mEnv.createOutputFile(Constants.JENNY_GEN_DIR_GLUE_SOURCE, mSourceName).use { out ->
                out.write(content.toByteArray(Charsets.UTF_8))
            }
        } catch (e: IOException) {
            warn("generate source file $mSourceName failed")
        }
    }

    private fun getConstants(): List<String> {
        return mClazz.enclosedElements
            .filter {
                it.kind.isField && it.modifiers.containsAll(
                    listOf(
                        Modifier.STATIC,
                        Modifier.FINAL
                    )
                )
            }
            .map { it as VariableElement }
            .filter {
                // if this field is a compile-time constant value it's
                // value will be returned, otherwise null will be returned.
                it.constantValue != null
            }
            .map { mHelper.getConstexprStatement(it) }
    }

}
