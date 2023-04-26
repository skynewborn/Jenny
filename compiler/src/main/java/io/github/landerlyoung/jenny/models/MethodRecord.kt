package io.github.landerlyoung.jenny.models

import io.github.landerlyoung.jenny.HandyHelper
import io.github.landerlyoung.jenny.NativeCode
import io.github.landerlyoung.jenny.extensions.capitalize
import io.github.landerlyoung.jenny.extensions.isRefType
import io.github.landerlyoung.jenny.extensions.toJniTypeForParam
import io.github.landerlyoung.jenny.extensions.toJniTypeForReturn
import java.util.*
import javax.lang.model.element.ExecutableElement
import javax.lang.model.element.Modifier
import javax.lang.model.type.TypeKind

class MethodRecord(
    private val helper: HandyHelper,
    val method: ExecutableElement,
    val resolvedPostFix: String,
    val index: Int
) {
    val methodName: String = method.simpleName.toString()
    val returnType: String = method.returnType.toString()
    val returnVoid: Boolean = method.returnType.kind == TypeKind.VOID
    val symbol: String = methodName + resolvedPostFix
    val signature: String by lazy { helper.getBinaryMethodSignature(method) }
    val javaModifiers: String by lazy { helper.getModifiers(method) }
    val javaParameters: String by lazy { helper.getJavaMethodParam(method) }
    val jniReturnType: String by lazy { helper.toJNIType(method.returnType) }
    val nativeParameters: String by lazy { helper.getNativeMethodParam(method) }
    val methodStubBody: String by lazy {
        val sb = StringBuilder()
        val a = method.getAnnotation(NativeCode::class.java)
        if (a != null) {
            for (line in a.value) {
                sb.append("    ").append(line)
            }
        } else {
            sb.append(
                """
            |    // TODO: generated method stub.
            |
        """.trimMargin()
            ).append("    ").append(helper.getReturnStatement(method))
        }
        sb.toString()
    }

    fun isStatic(): Boolean {
        return method.modifiers.contains(Modifier.STATIC)
    }

    fun getJniMethodParam(useJniHelper: Boolean): String {
        return method.parameters.joinToString(", ") { p ->
            p.asType().toJniTypeForParam(helper, useJniHelper) + " " + p.simpleName.toString()
        }
    }

    fun getJniMethodParamVal(useJniHelper: Boolean): String {
        return method.parameters.joinToString(", ") { p ->
            p.simpleName.toString() + (if (useJniHelper && p.asType().isRefType()) ".get()" else "")
        }
    }

    fun toJniTypeForReturn(useJniHelper: Boolean): String {
        return method.returnType.toJniTypeForReturn(helper, useJniHelper)
    }

    fun getReturnTypeForJniCall(): String {
        val result: String
        val k = method.returnType.kind
        result = if (k.isPrimitive || k == TypeKind.VOID) {
            k.name.lowercase(Locale.US)
        } else {
            "object"
        }
        return result.capitalize()
    }

    fun jniReturnTypeNeedCast(): Boolean {
        return when (jniReturnType) {
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
