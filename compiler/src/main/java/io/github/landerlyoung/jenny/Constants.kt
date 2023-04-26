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

/**
 * Author: landerlyoung@gmail.com
 * Date:   2016-06-03
 * Time:   00:42
 * Life with Passion, Code with Creativity.
 */
object Constants {
    const val JENNY_GEN_DIR = "jnigen"

    const val JENNY_GEN_DIR_HEADERS = "$JENNY_GEN_DIR.include.$JENNY_GEN_DIR"

    const val JENNY_GEN_DIR_PROXY_FILES = "$JENNY_GEN_DIR_HEADERS.proxy"

    const val JENNY_GEN_DIR_GLUE_SOURCE = JENNY_GEN_DIR

    const val JENNY_GEN_DIR_GLUE_HEADER = "$JENNY_GEN_DIR_HEADERS.jni"

    const val JENNY_PROXY_REGISTER_HEADER_NAME = "proxy_reg.h"

    const val JENNY_JNI_HELPER_HEADER_NAME = "jni_helper.h"

    const val JENNY_JNI_ENTRY_SOURCE_NAME = "jni_entry.cpp"

    val JENNY_JNI_HELPER_H_CONTENT: String
        get() = Constants.javaClass.classLoader.getResourceAsStream(JENNY_JNI_HELPER_HEADER_NAME)!!
            .use {
                String(it.readBytes(), Charsets.UTF_8)
            }

    //  https://en.cppreference.com/w/cpp/keyword
    val CPP_RESERVED_WORS = setOf(
        "alignas",
        "alignof",
        "and",
        "and_eq",
        "asm",
        "atomic_cancel",
        "atomic_commit",
        "atomic_noexcept",
        "auto",
        "bitand",
        "bitor",
        "bool",
        "break",
        "case",
        "catch",
        "char",
        "char8_t",
        "char16_t",
        "char32_t",
        "class",
        "compl",
        "concept",
        "const",
        "consteval",
        "constexpr",
        "constinit",
        "const_cast",
        "continue",
        "co_await",
        "co_return",
        "co_yield",
        "decltype",
        "default",
        "delete",
        "do",
        "double",
        "dynamic_cast",
        "else",
        "enum",
        "explicit",
        "export",
        "extern",
        "false",
        "float",
        "for",
        "friend",
        "goto",
        "if",
        "inline",
        "int",
        "long",
        "mutable",
        "namespace",
        "new",
        "noexcept",
        "not",
        "not_eq",
        "nullptr",
        "operator",
        "or",
        "or_eq",
        "private",
        "protected",
        "public",
        "reflexpr",
        "register",
        "reinterpret_cast",
        "requires",
        "return",
        "short",
        "signed",
        "sizeof",
        "static",
        "static_assert",
        "static_cast",
        "struct",
        "switch",
        "synchronized",
        "template",
        "this",
        "thread_local",
        "throw",
        "true",
        "try",
        "typedef",
        "typeid",
        "typename",
        "union",
        "unsigned",
        "using",
        "virtual",
        "void",
        "volatile",
        "wchar_t",
        "while",
        "xor",
        "xor_e"
    )
}
