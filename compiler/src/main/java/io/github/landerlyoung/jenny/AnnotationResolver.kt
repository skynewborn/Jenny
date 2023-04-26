/**
 * Copyright 2016 landerlyoung@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package io.github.landerlyoung.jenny

import java.lang.reflect.Proxy

/**
 * Author: landerlyoung@gmail.com
 * Date:   2016-06-19
 * Time:   15:45
 * Life with Passion, Code with Creativity.
 */

object AnnotationResolver {
    @Suppress("UNCHECKED_CAST")
    fun <T : Annotation> getDefaultImplementation(annotation: Class<T>): T =
        Proxy.newProxyInstance(
            annotation.classLoader,
            arrayOf<Class<*>>(annotation)
        ) { _, method, _ ->
            method.defaultValue
        } as T
}
