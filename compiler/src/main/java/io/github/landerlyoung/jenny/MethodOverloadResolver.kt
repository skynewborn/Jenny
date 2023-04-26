package io.github.landerlyoung.jenny

import io.github.landerlyoung.jenny.models.MethodRecord
import javax.lang.model.element.ExecutableElement

/**
 * Author: landerlyoung@gmail.com
 * Date:   2019-09-26
 * Time:   17:26
 * Life with Passion, Code with Creativity.
 */
class MethodOverloadResolver(
    private val helper: HandyHelper,
    private val nativeParamResolver: (ExecutableElement) -> String
) {

    fun resolve(methodList: List<ExecutableElement>): List<MethodRecord> {
        val duplicateRecord = mutableMapOf<String, Boolean>()
        methodList.forEach {
            val p = nativeParamResolver(it)
            duplicateRecord[p] = duplicateRecord.containsKey(p)
        }

        return methodList.mapIndexed { index, m ->
            val p = nativeParamResolver(m)
            if (duplicateRecord[p]!! || Constants.CPP_RESERVED_WORS.contains(m.simpleName.toString())) {
                MethodRecord(
                    helper,
                    m,
                    helper.getMethodOverloadPostfix(m),
                    index
                )
            } else {
                MethodRecord(helper, m, "", index)
            }
        }
    }

}