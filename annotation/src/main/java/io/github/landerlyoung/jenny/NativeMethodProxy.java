/**
 * Copyright 2016 landerlyoung@gmail.com
 * <p>
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * <p>
 * http://www.apache.org/licenses/LICENSE-2.0
 * <p>
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package io.github.landerlyoung.jenny;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * <p>
 * Control whether should Jenny generate proxy function for this method/constructor.
 * Regardless of the {@link NativeProxy @NativeReflace(allMethos = false) or @NativeReflace(allMethos = true)} config.
 * </p>
 *
 * <hr>
 * <pre>
 * Author: landerlyoung@gmail.com
 * Date:   2016-06-02
 * Time:   20-01
 * Life with Passion, Code with Creativity.
 * </pre>
 * @see NativeProxy#allMethods()
 */
@Retention(RetentionPolicy.CLASS)
@Target({ElementType.METHOD, ElementType.CONSTRUCTOR})
public @interface NativeMethodProxy {
    boolean enabled() default true;
}
