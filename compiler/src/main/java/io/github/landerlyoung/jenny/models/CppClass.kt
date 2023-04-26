package io.github.landerlyoung.jenny.models

import io.github.landerlyoung.jenny.HandyHelper
import io.github.landerlyoung.jenny.extensions.toJniTypeForParam
import javax.lang.model.element.TypeElement

/*
 * ```
 * Author: taylorcyang@tencent.com
 * Date:   2020-10-21
 * Time:   15:43
 * Life with Passion, Code with Creativity.
 * ```
 */

data class CppClass(
    private val helper: HandyHelper,
    private val javaClass: TypeElement,
    val name: String,
    val namespace: String,
    val headerFileName: String
) : Comparable<CppClass> {
    val nestedClass: Boolean = helper.isNestedClass(javaClass)

    val enclosingElementJniType: String by lazy {
        if (nestedClass) {
            helper.toJNIType(javaClass.enclosingElement.asType())
        } else {
            ""
        }
    }
    fun getEnclosingElementJniParam(useJniHelper: Boolean): String {
        return if (nestedClass) {
            javaClass.enclosingElement.asType().toJniTypeForParam(helper, useJniHelper)
        } else {
            ""
        }
    }

    override fun compareTo(other: CppClass) = compareValuesBy(
        this, other,
        { it.namespace },
        { it.name })
}