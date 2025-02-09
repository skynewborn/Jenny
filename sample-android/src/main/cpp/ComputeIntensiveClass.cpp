/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues.
 */
#include "jnigen/jni/ComputeIntensiveClass.h"
#include "jnigen/proxy/CallbackProxy.h"
#include "jnigen/proxy/NestedClassProxy.h"
#include "jnigen/proxy/java_okhttp_OkHttpClientProxy.h"
#include "jnigen/proxy/java_okhttp_BuilderProxy.h"
#include "jnigen/proxy/java_okhttp_RequestProxy.h"
#include "jnigen/proxy/java_okhttp_CallProxy.h"
#include "jnigen/proxy/java_okhttp_ResponseProxy.h"
#include "jnigen/proxy/java_okhttp_ResponseBodyProxy.h"

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public int addInNative(int a, int b)
 * Signature: (II)I
 */
jint ComputeIntensiveClass::addInNative(JNIEnv* env, jobject thiz, jint a, jint b) {
    jint c = a + b;    return c;
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public static void computeSomething(byte[] sth)
 * Signature: ([B)V
 */
void ComputeIntensiveClass::computeSomething(JNIEnv* env, jclass clazz, jbyteArray sth) {
    // TODO: generated method stub.
    
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public static java.lang.String greet()
 * Signature: ()Ljava/lang/String;
 */
jstring ComputeIntensiveClass::greet(JNIEnv* env, jclass clazz) {
    // TODO: generated method stub.
    return env->NewStringUTF("Hello From Jenny");
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public final void testParamParse(int a, java.lang.String b, long[] c, float[][] d, java.lang.Exception e, java.lang.Class<java.lang.String> f, java.util.HashMap<?,?> g)
 * Signature: (ILjava/lang/String;[J[[FLjava/lang/Exception;Ljava/lang/Class;Ljava/util/HashMap;)V
 */
void ComputeIntensiveClass::testParamParse(JNIEnv* env, jobject thiz, jint a, jstring b, jlongArray c, jobjectArray d, jthrowable e, jclass f, jobject g) {
    // TODO: generated method stub.
    
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public static long returnsLong()
 * Signature: ()J
 */
jlong ComputeIntensiveClass::returnsLong(JNIEnv* env, jclass clazz) {
    // TODO: generated method stub.
    return 0;
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public static boolean returnsBool()
 * Signature: ()Z
 */
jboolean ComputeIntensiveClass::returnsBool(JNIEnv* env, jclass clazz) {
    // TODO: generated method stub.
    return JNI_FALSE;
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public static java.lang.Object returnsObject()
 * Signature: ()Ljava/lang/Object;
 */
jobject ComputeIntensiveClass::returnsObject(JNIEnv* env, jclass clazz) {
    // TODO: generated method stub.
    return nullptr;
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public static void testOverload()
 * Signature: ()V
 */
void ComputeIntensiveClass::testOverload__(JNIEnv* env, jclass clazz) {
    // TODO: generated method stub.
    
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public static void testOverload(int i)
 * Signature: (I)V
 */
void ComputeIntensiveClass::testOverload__I(JNIEnv* env, jclass clazz, jint i) {
    // TODO: generated method stub.
    
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public static java.lang.String httpGet(java.lang.String url)
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
jstring ComputeIntensiveClass::httpGet(JNIEnv* env, jclass clazz, jstring url) {
#define __                          \
    if (env->ExceptionCheck()) {    \
        env->ExceptionClear();      \
        return nullptr;             \
    }

    using namespace java::okhttp;
    jenny::LocalRef<jstring> _url(url, false);

    OkHttpClientProxy client = OkHttpClientProxy::newInstance(); __
    BuilderProxy builder = BuilderProxy::newInstance().url(_url); __
    RequestProxy request = builder.build(); __
    CallProxy call = client.newCall(request.getThis()); __
    ResponseProxy response = call.execute(); __
    ResponseBodyProxy body = response.body(); __
    return body.string().release();

#undef __


    /*
     * equivalent java code to {@link ComputeIntensiveClass#httpGet(String)}

        String run(String url) throws IOException {
         OkHttpClient client = new OkHttpClient();
          Request request = new Request.Builder()
              .url(url)
              .build();

          Response response = client.newCall(request).execute();
          return response.body().string();
        }

     */
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public int computeThenCallback(io.github.landerlyoung.jennysampleapp.Callback listener)
 * Signature: (Lio/github/landerlyoung/jennysampleapp/Callback;)I
 */
jint ComputeIntensiveClass::computeThenCallback(JNIEnv* env, jobject thiz, jobject listener) {
    CallbackProxy::onJobStart(env, listener);

    auto name = CallbackProxy::getName(env, listener);


    auto newInstance = CallbackProxy::newInstance(env);
    CallbackProxy::setLock(env, listener, newInstance);
    CallbackProxy::onJobProgress(env, listener, 20);

    auto nestedClass = NestedClassProxy::newInstance(env, listener);
    CallbackProxy::setLock(env, newInstance, nestedClass);
    CallbackProxy::onJobProgress(env, listener, 50);

    CallbackProxy::setAStaticField(env, nullptr);

    CallbackProxy::setCount(env, listener, 100);
    CallbackProxy::setLock(env, listener, listener);
    CallbackProxy::onJobProgress(env, listener, 100);

    jstring str = env->NewStringUTF("Yes, callback from jni");
    CallbackProxy::onJobDone(env, listener, JNI_TRUE, str);

    env->DeleteLocalRef(name);
    env->DeleteLocalRef(str);

    env->DeleteLocalRef(newInstance);
    env->DeleteLocalRef(nestedClass);
    return 0;
}

/*
 * Class:     io.github.landerlyoung.jennysampleapp.ComputeIntensiveClass
 * Method:    public static void runJniHelperTest()
 * Signature: ()V
 */
void ComputeIntensiveClass::runJniHelperTest(JNIEnv* env, jclass clazz) {
    // TODO: generated method stub.
    jenny::internal::jniHelperUnitTest(env);
}


