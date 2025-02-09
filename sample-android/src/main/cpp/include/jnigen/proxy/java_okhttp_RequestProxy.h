/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues.
 */
#pragma once

#include <jni.h>
#include <assert.h>
#include <atomic>
#include <mutex>

#include "jnigen/jni_helper.h"

// external logger function
void jennySampleErrorLog(JNIEnv* env, const char* error);


namespace java {
namespace okhttp {
class RequestProxy {

public:
    static constexpr auto FULL_CLASS_NAME = u8"okhttp3/Request";


public:
    static bool initClazz(JNIEnv* env);

    static void releaseClazz(JNIEnv* env);

    static void assertInited(JNIEnv* env) {
        auto initClazzSuccess = initClazz(env);
        assert(initClazzSuccess);
    }


    // method: public okhttp3.HttpUrl url()
    static jobject url(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_url_0);
    }

    // method: public java.lang.String method()
    static jstring method(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return reinterpret_cast<jstring>(env->CallObjectMethod(thiz, getClassInitState().sMethod_method_0));
    }

    // method: public okhttp3.Headers headers()
    static jobject headers(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_headers_0);
    }

    // method: public java.util.List<java.lang.String> headers(java.lang.String name)
    static jobject headers(JNIEnv* env, jobject thiz, jstring name) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_headers_1, name);
    }

    // method: public java.lang.String header(java.lang.String name)
    static jstring header(JNIEnv* env, jobject thiz, jstring name) {
        assertInited(env);
        return reinterpret_cast<jstring>(env->CallObjectMethod(thiz, getClassInitState().sMethod_header_0, name));
    }

    // method: public okhttp3.RequestBody body()
    static jobject body(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_body_0);
    }

    // method: public java.lang.Object tag()
    static jobject tag(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_tag_0);
    }

    // method: public T tag(java.lang.Class<? extends T> type)
    static jobject tag(JNIEnv* env, jobject thiz, jclass type) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_tag_1, type);
    }

    // method: public okhttp3.Request.Builder newBuilder()
    static jobject newBuilder(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_newBuilder_0);
    }

    // method: public okhttp3.CacheControl cacheControl()
    static jobject cacheControl(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_cacheControl_0);
    }

    // method: public boolean isHttps()
    static jboolean isHttps(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallBooleanMethod(thiz, getClassInitState().sMethod_isHttps_0);
    }

    // method: public java.lang.String toString()
    static jstring toString(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return reinterpret_cast<jstring>(env->CallObjectMethod(thiz, getClassInitState().sMethod_toString_0));
    }



private:
    ::jenny::LocalRef<jobject> _local;
    ::jenny::GlobalRef<jobject> _global;

public:
    ::jenny::LocalRef<jobject> getThis(bool owned = true) const {
        if (_local) {
            if (owned) {
                return _local;
            } else {
                return ::jenny::LocalRef<jobject>(_local.get(), false);
            }
        } else {
            return _global.toLocal();
        }
    }

    // jni helper constructors
    RequestProxy(jobject ref, bool owned = false): _local(ref, owned) {
       assertInited(::jenny::Env().get());
    }

    RequestProxy(::jenny::LocalRef<jobject> ref): _local(std::move(ref)) {
       assertInited(::jenny::Env().get());
    }

    RequestProxy(::jenny::GlobalRef<jobject> ref): _global(std::move(ref)) {
       assertInited(::jenny::Env().get());
    }


    // method: public okhttp3.HttpUrl url()
    ::jenny::LocalRef<jobject> url() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_url_0));
    }

    // method: public java.lang.String method()
    ::jenny::LocalRef<jstring> method() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jstring>(reinterpret_cast<jstring>(env->CallObjectMethod(thiz, getClassInitState().sMethod_method_0)));
    }

    // method: public okhttp3.Headers headers()
    ::jenny::LocalRef<jobject> headers() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_headers_0));
    }

    // method: public java.util.List<java.lang.String> headers(java.lang.String name)
    ::jenny::LocalRef<jobject> headers(const ::jenny::LocalRef<jstring>& name) const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_headers_1, name.get()));
    }

    // method: public java.lang.String header(java.lang.String name)
    ::jenny::LocalRef<jstring> header(const ::jenny::LocalRef<jstring>& name) const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jstring>(reinterpret_cast<jstring>(env->CallObjectMethod(thiz, getClassInitState().sMethod_header_0, name.get())));
    }

    // method: public okhttp3.RequestBody body()
    ::jenny::LocalRef<jobject> body() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_body_0));
    }

    // method: public java.lang.Object tag()
    ::jenny::LocalRef<jobject> tag() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_tag_0));
    }

    // method: public T tag(java.lang.Class<? extends T> type)
    ::jenny::LocalRef<jobject> tag(const ::jenny::LocalRef<jclass>& type) const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_tag_1, type.get()));
    }

    // method: public okhttp3.Request.Builder newBuilder()
    ::jenny::LocalRef<jobject> newBuilder() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_newBuilder_0));
    }

    // method: public okhttp3.CacheControl cacheControl()
    ::jenny::LocalRef<jobject> cacheControl() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_cacheControl_0));
    }

    // method: public boolean isHttps()
    jboolean isHttps() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return env->CallBooleanMethod(thiz, getClassInitState().sMethod_isHttps_0);
    }

    // method: public java.lang.String toString()
    ::jenny::LocalRef<jstring> toString() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jstring>(reinterpret_cast<jstring>(env->CallObjectMethod(thiz, getClassInitState().sMethod_toString_0)));
    }



private:
    struct ClassInitState {
        // thread safe init
        std::atomic_bool sInited {};
        std::mutex sInitLock {};
        jclass sClazz = nullptr;


        jmethodID sMethod_url_0 = nullptr;
        jmethodID sMethod_method_0 = nullptr;
        jmethodID sMethod_headers_0 = nullptr;
        jmethodID sMethod_headers_1 = nullptr;
        jmethodID sMethod_header_0 = nullptr;
        jmethodID sMethod_body_0 = nullptr;
        jmethodID sMethod_tag_0 = nullptr;
        jmethodID sMethod_tag_1 = nullptr;
        jmethodID sMethod_newBuilder_0 = nullptr;
        jmethodID sMethod_cacheControl_0 = nullptr;
        jmethodID sMethod_isHttps_0 = nullptr;
        jmethodID sMethod_toString_0 = nullptr;

    }; // endof struct ClassInitState

    static inline ClassInitState& getClassInitState() {
        static ClassInitState classInitState;
        return classInitState;
    }

};


/*static*/ inline bool RequestProxy::initClazz(JNIEnv* env) {
#define JENNY_CHECK_NULL(val)                      \
       do {                                        \
           if ((val) == nullptr) {                 \
               jennySampleErrorLog(env, "can't init RequestProxy::" #val); \
               return false;                       \
           }                                       \
       } while(false)

    auto& state = getClassInitState();
    if (!state.sInited) {
        std::lock_guard<std::mutex> lg(state.sInitLock);
        if (!state.sInited) {
            auto clazz = env->FindClass(FULL_CLASS_NAME);
            JENNY_CHECK_NULL(clazz);
            state.sClazz = reinterpret_cast<jclass>(env->NewGlobalRef(clazz));
            env->DeleteLocalRef(clazz);
            JENNY_CHECK_NULL(state.sClazz);


            state.sMethod_url_0 = env->GetMethodID(state.sClazz, "url", "()Lokhttp3/HttpUrl;");
            JENNY_CHECK_NULL(state.sMethod_url_0);
            state.sMethod_method_0 = env->GetMethodID(state.sClazz, "method", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_method_0);
            state.sMethod_headers_0 = env->GetMethodID(state.sClazz, "headers", "()Lokhttp3/Headers;");
            JENNY_CHECK_NULL(state.sMethod_headers_0);
            state.sMethod_headers_1 = env->GetMethodID(state.sClazz, "headers", "(Ljava/lang/String;)Ljava/util/List;");
            JENNY_CHECK_NULL(state.sMethod_headers_1);
            state.sMethod_header_0 = env->GetMethodID(state.sClazz, "header", "(Ljava/lang/String;)Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_header_0);
            state.sMethod_body_0 = env->GetMethodID(state.sClazz, "body", "()Lokhttp3/RequestBody;");
            JENNY_CHECK_NULL(state.sMethod_body_0);
            state.sMethod_tag_0 = env->GetMethodID(state.sClazz, "tag", "()Ljava/lang/Object;");
            JENNY_CHECK_NULL(state.sMethod_tag_0);
            state.sMethod_tag_1 = env->GetMethodID(state.sClazz, "tag", "(Ljava/lang/Class;)Ljava/lang/Object;");
            JENNY_CHECK_NULL(state.sMethod_tag_1);
            state.sMethod_newBuilder_0 = env->GetMethodID(state.sClazz, "newBuilder", "()Lokhttp3/Request$Builder;");
            JENNY_CHECK_NULL(state.sMethod_newBuilder_0);
            state.sMethod_cacheControl_0 = env->GetMethodID(state.sClazz, "cacheControl", "()Lokhttp3/CacheControl;");
            JENNY_CHECK_NULL(state.sMethod_cacheControl_0);
            state.sMethod_isHttps_0 = env->GetMethodID(state.sClazz, "isHttps", "()Z");
            JENNY_CHECK_NULL(state.sMethod_isHttps_0);
            state.sMethod_toString_0 = env->GetMethodID(state.sClazz, "toString", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_toString_0);


            state.sInited = true;
        }
    }
#undef JENNY_CHECK_NULL
   return true;
}

/*static*/ inline void RequestProxy::releaseClazz(JNIEnv* env) {
    auto& state = getClassInitState();
    if (state.sInited) {
        std::lock_guard<std::mutex> lg(state.sInitLock);
        if (state.sInited) {
            env->DeleteGlobalRef(state.sClazz);
            state.sClazz = nullptr;
            state.sInited = false;
        }
    }
}


} // end of namespace java
} // end of namespace okhttp
