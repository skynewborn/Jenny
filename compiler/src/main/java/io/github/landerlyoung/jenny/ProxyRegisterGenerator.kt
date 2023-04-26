package io.github.landerlyoung.jenny

import io.github.landerlyoung.jenny.models.CppClass


/**
 * Author: taylorcyang@tencent.com
 * Date:   2020-10-21
 * Time:   15:48
 * Life with Passion, Code with Creativity.
 */
class ProxyRegisterGenerator(
    private val env: Environment,
    _proxyClasses: Collection<CppClass>
) {

    private val proxyClasses: List<CppClass> = _proxyClasses.sorted()

    fun generate() {
        env.createOutputFile(
            Constants.JENNY_GEN_DIR_PROXY_FILES,
            Constants.JENNY_PROXY_REGISTER_HEADER_NAME
        ).use { out ->
            val vars = HashMap<String, List<CppClass>>().apply {
                put("proxyClasses", proxyClasses)
            }
            val result = env.renderTemplate("templates/proxy_reg.vm", vars)
            out.write(result.toByteArray(Charsets.UTF_8))
        }
    }

}