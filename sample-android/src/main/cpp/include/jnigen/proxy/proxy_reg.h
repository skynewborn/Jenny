/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues.
 */
#pragma once

#include <jni.h>

#include "jnigen/proxy/CallbackProxy.h"
#include "jnigen/proxy/GenericProxy.h"
#include "jnigen/proxy/NativeDrawableProxy.h"
#include "jnigen/proxy/NestedClassProxy.h"
#include "jnigen/proxy/android_RectProxy.h"
#include "jnigen/proxy/android_StyleProxy.h"
#include "jnigen/proxy/java_lang_RuntimeExceptionProxy.h"
#include "jnigen/proxy/java_okhttp_BuilderProxy.h"
#include "jnigen/proxy/java_okhttp_CallProxy.h"
#include "jnigen/proxy/java_okhttp_OkHttpClientProxy.h"
#include "jnigen/proxy/java_okhttp_RequestProxy.h"
#include "jnigen/proxy/java_okhttp_ResponseBodyProxy.h"
#include "jnigen/proxy/java_okhttp_ResponseProxy.h"
#include "jnigen/proxy/jenny_GraphicsProxy.h"

namespace jenny {

inline bool initAllProxies(JNIEnv* env) {
    bool success =
        ::CallbackProxy::initClazz(env) &&
        ::GenericProxy::initClazz(env) &&
        ::NativeDrawableProxy::initClazz(env) &&
        ::NestedClassProxy::initClazz(env) &&
        android::RectProxy::initClazz(env) &&
        android::StyleProxy::initClazz(env) &&
        java::lang::RuntimeExceptionProxy::initClazz(env) &&
        java::okhttp::BuilderProxy::initClazz(env) &&
        java::okhttp::CallProxy::initClazz(env) &&
        java::okhttp::OkHttpClientProxy::initClazz(env) &&
        java::okhttp::RequestProxy::initClazz(env) &&
        java::okhttp::ResponseBodyProxy::initClazz(env) &&
        java::okhttp::ResponseProxy::initClazz(env) &&
        jenny::GraphicsProxy::initClazz(env);
    return success;
}

inline void releaseAllProxies(JNIEnv* env) {
    ::CallbackProxy::releaseClazz(env);
    ::GenericProxy::releaseClazz(env);
    ::NativeDrawableProxy::releaseClazz(env);
    ::NestedClassProxy::releaseClazz(env);
    android::RectProxy::releaseClazz(env);
    android::StyleProxy::releaseClazz(env);
    java::lang::RuntimeExceptionProxy::releaseClazz(env);
    java::okhttp::BuilderProxy::releaseClazz(env);
    java::okhttp::CallProxy::releaseClazz(env);
    java::okhttp::OkHttpClientProxy::releaseClazz(env);
    java::okhttp::RequestProxy::releaseClazz(env);
    java::okhttp::ResponseBodyProxy::releaseClazz(env);
    java::okhttp::ResponseProxy::releaseClazz(env);
    jenny::GraphicsProxy::releaseClazz(env);
}

} // end of namespace jenny
