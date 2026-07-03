/******************************************************************************
 * File : image.c
 *
 * This file contains the ACTUAL implementation of create_image().
 *
 * image.h only tells the compiler:
 *
 *      "This function exists."
 *
 * image.c contains:
 *
 *      "This is HOW the function works."
 *
 ******************************************************************************/

#include "image.h"
/*
 * Include our own header file.
 *
 * Why?
 *
 * It gives this source file the function declaration.
 *
 * This lets the compiler verify that the implementation
 * exactly matches the declaration in image.h.
 */

#include <stdio.h>
/*
 * Standard Input / Output Library
 *
 * This provides functions like:
 *
 * fopen()
 * fclose()
 * fprintf()
 * fwrite()
 *
 * Without stdio.h,
 * the compiler wouldn't know what those functions are.
 */


/******************************************************************************
 * Function Definition
 ******************************************************************************/

/*
 * Return Type:
 *
 *      void
 *
 * Meaning:
 *
 * This function does NOT return anything.
 */

void create_image(

    /*
     * First argument
     *
     * Pointer to a string.
     *
     * Example:
     *
     *      "output.ppm"
     */

    const char *filename,

    /*
     * Image width
     */

    int width,

    /*
     * Image height
     */

    int height
)

{
    /**********************************************************************
     * Open the output file
     **********************************************************************/

    FILE *fp = fopen(filename, "wb");

    /*
     * FILE
     * ----
     *
     * FILE is a structure defined inside stdio.h.
     *
     * It stores information about an opened file.
     *
     * fp means:
     *
     *      File Pointer
     *
     * fopen()
     * -------
     *
     * Opens a file.
     *
     * First parameter:
     *
     *      filename
     *
     * Example:
     *
     *      output.ppm
     *
     * Second parameter:
     *
     *      "wb"
     *
     * w = Write
     *
     * If file exists:
     *      erase it
     *
     * If file doesn't exist:
     *      create it
     *
     * b = Binary mode
     *
     * Binary mode writes raw bytes.
     */

    if (!fp)
    {
        /*
         * fopen() failed.
         *
         * fp == NULL
         *
         * Possible reasons:
         *
         * • Invalid folder
         * • No permission
         * • Disk full
         */

        return;
    }

    /**********************************************************************
     * Write the PPM Header
     **********************************************************************/

    fprintf(
        fp,
        "P6\n%d %d\n255\n",
        width,
        height
    );

    /*
     * fprintf()
     *
     * Similar to printf()
     *
     * printf()
     * writes to the SCREEN.
     *
     * fprintf()
     * writes to a FILE.
     *
     *
     * Header becomes:
     *
     * P6
     * 1800 1200
     * 255
     *
     *
     * P6
     * ----
     * Means:
     *
     * Binary RGB image
     *
     * 1800 1200
     *
     * Width Height
     *
     * 255
     *
     * Maximum color value.
     *
     * RGB values can be:
     *
     * 0
     *
     * up to
     *
     * 255
     */

    /**********************************************************************
     * Draw every pixel
     **********************************************************************/

    for (int y = 0; y < height; y++)
    {
        /*
         * y represents the row.
         *
         * Starts at:
         *
         * y = 0
         *
         * Ends at:
         *
         * height-1
         */

        for (int x = 0; x < width; x++)
        {
            /*
             * x represents the column.
             */

            unsigned char pixel[3] =
            {
                255,   /* RED   */
                255,   /* GREEN */
                255    /* BLUE  */
            };

            /*
             * unsigned char
             *
             * One byte.
             *
             * Range:
             *
             * 0
             * to
             * 255
             *
             * Perfect for color values.
             *
             * pixel[0]
             *
             * Red
             *
             * pixel[1]
             *
             * Green
             *
             * pixel[2]
             *
             * Blue
             *
             *
             * Current color:
             *
             * RGB(255,255,255)
             *
             * White
             */

            fwrite(

                pixel,

                1,

                3,

                fp

            );

            /*
             * fwrite()
             *
             * Writes raw bytes.
             *
             * Parameter 1:
             *
             * pixel
             *
             * Address of data.
             *
             * Parameter 2:
             *
             * Size of ONE element.
             *
             * Here:
             *
             * 1 byte
             *
             * Parameter 3:
             *
             * Number of elements.
             *
             * Here:
             *
             * 3 bytes
             *
             * Parameter 4:
             *
             * File pointer.
             *
             *
             * Therefore:
             *
             * Write:
             *
             * R
             * G
             * B
             *
             * Total:
             *
             * 3 bytes
             */
        }
    }

    /**********************************************************************
     * Close the file
     **********************************************************************/

    fclose(fp);

    /*
     * Always close files.
     *
     * This ensures:
     *
     * • Data is written to disk
     * • Memory is released
     * • File handle is freed
     */

}

/******************************************************************************
 *
 * Example:
 *
 * create_image("test.ppm",1800,1200);
 *
 * Header written:
 *
 *      P6
 *      1800 1200
 *      255
 *
 * Then:
 *
 * 1800 × 1200
 * =
 * 2,160,000 pixels
 *
 * Every pixel contains:
 *
 *      R
 *      G
 *      B
 *
 * Total image data:
 *
 * 2,160,000 × 3
 *
 * =
 * 6,480,000 bytes
 *
 * Since every pixel is:
 *
 * RGB(255,255,255)
 *
 * the final image is completely WHITE.
 *
 ******************************************************************************/