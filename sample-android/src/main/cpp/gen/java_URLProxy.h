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

namespace java {
class URLProxy {

public:
    static constexpr auto FULL_CLASS_NAME = "java/net/URL";



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

    URLProxy(): URLProxy(nullptr, nullptr) {}
    
    URLProxy(JNIEnv* env, jobject javaObj)
            : mJniEnv(env), mJavaObjectReference(javaObj) {
        if (env) { assertInited(env); }
    }

    URLProxy(const URLProxy& from) = default;
    URLProxy &operator=(const URLProxy &) = default;

    URLProxy(URLProxy&& from) noexcept
           : mJniEnv(from.mJniEnv), mJavaObjectReference(from.mJavaObjectReference) {
        from.mJavaObjectReference = nullptr;
    }
    
    URLProxy& operator=(URLProxy&& from) noexcept {
       mJniEnv = from.mJniEnv;
       std::swap(mJavaObjectReference, from.mJavaObjectReference);
       return *this;
   }

    ~URLProxy() = default;
    
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
    
    // construct: public URL(java.lang.String protocol, java.lang.String host, int port, java.lang.String file)
    static URLProxy newInstance(JNIEnv* env, jstring protocol, jstring host, jint port, jstring file) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(sClazz, sConstruct_0, protocol, host, port, file));
    } 
    
    // construct: public URL(java.lang.String protocol, java.lang.String host, java.lang.String file)
    static URLProxy newInstance(JNIEnv* env, jstring protocol, jstring host, jstring file) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(sClazz, sConstruct_1, protocol, host, file));
    } 
    
    // construct: public URL(java.lang.String protocol, java.lang.String host, int port, java.lang.String file, java.net.URLStreamHandler handler)
    static URLProxy newInstance(JNIEnv* env, jstring protocol, jstring host, jint port, jstring file, jobject handler) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(sClazz, sConstruct_2, protocol, host, port, file, handler));
    } 
    
    // construct: public URL(java.lang.String spec)
    static URLProxy newInstance(JNIEnv* env, jstring spec) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(sClazz, sConstruct_3, spec));
    } 
    
    // construct: public URL(java.net.URL context, java.lang.String spec)
    static URLProxy newInstance(JNIEnv* env, jobject context, jstring spec) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(sClazz, sConstruct_4, context, spec));
    } 
    
    // construct: public URL(java.net.URL context, java.lang.String spec, java.net.URLStreamHandler handler)
    static URLProxy newInstance(JNIEnv* env, jobject context, jstring spec, jobject handler) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(sClazz, sConstruct_5, context, spec, handler));
    } 
    

    // method: public java.lang.String getQuery()
    jstring getQuery() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getQuery_0));
    }

    // method: public java.lang.String getPath()
    jstring getPath() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getPath_0));
    }

    // method: public java.lang.String getUserInfo()
    jstring getUserInfo() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getUserInfo_0));
    }

    // method: public java.lang.String getAuthority()
    jstring getAuthority() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getAuthority_0));
    }

    // method: public int getPort()
    jint getPort() const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, sMethod_getPort_0);
    }

    // method: public int getDefaultPort()
    jint getDefaultPort() const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, sMethod_getDefaultPort_0);
    }

    // method: public java.lang.String getProtocol()
    jstring getProtocol() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getProtocol_0));
    }

    // method: public java.lang.String getHost()
    jstring getHost() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getHost_0));
    }

    // method: public java.lang.String getFile()
    jstring getFile() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getFile_0));
    }

    // method: public java.lang.String getRef()
    jstring getRef() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getRef_0));
    }

    // method: public boolean equals(java.lang.Object obj)
    jboolean equals(jobject obj) const {
        return mJniEnv->CallBooleanMethod(mJavaObjectReference, sMethod_equals_0, obj);
    }

    // method: public synchronized int hashCode()
    jint hashCode() const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, sMethod_hashCode_0);
    }

    // method: public boolean sameFile(java.net.URL other)
    jboolean sameFile(jobject other) const {
        return mJniEnv->CallBooleanMethod(mJavaObjectReference, sMethod_sameFile_0, other);
    }

    // method: public java.lang.String toString()
    jstring toString() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_toString_0));
    }

    // method: public java.lang.String toExternalForm()
    jstring toExternalForm() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_toExternalForm_0));
    }

    // method: public java.net.URI toURI()
    jobject toURI() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_toURI_0);
    }

    // method: public java.net.URLConnection openConnection()
    jobject openConnection() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_openConnection_0);
    }

    // method: public java.net.URLConnection openConnection(java.net.Proxy proxy)
    jobject openConnection(jobject proxy) const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_openConnection_1, proxy);
    }

    // method: public java.io.InputStream openStream()
    jobject openStream() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_openStream_0);
    }

    // method: public java.lang.Object getContent()
    jobject getContent() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getContent_0);
    }

    // method: public java.lang.Object getContent(java.lang.Class[] classes)
    jobject getContent(jobjectArray classes) const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getContent_1, classes);
    }

    // method: public static void setURLStreamHandlerFactory(java.net.URLStreamHandlerFactory fac)
    static void setURLStreamHandlerFactory(JNIEnv* env, jobject fac) {
        assertInited(env);
        env->CallStaticVoidMethod(sClazz, sMethod_setURLStreamHandlerFactory_0, fac);
    }



private:
    static jclass sClazz;
    static jmethodID sConstruct_0;
    static jmethodID sConstruct_1;
    static jmethodID sConstruct_2;
    static jmethodID sConstruct_3;
    static jmethodID sConstruct_4;
    static jmethodID sConstruct_5;

    static jmethodID sMethod_getQuery_0;
    static jmethodID sMethod_getPath_0;
    static jmethodID sMethod_getUserInfo_0;
    static jmethodID sMethod_getAuthority_0;
    static jmethodID sMethod_getPort_0;
    static jmethodID sMethod_getDefaultPort_0;
    static jmethodID sMethod_getProtocol_0;
    static jmethodID sMethod_getHost_0;
    static jmethodID sMethod_getFile_0;
    static jmethodID sMethod_getRef_0;
    static jmethodID sMethod_equals_0;
    static jmethodID sMethod_hashCode_0;
    static jmethodID sMethod_sameFile_0;
    static jmethodID sMethod_toString_0;
    static jmethodID sMethod_toExternalForm_0;
    static jmethodID sMethod_toURI_0;
    static jmethodID sMethod_openConnection_0;
    static jmethodID sMethod_openConnection_1;
    static jmethodID sMethod_openStream_0;
    static jmethodID sMethod_getContent_0;
    static jmethodID sMethod_getContent_1;
    static jmethodID sMethod_setURLStreamHandlerFactory_0;


};
} // endof namespace java
