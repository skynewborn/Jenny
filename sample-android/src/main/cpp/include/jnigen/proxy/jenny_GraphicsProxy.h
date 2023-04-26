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


namespace jenny {
class GraphicsProxy {

public:
    static constexpr auto FULL_CLASS_NAME = u8"io/github/landerlyoung/jennysampleapp/Graphics";


public:
    static bool initClazz(JNIEnv* env);

    static void releaseClazz(JNIEnv* env);

    static void assertInited(JNIEnv* env) {
        auto initClazzSuccess = initClazz(env);
        assert(initClazzSuccess);
    }

    // construct: private Graphics()
    static jobject newInstance(JNIEnv* env) {
        assertInited(env);
        return env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_0);
    }

    // method: public static final android.graphics.Paint newPaint()
    static jobject newPaint(JNIEnv* env) {
        assertInited(env);
        return env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_newPaint_0);
    }

    // method: public static final void paintSetStyle(android.graphics.Paint paint, android.graphics.Paint.Style style)
    static void paintSetStyle(JNIEnv* env, jobject paint, jobject style) {
        assertInited(env);
        env->CallStaticVoidMethod(getClassInitState().sClazz, getClassInitState().sMethod_paintSetStyle_0, paint, style);
    }

    // method: public static final void drawableCircle(android.graphics.Canvas canvas, float x, float y, float r, android.graphics.Paint paint)
    static void drawableCircle(JNIEnv* env, jobject canvas, jfloat x, jfloat y, jfloat r, jobject paint) {
        assertInited(env);
        env->CallStaticVoidMethod(getClassInitState().sClazz, getClassInitState().sMethod_drawableCircle_0, canvas, x, y, r, paint);
    }

    // method: public static final android.graphics.Rect drawableGetBounds(android.graphics.drawable.Drawable drawable)
    static jobject drawableGetBounds(JNIEnv* env, jobject drawable) {
        assertInited(env);
        return env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_drawableGetBounds_0, drawable);
    }

    // method: public static final void setColor(android.graphics.Paint paint, int color)
    static void setColor(JNIEnv* env, jobject paint, jint color) {
        assertInited(env);
        env->CallStaticVoidMethod(getClassInitState().sClazz, getClassInitState().sMethod_setColor_0, paint, color);
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
    GraphicsProxy(jobject ref, bool owned = false): _local(ref, owned) {
       assertInited(::jenny::Env().get());
    }

    GraphicsProxy(::jenny::LocalRef<jobject> ref): _local(std::move(ref)) {
       assertInited(::jenny::Env().get());
    }

    GraphicsProxy(::jenny::GlobalRef<jobject> ref): _global(std::move(ref)) {
       assertInited(::jenny::Env().get());
    }

    // construct: private Graphics()
    static GraphicsProxy newInstance() {
        ::jenny::Env env;
        assertInited(env.get());
        return env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_0);
    }

    // method: public static final android.graphics.Paint newPaint()
    static ::jenny::LocalRef<jobject> newPaint() {
        ::jenny::Env env;
        assertInited(env.get());
        return ::jenny::LocalRef<jobject>(env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_newPaint_0));
    }

    // method: public static final void paintSetStyle(android.graphics.Paint paint, android.graphics.Paint.Style style)
    static void paintSetStyle(const ::jenny::LocalRef<jobject>& paint, const ::jenny::LocalRef<jobject>& style) {
        ::jenny::Env env;
        assertInited(env.get());
        env->CallStaticVoidMethod(getClassInitState().sClazz, getClassInitState().sMethod_paintSetStyle_0, paint.get(), style.get());
    }

    // method: public static final void drawableCircle(android.graphics.Canvas canvas, float x, float y, float r, android.graphics.Paint paint)
    static void drawableCircle(const ::jenny::LocalRef<jobject>& canvas, jfloat x, jfloat y, jfloat r, const ::jenny::LocalRef<jobject>& paint) {
        ::jenny::Env env;
        assertInited(env.get());
        env->CallStaticVoidMethod(getClassInitState().sClazz, getClassInitState().sMethod_drawableCircle_0, canvas.get(), x, y, r, paint.get());
    }

    // method: public static final android.graphics.Rect drawableGetBounds(android.graphics.drawable.Drawable drawable)
    static ::jenny::LocalRef<jobject> drawableGetBounds(const ::jenny::LocalRef<jobject>& drawable) {
        ::jenny::Env env;
        assertInited(env.get());
        return ::jenny::LocalRef<jobject>(env->CallStaticObjectMethod(getClassInitState().sClazz, getClassInitState().sMethod_drawableGetBounds_0, drawable.get()));
    }

    // method: public static final void setColor(android.graphics.Paint paint, int color)
    static void setColor(const ::jenny::LocalRef<jobject>& paint, jint color) {
        ::jenny::Env env;
        assertInited(env.get());
        env->CallStaticVoidMethod(getClassInitState().sClazz, getClassInitState().sMethod_setColor_0, paint.get(), color);
    }



private:
    struct ClassInitState {
        // thread safe init
        std::atomic_bool sInited {};
        std::mutex sInitLock {};
        jclass sClazz = nullptr;

        jmethodID sConstruct_0 = nullptr;

        jmethodID sMethod_newPaint_0 = nullptr;
        jmethodID sMethod_paintSetStyle_0 = nullptr;
        jmethodID sMethod_drawableCircle_0 = nullptr;
        jmethodID sMethod_drawableGetBounds_0 = nullptr;
        jmethodID sMethod_setColor_0 = nullptr;

    }; // endof struct ClassInitState

    static inline ClassInitState& getClassInitState() {
        static ClassInitState classInitState;
        return classInitState;
    }

};


/*static*/ inline bool GraphicsProxy::initClazz(JNIEnv* env) {
#define JENNY_CHECK_NULL(val)                      \
       do {                                        \
           if ((val) == nullptr) {                 \
               jennySampleErrorLog(env, "can't init GraphicsProxy::" #val); \
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

            state.sMethod_newPaint_0 = env->GetStaticMethodID(state.sClazz, "newPaint", "()Landroid/graphics/Paint;");
            JENNY_CHECK_NULL(state.sMethod_newPaint_0);
            state.sMethod_paintSetStyle_0 = env->GetStaticMethodID(state.sClazz, "paintSetStyle", "(Landroid/graphics/Paint;Landroid/graphics/Paint$Style;)V");
            JENNY_CHECK_NULL(state.sMethod_paintSetStyle_0);
            state.sMethod_drawableCircle_0 = env->GetStaticMethodID(state.sClazz, "drawableCircle", "(Landroid/graphics/Canvas;FFFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(state.sMethod_drawableCircle_0);
            state.sMethod_drawableGetBounds_0 = env->GetStaticMethodID(state.sClazz, "drawableGetBounds", "(Landroid/graphics/drawable/Drawable;)Landroid/graphics/Rect;");
            JENNY_CHECK_NULL(state.sMethod_drawableGetBounds_0);
            state.sMethod_setColor_0 = env->GetStaticMethodID(state.sClazz, "setColor", "(Landroid/graphics/Paint;I)V");
            JENNY_CHECK_NULL(state.sMethod_setColor_0);


            state.sInited = true;
        }
    }
#undef JENNY_CHECK_NULL
   return true;
}

/*static*/ inline void GraphicsProxy::releaseClazz(JNIEnv* env) {
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


} // end of namespace jenny
