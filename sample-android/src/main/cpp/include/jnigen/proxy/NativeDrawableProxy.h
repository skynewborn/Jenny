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


class NativeDrawableProxy {

public:
    static constexpr auto FULL_CLASS_NAME = u8"io/github/landerlyoung/jennysampleapp/NativeDrawable";


public:
    static bool initClazz(JNIEnv* env);

    static void releaseClazz(JNIEnv* env);

    static void assertInited(JNIEnv* env) {
        auto initClazzSuccess = initClazz(env);
        assert(initClazzSuccess);
    }



    // field: private final long nativeHandle
    static jlong getNativeHandle(JNIEnv* env, jobject thiz) {
        assertInited(env);
        return env->GetLongField(thiz, getClassInitState().sField_nativeHandle_0);
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
    NativeDrawableProxy(jobject ref, bool owned = false): _local(ref, owned) {
       assertInited(::jenny::Env().get());
    }

    NativeDrawableProxy(::jenny::LocalRef<jobject> ref): _local(std::move(ref)) {
       assertInited(::jenny::Env().get());
    }

    NativeDrawableProxy(::jenny::GlobalRef<jobject> ref): _global(std::move(ref)) {
       assertInited(::jenny::Env().get());
    }



    // field: private final long nativeHandle
    jlong getNativeHandle() const {
        ::jenny::Env env;
        ::jenny::LocalRef<jobject> jennyLocalRef = getThis(false);
        jobject thiz = jennyLocalRef.get();
        return env->GetLongField(thiz, getClassInitState().sField_nativeHandle_0);
    }



private:
    struct ClassInitState {
        // thread safe init
        std::atomic_bool sInited {};
        std::mutex sInitLock {};
        jclass sClazz = nullptr;



        jfieldID sField_nativeHandle_0 = nullptr;
    }; // endof struct ClassInitState

    static inline ClassInitState& getClassInitState() {
        static ClassInitState classInitState;
        return classInitState;
    }

};


/*static*/ inline bool NativeDrawableProxy::initClazz(JNIEnv* env) {
#define JENNY_CHECK_NULL(val)                      \
       do {                                        \
           if ((val) == nullptr) {                 \
               jennySampleErrorLog(env, "can't init NativeDrawableProxy::" #val); \
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



            state.sField_nativeHandle_0 = env->GetFieldID(state.sClazz, "nativeHandle", "J");
            JENNY_CHECK_NULL(state.sField_nativeHandle_0);

            state.sInited = true;
        }
    }
#undef JENNY_CHECK_NULL
   return true;
}

/*static*/ inline void NativeDrawableProxy::releaseClazz(JNIEnv* env) {
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


