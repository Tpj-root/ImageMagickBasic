#include <stdio.h>

int main(void)
{
    const int width = 1800;
    const int height = 1200;

    FILE *fp = fopen("output.ppm", "wb");
    if (!fp)
        return 1;

    // PPM Header
    fprintf(fp, "P6\n%d %d\n255\n", width, height);

    // White image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            //unsigned char pixel[3] = {255, 255, 255};
            //fwrite(pixel, 1, 3, fp);
			
			unsigned char pixel[3];
			
			if (x == width / 2)
			{
			    pixel[0] = 0;
			    pixel[1] = 0;
			    pixel[2] = 0;
			}
			else
			{
			    pixel[0] = 255;
			    pixel[1] = 255;
			    pixel[2] = 255;
			}
			
			fwrite(pixel, 1, 3, fp);

        }
    }

    fclose(fp);

    printf("Image created!\n");
    return 0;
}
