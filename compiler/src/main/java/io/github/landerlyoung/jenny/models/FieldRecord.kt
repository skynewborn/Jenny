package io.github.landerlyoung.jenny.models

import io.github.landerlyoung.jenny.HandyHelper
import io.github.landerlyoung.jenny.extensions.capitalize
import io.github.landerlyoung.jenny.extensions.isRefType
import io.github.landerlyoung.jenny.extensions.toJniTypeForParam
import io.github.landerlyoung.jenny.extensions.toJniTypeForReturn
import java.util.*
import javax.lang.model.element.Modifier
import javax.lang.model.element.VariableElement
import javax.lang.model.type.TypeKind

class FieldRecord(
    private val helper: HandyHelper,
    val field: VariableElement,
    val index: Int,
    val hasGetter: Boolean,
    val hasSetter: Boolean,
) {
    val fieldName: String = field.simpleName.toString()
    val camelCaseName: String = fieldName.capitalize()
    val type: String = field.asType().toString()
    val isRefType: Boolean = field.asType().isRefType()
    val signature: String by lazy { helper.getBinaryTypeSignature(field.asType()) }
    val javaModifiers: String by lazy { helper.getModifiers(field) }
    val jniType: String by lazy { helper.toJNIType(field.asType()) }

//    val symbol: String = fieldName + resolvedPostFix
//    val javaParameters: String by lazy { helper.getJavaMethodParam(field) }
//    val nativeParameters: String by lazy { helper.getNativeMethodParam(field) }

    fun isStatic(): Boolean {
        return field.modifiers.contains(Modifier.STATIC)
    }

    fun toJniTypeForParam(useJniHelper: Boolean): String {
        return field.asType().toJniTypeForParam(helper, useJniHelper)
    }

    fun toJniTypeForReturn(useJniHelper: Boolean): String {
        return field.asType().toJniTypeForReturn(helper, useJniHelper)
    }

    fun getTypeForJniCall(): String {
        val k = field.asType().kind
        val result: String = if (k.isPrimitive || k == TypeKind.VOID) {
            k.name.lowercase(Locale.US)
        } else {
            "object"
        }
        return result.capitalize()
    }

    fun jniTypeNeedCast(): Boolean {
        return when (jniType) {
            "jclass", "jstring", "jarray", "jobjectArray",
            "jbooleanArray", "jbyteArray", "jcharArray",
            "jshortArray", "jintArray", "jlongArray",
            "jfloatArray", "jdoubleArray",
            "jthrowable", "jweak" -> true
            else ->
                // primitive type or jobject or void
                false
        }
    }

}