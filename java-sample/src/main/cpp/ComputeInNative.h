/*
 * JNI Header file generated by annotation JNI helper
 * written by landerlyoung@gmail.com
 */

/* C/C++ header file for class com.young.jennysampleapp.ComputeIntensiveClass */
#pragma once

#include <jni.h>



/*
 * Class:     com_young_jenny_ComputeInNative
 * Method:    public boolean init()
 * Signature: ()Z
 */
jboolean init(JNIEnv *env, jobject thiz);


/*
 * Class:     com_young_jenny_ComputeInNative
 * Method:    public void release()
 * Signature: ()V
 */
void release(JNIEnv *env, jobject thiz);


/*
 * Class:     com_young_jenny_ComputeInNative
 * Method:    public void setParam(java.util.Map<java.lang.String,java.lang.String> globalHttpParam)
 * Signature: (Ljava/util/Map;)V
 */
void setParam(JNIEnv *env, jobject thiz, jobject globalHttpParam);


/*
 * Class:     com_young_jenny_ComputeInNative
 * Method:    public java.util.Map<java.lang.String,java.lang.String> getGlobalParam()
 * Signature: ()Ljava/util/Map;
 */
jobject getGlobalParam(JNIEnv *env, jobject thiz);


/*
 * Class:     com_young_jenny_ComputeInNative
 * Method:    public boolean request(java.lang.String json, com.young.jenny.RequestListener listener)
 * Signature: (Ljava/lang/String;Lcom/young/jenny/RequestListener;)Z
 */
jboolean request(JNIEnv *env, jobject thiz, jstring json, jobject listener);




#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved);
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved);
#ifdef __cplusplus
}
#endif
