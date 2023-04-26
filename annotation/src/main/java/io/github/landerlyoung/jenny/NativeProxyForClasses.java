package io.github.landerlyoung.jenny;

import java.lang.annotation.ElementType;
import java.lang.annotation.Repeatable;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * Tell Jenny to generate proxy code for given classes.
 * <p>
 * These class usually come from third-part library or JDK.
 * <p>
 * This Annotation can be added to any class.
 *
 * <pre>
 * Author: landerlyoung@gmail.com
 * Date:   2019-09-25
 * Time:   20:36
 * Life with Passion, Code with Creativity.
 * </pre>
 */
@Repeatable(NativeProxyForClasses.RepeatContainer.class)
@Retention(RetentionPolicy.CLASS)
@Target({ElementType.TYPE, ElementType.FIELD, ElementType.METHOD, ElementType.CONSTRUCTOR})
public @interface NativeProxyForClasses {
    /**
     * @return class generate proxy code for.
     */
    Class<?>[] classes() default {};

    /**
     * @return C++ namespace for generated class
     */
    String namespace() default "";

    /**
     * Java 8 repeatable annotation container.
     */
    @Retention(RetentionPolicy.CLASS)
    @Target(ElementType.TYPE)
    @interface RepeatContainer {
        NativeProxyForClasses[] value() default {};
    }
}
