package io.github.landerlyoung.jenny

import io.github.landerlyoung.jenny.models.CppClass

class JniEntryGenerator(
    private val env: Environment,
    _nativeClasses: Collection<CppClass>,
    _proxyClasses: Collection<CppClass>
) {

    private val nativeClasses: List<CppClass> = _nativeClasses.sorted()
    private val hasProxy: Boolean = _proxyClasses.isNotEmpty()

    fun generate() {
        env.createOutputFile(
            Constants.JENNY_GEN_DIR,
            Constants.JENNY_JNI_ENTRY_SOURCE_NAME
        ).use { out ->
            val vars = HashMap<String, Any>().apply {
                put("nativeClasses", nativeClasses)
                put("hasProxy", hasProxy)
            }
            val result = env.renderTemplate("templates/jni_entry.vm", vars)
            out.write(result.toByteArray(Charsets.UTF_8))
        }
    }

}