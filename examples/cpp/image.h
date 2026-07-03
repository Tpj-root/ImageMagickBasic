/******************************************************************************
 * File: image.h
 *
 * This is a HEADER FILE.
 *
 * A header file usually contains:
 *   - Function declarations (prototypes)
 *   - Constants
 *   - Structures
 *   - Macros
 *
 * It DOES NOT normally contain the actual function implementation.
 * The implementation is placed in image.c.
 ******************************************************************************/

#ifndef IMAGE_H
/*
 * #ifndef = "If NOT Defined"
 *
 * This checks whether IMAGE_H has already been defined.
 *
 * Why?
 *
 * Imagine:
 *
 * main.cpp
 *     |
 *     +-----> image.h
 *     |
 *     +-----> other.h
 *                 |
 *                 +-----> image.h
 *
 * Without this check, image.h would be included TWICE.
 *
 * That causes compiler errors like:
 *
 *     error: redefinition of ...
 *
 * So this prevents multiple inclusion.
 */

#define IMAGE_H
/*
 * Define IMAGE_H.
 *
 * The first time image.h is included:
 *
 *     IMAGE_H is NOT defined
 *     -> Compiler reads this file
 *     -> IMAGE_H becomes defined
 *
 * Next time:
 *
 *     IMAGE_H already exists
 *     -> Compiler skips the entire file.
 */

#ifdef __cplusplus
/*
 * __cplusplus is automatically defined by a C++ compiler.
 *
 * If compiling with:
 *
 *      gcc
 *
 * then __cplusplus does NOT exist.
 *
 * If compiling with:
 *
 *      g++
 *
 * then __cplusplus DOES exist.
 *
 * This lets us write one header that works in BOTH C and C++.
 */

extern "C" {
/*
 * This tells the C++ compiler:
 *
 * "Everything inside these braces uses C naming."
 *
 * Why?
 *
 * C compiler:
 *
 *      create_image
 *
 * C++ compiler changes names internally
 * (called NAME MANGLING)
 *
 * Example:
 *
 *      create_image
 *
 * may become something like
 *
 *      _Z12create_imagePKcii
 *
 * The linker then cannot find the C function.
 *
 * extern "C" disables name mangling.
 *
 * So C++ will call exactly:
 *
 *      create_image
 *
 * which matches the function inside image.c.
 */
#endif

/******************************************************************************
 * Function Declaration (Prototype)
 ******************************************************************************/

/*
 * Function name:
 *
 *      create_image()
 *
 * Return type:
 *
 *      void
 *
 * Meaning:
 *
 *      This function returns NOTHING.
 */

void create_image(
    /*
     * First parameter
     *
     * const char *filename
     *
     * const
     * -----
     * Means the function promises NOT to modify
     * the filename string.
     *
     * char *
     * -----
     * Pointer to characters.
     *
     * Example:
     *
     *      "output.ppm"
     *
     * becomes
     *
     *      const char *
     */

    const char *filename,

    /*
     * Second parameter
     *
     * Width of image.
     *
     * Example:
     *
     *      1800
     */

    int width,

    /*
     * Third parameter
     *
     * Height of image.
     *
     * Example:
     *
     *      1200
     */

    int height

);
/*
 * Notice:
 *
 * This ends with a semicolon.
 *
 * That means:
 *
 * "The function exists somewhere else."
 *
 * The actual code is inside image.c
 */

#ifdef __cplusplus

}
/*
 * End of:
 *
 * extern "C"
 *
 * After this point,
 * C++ returns to normal C++ mode.
 */

#endif

#endif
/*
 * End of
 *
 * #ifndef IMAGE_H
 *
 * If IMAGE_H was already defined,
 * the compiler jumps directly here.
 */