/******************************************************************************
 *
 * File : main.cpp
 *
 * This is the PROGRAM ENTRY POINT.
 *
 * Every C++ program starts execution from:
 *
 *      main()
 *
 * The operating system loads your program into memory,
 * then automatically calls main().
 *
 ******************************************************************************/

#include "image.h"

/*
 * Include our own header file.
 *
 * image.h contains the declaration:
 *
 *      void create_image(...);
 *
 * Without including image.h,
 * the compiler would not know that create_image()
 * exists.
 *
 * The compiler checks:
 *
 *      Is there a function named create_image()?
 *
 * image.h answers:
 *
 *      Yes.
 *
 * The actual implementation is inside:
 *
 *      image.c
 */


/******************************************************************************
 *
 * Program Entry Point
 *
 ******************************************************************************/

/*
 * int
 *
 * main() returns an integer to the Operating System.
 *
 * The returned value is called:
 *
 *      Exit Status
 *
 * 0
 *
 * means
 *
 *      Success
 *
 * Non-zero values usually mean
 *
 *      Error
 */

int main()
{

    /**********************************************************************
     * Create an Image
     **********************************************************************/

    create_image(

        /*
         * Parameter 1
         *
         * File name.
         *
         * This is where the image will be saved.
         *
         * Because it is a string,
         * it is enclosed inside double quotes.
         */

        "test.ppm",

        /*
         * Parameter 2
         *
         * Image Width
         *
         * Units:
         *
         * Pixels
         */

        1800,

        /*
         * Parameter 3
         *
         * Image Height
         *
         * Units:
         *
         * Pixels
         */

        1200

    );

    /*
     *
     * What happens internally?
     *
     * main()
     *
     *      |
     *      |
     *      +------> create_image()
     *                     |
     *                     |
     *                     +---- Open file
     *                     |
     *                     +---- Write PPM header
     *                     |
     *                     +---- Draw every pixel
     *                     |
     *                     +---- Close file
     *
     * After create_image() finishes,
     * execution returns here.
     *
     */

    /**********************************************************************
     * Return to the Operating System
     **********************************************************************/

    return 0;

    /*
     * return
     *
     * Stops execution of main().
     *
     * Returns control back to the Operating System.
     *
     * The value:
     *
     *      0
     *
     * tells Linux / Windows:
     *
     *      Program completed successfully.
     *
     * If you returned:
     *
     *      return 1;
     *
     * it would usually indicate
     * that an error occurred.
     */

}

/******************************************************************************
 *
 * Program Flow
 *
 *          Operating System
 *                 |
 *                 |
 *                 V
 *             main()
 *                 |
 *                 |
 *                 V
 *      create_image("test.ppm",1800,1200)
 *                 |
 *                 |
 *                 +---- fopen()
 *                 |
 *                 +---- fprintf()
 *                 |
 *                 +---- for(y)
 *                 |        |
 *                 |        +---- for(x)
 *                 |                 |
 *                 |                 +---- fwrite()
 *                 |
 *                 +---- fclose()
 *                 |
 *                 V
 *            return to main()
 *                 |
 *                 V
 *             return 0
 *                 |
 *                 V
 *          Operating System
 *
 ******************************************************************************/