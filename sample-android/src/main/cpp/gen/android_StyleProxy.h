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

namespace android {
class StyleProxy {

public:
    static constexpr auto FULL_CLASS_NAME = "android/graphics/Paint$Style";



private:
    // thread safe init
    static std::atomic_bool sInited;
    static std::mutex sInitLock;

    JNIEnv* mJniEnv;
    jobject mJavaObjectReference;

public:

    static bool initClazz(JNIEnv* env);
    
    static void releaseClazz(JNIEnv* env);

    static void assertInited(JNIEnv* env) {
        auto initClazzSuccess = initClazz(env);
        assert(initClazzSuccess);
    }

    StyleProxy(): StyleProxy(nullptr, nullptr) {}
    
    StyleProxy(JNIEnv* env, jobject javaObj)
            : mJniEnv(env), mJavaObjectReference(javaObj) {
        if (env) { assertInited(env); }
    }

    StyleProxy(const StyleProxy& from) = default;
    StyleProxy &operator=(const StyleProxy &) = default;

    StyleProxy(StyleProxy&& from) noexcept
           : mJniEnv(from.mJniEnv), mJavaObjectReference(from.mJavaObjectReference) {
        from.mJavaObjectReference = nullptr;
    }
    
    StyleProxy& operator=(StyleProxy&& from) noexcept {
       mJniEnv = from.mJniEnv;
       std::swap(mJavaObjectReference, from.mJavaObjectReference);
       return *this;
   }

    ~StyleProxy() = default;
    
    // helper method to get underlay jobject reference
    jobject operator*() const {
       return mJavaObjectReference;
    }
    
    // helper method to check underlay jobject reference is not nullptr
    operator bool() const {
       return mJavaObjectReference;
    }
    
    // helper method to delete JNI local ref.
    // use only when you really understand JNIEnv::DeleteLocalRef.
    void deleteLocalRef() {
       if (mJavaObjectReference) {
           mJniEnv->DeleteLocalRef(mJavaObjectReference);
           mJavaObjectReference = nullptr;
       }
    }
    
    // === java methods below ===
    

    // method: public static android.graphics.Paint.Style[] values()
    static jobjectArray values(JNIEnv* env) {
        assertInited(env);
        return reinterpret_cast<jobjectArray>(env->CallStaticObjectMethod(sClazz, sMethod_values_0));
    }

    // method: public static android.graphics.Paint.Style valueOf(java.lang.String name)
    static jobject valueOf(JNIEnv* env, jstring name) {
        assertInited(env);
        return env->CallStaticObjectMethod(sClazz, sMethod_valueOf_0, name);
    }


    // field: public static final android.graphics.Paint.Style FILL
    static jobject getFILL(JNIEnv* env) {
       assertInited(env);
       return env->GetStaticObjectField(sClazz, sField_FILL_0);

    }

    // field: public static final android.graphics.Paint.Style FILL
    static void setFILL(JNIEnv* env, jobject FILL) {
        assertInited(env);
        env->SetStaticObjectField(sClazz, sField_FILL_0, FILL);
    }


    // field: public static final android.graphics.Paint.Style STROKE
    static jobject getSTROKE(JNIEnv* env) {
       assertInited(env);
       return env->GetStaticObjectField(sClazz, sField_STROKE_1);

    }

    // field: public static final android.graphics.Paint.Style STROKE
    static void setSTROKE(JNIEnv* env, jobject STROKE) {
        assertInited(env);
        env->SetStaticObjectField(sClazz, sField_STROKE_1, STROKE);
    }


    // field: public static final android.graphics.Paint.Style FILL_AND_STROKE
    static jobject getFILL_AND_STROKE(JNIEnv* env) {
       assertInited(env);
       return env->GetStaticObjectField(sClazz, sField_FILL_AND_STROKE_2);

    }

    // field: public static final android.graphics.Paint.Style FILL_AND_STROKE
    static void setFILL_AND_STROKE(JNIEnv* env, jobject FILL_AND_STROKE) {
        assertInited(env);
        env->SetStaticObjectField(sClazz, sField_FILL_AND_STROKE_2, FILL_AND_STROKE);
    }



private:
    static jclass sClazz;

    static jmethodID sMethod_values_0;
    static jmethodID sMethod_valueOf_0;

    static jfieldID sField_FILL_0;
    static jfieldID sField_STROKE_1;
    static jfieldID sField_FILL_AND_STROKE_2;

};
} // endof namespace android
