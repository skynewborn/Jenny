#pragma once

#include <jni.h>
#include <assert.h>

#ifdef __EXCEPTIONS
#include <stdexcept>
#endif

#define CHECK_NULL(val) do {if ((val) == nullptr) return false;} while(false)

class RequestListenerProxy {
public:
    static constexpr const char *const FULL_CLASS_NAME = "com/young/jenny/RequestListener";


private:
    static jclass sClazz;


    static jmethodID sMethod_onResponse_0;


    const bool mGlobal;
    jobject mJavaObjectReference;

public:
    static bool init_clazz(JNIEnv *env) {
        if (sClazz == nullptr) {
            auto localClazz = env->FindClass(FULL_CLASS_NAME);
            CHECK_NULL(localClazz);
            sClazz = reinterpret_cast<jclass>(env->NewGlobalRef(localClazz));
            CHECK_NULL(sClazz);


            sMethod_onResponse_0 = env->GetMethodID(sClazz, "onResponse", "(ZLjava/lang/String;)V");
            CHECK_NULL(sMethod_onResponse_0);


            return true;
        }
        return true;
    }

    static void release_clazz(JNIEnv *env) {
        if (sClazz != nullptr) {
            env->DeleteGlobalRef(sClazz);
            sClazz = nullptr;
        }
    }



    ///throw std::runtime_error when construct GlobalRef failed
    RequestListenerProxy(JNIEnv *env, jobject javaObj, bool global)
#ifdef __EXCEPTIONS
    throw(std::runtime_error)
#endif
            : mGlobal(global) {
        if (init_clazz(env)) {
            mJavaObjectReference = global ? env->NewGlobalRef(javaObj) : javaObj;
        }
#ifdef __EXCEPTIONS
        if (mGlobal && mJavaObjectReference == nullptr) {
            throw std::runtime_error("cannot create global reference");
        }
#endif
    }

    bool isGlobalReferencePresent() {
        return mJavaObjectReference != nullptr;
    }

    ///no copy construct
    RequestListenerProxy(const RequestListenerProxy &from) = delete;

    void deleteGlobalReference(JNIEnv *env) {
        if (mGlobal) {
            env->DeleteGlobalRef(mJavaObjectReference);
            mJavaObjectReference = nullptr;
        }
    }

    ~RequestListenerProxy() {
        assert(!mGlobal || mJavaObjectReference == nullptr);
    }

    void onResponse(JNIEnv *env, jboolean success, jstring rsp) const {
        env->CallVoidMethod(mJavaObjectReference, sMethod_onResponse_0, success, rsp);
    }





};

//static fields
jclass RequestListenerProxy::sClazz = nullptr;
jmethodID RequestListenerProxy::sMethod_onResponse_0 = nullptr;


#undef CHECK_NULL
