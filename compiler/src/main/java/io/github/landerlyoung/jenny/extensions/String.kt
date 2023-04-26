package io.github.landerlyoung.jenny.extensions

import java.util.*

fun String.capitalize(): String {
    return capitalize(Locale.getDefault())
}

fun String.capitalize(locale: Locale): String {
    return replaceFirstChar { if (it.isLowerCase()) it.titlecase(locale) else it.toString() }
}