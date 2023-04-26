package io.github.landerlyoung.jenny

/*
 * ```
 * Author: landerlyoung@gmail.com
 * Date:   2019-09-27
 * Time:   11:17
 * Life with Passion, Code with Creativity.
 * ```
 */
class NamespaceHelper(namespace: String) {
    val namespaces: List<String> = namespace.split("::").map { it.trim() }
        .filter { it.isNotEmpty() }

    val fileNamePrefix: String = namespaces.joinToString("_").let {
        if (it.isNotEmpty()) {
            it + "_"
        } else {
            it
        }
    }

    // like std::chrono
    val namespaceNotation: String = namespaces.joinToString("::")

}