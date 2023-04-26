package io.github.landerlyoung.jenny.extensions

import io.github.landerlyoung.jenny.HandyHelper
import javax.lang.model.type.NoType
import javax.lang.model.type.TypeMirror

// need wrap LocalRef for jni helper or not
fun TypeMirror.isRefType(): Boolean {
    return !this.kind.isPrimitive && this !is NoType
}

fun TypeMirror.toJniTypeForParam(helper: HandyHelper, useJniHelper: Boolean): String {
    val jniType = helper.toJNIType(this)
    return if (useJniHelper && isRefType()) {
        "const ::jenny::LocalRef<$jniType>&"
    } else {
        jniType
    }
}

fun TypeMirror.toJniTypeForReturn(helper: HandyHelper, useJniHelper: Boolean): String {
    val jniType = helper.toJNIType(this)
    return if (useJniHelper && isRefType()) {
        "::jenny::LocalRef<$jniType>"
    } else {
        jniType
    }
}

