# Jenny -- a JNI code generator

---


## 简介

**Jenny**是一个JNI代码生成器。它基于Java注解，在编译阶段，生成与Java类相对应的Native代码框架；开发者只需在其中补充相应方法的具体实现即可完成JNI方法编写，无需关心实现JNI所需的方法注册、类型转换等繁琐且乏味的细节。

本项目基于[https://github.com/LanderlYoung/Jenny](https://github.com/LanderlYoung/Jenny)改进，使用[Velocity](https://velocity.apache.org/)模板进行相关代码的生成，并根据内部使用的场景，屏蔽了一些配置项。更多细节请自行查阅代码。

Jenny目前可生成两类代码：
1. Java调用Native：可自动对应Java类中的native方法，生成相应的原生代码。
2. Native调用Java：可生成C++辅助类，便于从Native访问Java相关的类、方法、成员等。


## 如何使用

### 1、配置Gradle

在需要生成JNI代码的模块目录下，在`build.gradle`中添加如下依赖：

```groovy

dependencies {
    ......
    def jenny_version = '1.3.1-SNAPSHOT'
    compileOnly "io.github.landerlyoung:jenny-annotation:$jenny_version"
    // 对于Java项目
    annotationProcessor "io.github.landerlyoung:jenny-compiler:$jenny_version"
    // 对于Kotlin项目使用如下配置
    // kapt "io.github.landerlyoung:jenny-compiler:$jenny_version"
}
```

### 2、为Java代码添加注解

在包含native方法定义的Java类上添加`@NativeClass`注解，Jenny即可生成相应的Java->Native代码。

在需要在Native端使用的Java/Kotlin类上添加`@NativeProxy(allMethods = true, allFields = true)`注解，Jenny即可生成相应的Native->Java代理类，并为类中的所有成员及方法自动生成Native代理方法。更细粒度的控制，如只针对特定方法或成员进行代理，可结合`@NativeMethodProxy`及`@NativeFieldProxy`注解使用。

如果要对第三方库中的类生成Native代理代码，可在实现相应功能的native方法上使用`@NativeProxyForClasses` 注解，但由于运行时版本匹配等原因，可能会引入较大的稳定性风险，所以通常不建议这种直接在Native端调用相应API的使用方式；更好的方式是在Java端进行一些封装转换，处理好相应的异常，然后从C++端去调用自己封装的这些API。

### 3、使用生成的代码

项目成功编译之后，可在`build/generated/ap_generated_sources/debug/out/jnigen`目录下找到生成的代码（对于Kotlin项目，其位置在`build/generated/source/kapt/debug/jnigen`）。生成代码的位置也可通过配置项进行更改，详见[配置](#配置)。

将目录中相关文件拷贝至你的C++代码目录，并将其中的.cpp文件及.h文件配置到`CMakeFileList.txt`中即可开始使用。生成代码的结构与内容可参见[生成结果示例](#生成结果示例)，一般来说，你只需要将实际实现逻辑填入Java->Native代码相应桩位中即可，其余文件不建议手动修改。

**注意：在使用生成代码的时候，`include`目录结构建议不要随意变更，否则可能会影响相关头文件的有效引用。**


## 配置

支持的配置项及说明如下：

| 名称 | 默认值 | 说明 |
| :-: | :-: | :- |
| `threadSafe` | `true` | 代理类的初始化是否需要支持线程安全 |
| `errorLoggerFunction` | `null` | 如果配置了该项，则代理类发生类/方法/字段查找异常时会先记录日志。该方法必须是位于最顶端命名空间的一个C++方法，其签名是`void(JNIEnv* env, const char* error)` |
| `outputDirectory` | `null` | 该配置项可控制生成代码的目录。注意每次编译都会用最新生成的文件覆盖，所以请勿直接在生成目录中修改代码，以免丢失。 |


## 生成结果示例

### Java -> Native

Java类：

```java
@NativeClass
public class NativeTest {
    public static final int RUNTIME_TYPE_MAIN = 1;
    public native int add(int a, int b);
    public native void cpp_magic(String s, byte[] data);
}
```

生成的Native代码：

```C++
// NativeTest.h

namespace NativeTest {
static constexpr auto FULL_CLASS_NAME = u8"io/github/landerlyoung/jennysampleapp/NativeTest";
static constexpr jint RUNTIME_TYPE_MAIN = 1;

jint JNICALL add(JNIEnv* env, jobject thiz, jint a, jint b);
void JNICALL cpp_magic(JNIEnv* env, jobject thiz, jstring s, jbyteArray data);

inline bool registerNativeFunctions(JNIEnv* env) { ... }

}

// NativeTest.cpp

jint NativeTest::add(JNIEnv* env, jobject thiz, jint a, jint b) {
    // TODO: generated method stub.
    return 0;
}

void NativeTest::cpp_magic(JNIEnv* env, jobject thiz, jstring s, jbyteArray data) {
    // TODO: generated method stub.
}

```

Jenny会生成如下内容：

1. 常量定义。
2. JNI注册方法。
3. C++方法定义。
4. C++方法实现桩代码。开发者只需替换为实际逻辑实现代码即可。
5. `jni_entry.cpp`：JNI入口（`JNI_OnLoad`）方法实现，其中会完成JNI方法的注册。

### Native -> Java

下面代码展示了Native端如何通过生成的代理类调用Java端的相关接口发送HTTP请求：

```C++
jstring func(jstring _url) {
    jenny::LocalRef<jstring> url(_url, false);

    OkHttpClientProxy client = OkHttpClientProxy::newInstance();
    BuilderProxy builder = BuilderProxy::newInstance().url(url);
    RequestProxy request = builder.build();
    CallProxy call = client.newCall(request.getThis());
    ResponseProxy response = call.execute();
    ResponseBodyProxy body = response.body();
    return body.string().release();
}
```
类似的Java实现代码如下所示：

```java
String run(String url) throws IOException {
    OkHttpClient client = new OkHttpClient();
    Request request = new Request.Builder()
        .url(url)
        .build();

    Response response = client.newCall(request).execute();
    return response.body().string();
}
```

对比可见，通过代理类调用Java API，形式上与Java代码很接近，大大简化了通过JNI原生`env->FindClass`、`env->GetMethodID`、`env->CallXXXMethod`的繁琐易错调用步骤。


## License

Apache License Version 2.0.