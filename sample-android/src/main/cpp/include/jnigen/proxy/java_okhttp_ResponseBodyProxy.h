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
class ResponseBodyProxy {

public:
    static constexpr auto FULL_CLASS_NAME = u8"okhttp3/ResponseBody";


public:
    static bool initClazz(JNIEnv* env);

    static void releaseClazz(JNIEnv* env);

    static void assertInited(JNIEnv* env) {
        auto initClazzSuccess = initClazz(env);
        assert(initClazzSuccess);
    }

    // construct: public ResponseBody()
    static jobject newInstance(JNIEnv* env) {
        assertInited(env);
        return env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_0);
    }

    // method: public abstract okhttp3.MediaType contentType()
    static jobject contentType(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_contentType_0);
    }

    // method: public abstract long contentLength()
    static jlong contentLength(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallLongMethod(thiz, getClassInitState().sMethod_contentLength_0);
    }

    // method: public final java.io.InputStream byteStream()
    static jobject byteStream(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_byteStream_0);
    }

    // method: public abstract okio.BufferedSource source()
    static jobject source(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_source_0);
    }

    // method: public final byte[] bytes()
    static jbyteArray bytes(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return reinterpret_cast<jbyteArray>(env->CallObjectMethod(thiz, getClassInitState().sMethod_bytes_0));
    }

    // method: public final java.io.Reader charStream()
    static jobject charStream(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->CallObjectMethod(thiz, getClassInitState().sMethod_charStream_0);
    }

    // method: public final java.lang.String string()
    static jstring string(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return reinterpret_cast<jstring>(env->CallObjectMethod(thiz, getClassInitState().sMethod_string_0));
    }

    // method: public void close()
    static void close(JNIEnv* env, jobject thiz) {
        assertInited(env);
        env->CallVoidMethod(thiz, getClassInitState().sMethod_close_0);
    }

    // method: public static okhttp3.ResponseBody create(okhttp3.MediaType contentType, java.lang.String content)
    static jobject create(JNIEnv* env, jobject contentType, jstring content) {
        assertInited(env);
        return env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_create_0, contentType, content);
    }

    // method: public static okhttp3.ResponseBody create(okhttp3.MediaType contentType, byte[] content)
    static jobject create(JNIEnv* env, jobject contentType, jbyteArray content) {
        assertInited(env);
        return env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_create_1, contentType, content);
    }

    // method: public static okhttp3.ResponseBody create(okhttp3.MediaType contentType, okio.ByteString content)
    static jobject create(JNIEnv* env, jobject contentType, jobject content) {
        assertInited(env);
        return env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_create_2, contentType, content);
    }

    // method: public static okhttp3.ResponseBody create(okhttp3.MediaType contentType, long contentLength, okio.BufferedSource content)
    static jobject create(JNIEnv* env, jobject contentType, jlong contentLength, jobject content) {
        assertInited(env);
        return env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_create_3, contentType, contentLength, content);
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
    ResponseBodyProxy(jobject ref, bool owned = false): _local(ref, owned) {
       assertInited(::jenny::Env().get());
    }

    ResponseBodyProxy(::jenny::LocalRef<jobject> ref): _local(std::move(ref)) {
       assertInited(::jenny::Env().get());
    }

    ResponseBodyProxy(::jenny::GlobalRef<jobject> ref): _global(std::move(ref)) {
       assertInited(::jenny::Env().get());
    }

    // construct: public ResponseBody()
    static ResponseBodyProxy newInstance() {
        ::jenny::Env env;
        assertInited(env.get());
        return env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_0);
    }

    // method: public abstract okhttp3.MediaType contentType()
    ::jenny::LocalRef<jobject> contentType() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_contentType_0));
    }

    // method: public abstract long contentLength()
    jlong contentLength() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return env->CallLongMethod(thiz, getClassInitState().sMethod_contentLength_0);
    }

    // method: public final java.io.InputStream byteStream()
    ::jenny::LocalRef<jobject> byteStream() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_byteStream_0));
    }

    // method: public abstract okio.BufferedSource source()
    ::jenny::LocalRef<jobject> source() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_source_0));
    }

    // method: public final byte[] bytes()
    ::jenny::LocalRef<jbyteArray> bytes() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jbyteArray>(reinterpret_cast<jbyteArray>(env->CallObjectMethod(thiz, getClassInitState().sMethod_bytes_0)));
    }

    // method: public final java.io.Reader charStream()
    ::jenny::LocalRef<jobject> charStream() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jobject>(env->CallObjectMethod(thiz, getClassInitState().sMethod_charStream_0));
    }

    // method: public final java.lang.String string()
    ::jenny::LocalRef<jstring> string() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return ::jenny::LocalRef<jstring>(reinterpret_cast<jstring>(env->CallObjectMethod(thiz, getClassInitState().sMethod_string_0)));
    }

    // method: public void close()
    void close() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        env->CallVoidMethod(thiz, getClassInitState().sMethod_close_0);
    }

    // method: public static okhttp3.ResponseBody create(okhttp3.MediaType contentType, java.lang.String content)
    static ::jenny::LocalRef<jobject> create(const ::jenny::LocalRef<jobject>& contentType, const ::jenny::LocalRef<jstring>& content) {
        ::jenny::Env env;
        assertInited(env.get());
        return ::jenny::LocalRef<jobject>(env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_create_0, contentType.get(), content.get()));
    }

    // method: public static okhttp3.ResponseBody create(okhttp3.MediaType contentType, byte[] content)
    static ::jenny::LocalRef<jobject> create(const ::jenny::LocalRef<jobject>& contentType, const ::jenny::LocalRef<jbyteArray>& content) {
        ::jenny::Env env;
        assertInited(env.get());
        return ::jenny::LocalRef<jobject>(env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_create_1, contentType.get(), content.get()));
    }

    // method: public static okhttp3.ResponseBody create(okhttp3.MediaType contentType, okio.ByteString content)
    static ::jenny::LocalRef<jobject> create(const ::jenny::LocalRef<jobject>& contentType, const ::jenny::LocalRef<jobject>& content) {
        ::jenny::Env env;
        assertInited(env.get());
        return ::jenny::LocalRef<jobject>(env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_create_2, contentType.get(), content.get()));
    }

    // method: public static okhttp3.ResponseBody create(okhttp3.MediaType contentType, long contentLength, okio.BufferedSource content)
    static ::jenny::LocalRef<jobject> create(const ::jenny::LocalRef<jobject>& contentType, jlong contentLength, const ::jenny::LocalRef<jobject>& content) {
        ::jenny::Env env;
        assertInited(env.get());
        return ::jenny::LocalRef<jobject>(env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_create_3, contentType.get(), contentLength, content.get()));
    }



private:
    struct ClassInitState {
        // thread safe init
        std::atomic_bool sInited {};
        std::mutex sInitLock {};
        jclass sClazz = nullptr;

        jmethodID sConstruct_0 = nullptr;

        jmethodID sMethod_contentType_0 = nullptr;
        jmethodID sMethod_contentLength_0 = nullptr;
        jmethodID sMethod_byteStream_0 = nullptr;
        jmethodID sMethod_source_0 = nullptr;
        jmethodID sMethod_bytes_0 = nullptr;
        jmethodID sMethod_charStream_0 = nullptr;
        jmethodID sMethod_string_0 = nullptr;
        jmethodID sMethod_close_0 = nullptr;
        jmethodID sMethod_create_0 = nullptr;
        jmethodID sMethod_create_1 = nullptr;
        jmethodID sMethod_create_2 = nullptr;
        jmethodID sMethod_create_3 = nullptr;

    }; // endof struct ClassInitState

    static inline ClassInitState& getClassInitState() {
        static ClassInitState classInitState;
        return classInitState;
    }

};


/*static*/ inline bool ResponseBodyProxy::initClazz(JNIEnv* env) {
#define JENNY_CHECK_NULL(val)                      \
       do {                                        \
           if ((val) == nullptr) {                 \
               jennySampleErrorLog(env, "can't init ResponseBodyProxy::" #val); \
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

            state.sConstruct_0 = env->GetMethodID(state.sClazz, "<init>", "()V");
            JENNY_CHECK_NULL(state.sConstruct_0);

            state.sMethod_contentType_0 = env->GetMethodID(state.sClazz, "contentType", "()Lokhttp3/MediaType;");
            JENNY_CHECK_NULL(state.sMethod_contentType_0);
            state.sMethod_contentLength_0 = env->GetMethodID(state.sClazz, "contentLength", "()J");
            JENNY_CHECK_NULL(state.sMethod_contentLength_0);
            state.sMethod_byteStream_0 = env->GetMethodID(state.sClazz, "byteStream", "()Ljava/io/InputStream;");
            JENNY_CHECK_NULL(state.sMethod_byteStream_0);
            state.sMethod_source_0 = env->GetMethodID(state.sClazz, "source", "()Lokio/BufferedSource;");
            JENNY_CHECK_NULL(state.sMethod_source_0);
            state.sMethod_bytes_0 = env->GetMethodID(state.sClazz, "bytes", "()[B");
            JENNY_CHECK_NULL(state.sMethod_bytes_0);
            state.sMethod_charStream_0 = env->GetMethodID(state.sClazz, "charStream", "()Ljava/io/Reader;");
            JENNY_CHECK_NULL(state.sMethod_charStream_0);
            state.sMethod_string_0 = env->GetMethodID(state.sClazz, "string", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_string_0);
            state.sMethod_close_0 = env->GetMethodID(state.sClazz, "close", "()V");
            JENNY_CHECK_NULL(state.sMethod_close_0);
            state.sMethod_create_0 = env->GetStaticMethodID(state.sClazz, "create", "(Lokhttp3/MediaType;Ljava/lang/String;)Lokhttp3/ResponseBody;");
            JENNY_CHECK_NULL(state.sMethod_create_0);
            state.sMethod_create_1 = env->GetStaticMethodID(state.sClazz, "create", "(Lokhttp3/MediaType;[B)Lokhttp3/ResponseBody;");
            JENNY_CHECK_NULL(state.sMethod_create_1);
            state.sMethod_create_2 = env->GetStaticMethodID(state.sClazz, "create", "(Lokhttp3/MediaType;Lokio/ByteString;)Lokhttp3/ResponseBody;");
            JENNY_CHECK_NULL(state.sMethod_create_2);
            state.sMethod_create_3 = env->GetStaticMethodID(state.sClazz, "create", "(Lokhttp3/MediaType;JLokio/BufferedSource;)Lokhttp3/ResponseBody;");
            JENNY_CHECK_NULL(state.sMethod_create_3);


            state.sInited = true;
        }
    }
#undef JENNY_CHECK_NULL
   return true;
}

/*static*/ inline void ResponseBodyProxy::releaseClazz(JNIEnv* env) {
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
