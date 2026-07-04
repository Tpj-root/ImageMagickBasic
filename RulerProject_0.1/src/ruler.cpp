#include "ruler.hpp"

#include <Magick++.h>

using namespace Magick;



#include <cstdlib>
#include <ctime>

void DrawRandomPixels(
    Magick::Image& img,
    int count,
    int pixelSize = 1)
{
    static bool seeded = false;

    if(!seeded)
    {
        std::srand((unsigned)std::time(nullptr));
        seeded = true;
    }

    const int width  = img.columns();
    const int height = img.rows();

    for(int i = 0; i < count; i++)
    {
        int x = std::rand() % width;
        int y = std::rand() % height;

        int r = std::rand() % 256;
        int g = std::rand() % 256;
        int b = std::rand() % 256;

        img.fillColor(
            Magick::ColorRGB(
                r / 255.0,
                g / 255.0,
                b / 255.0
            )
        );

        img.strokeColor("transparent");

        img.draw(
            Magick::DrawableRectangle(
                x,
                y,
                x + pixelSize - 1,
                y + pixelSize - 1
            )
        );
    }
}



void DrawQRCode(
    Magick::Image& img,
    const std::string& qrFile,
    int x,
    int y,
    int size = 150)
{
    Magick::Image qr(qrFile);

    qr.resize(
        Magick::Geometry(size, size)
    );

    img.composite(
        qr,
        x,
        y,
        Magick::OverCompositeOp
    );
}







void DrawCopyrightNotice(Magick::Image& img)
{
    const int x = 500;
    const int y = img.rows() - 180;

    img.fillColor("black");
    img.strokeColor("transparent");
    img.fontPointsize(16);



    img.draw(Magick::DrawableText(x, y +   0, "Copyright Notice"));
    img.draw(Magick::DrawableText(x, y +  25, "Image Size: 1800 x 1200 pixels (6 x 4 inches at 300 DPI)"));
    img.draw(Magick::DrawableText(x, y +  50, "This image was generated using proprietary C++ software"));
    img.draw(Magick::DrawableText(x, y +  75, "developed by Hackerspace Trichy."));
    img.draw(Magick::DrawableText(x, y + 110, "Copyright (c) Hackerspace Trichy. All Rights Reserved."));
    img.draw(Magick::DrawableText(x, y + 145, "Unauthorized printing, copying, reproduction, modification,"));
    img.draw(Magick::DrawableText(x, y + 170, "redistribution, or commercial use is strictly prohibited"));
    img.draw(Magick::DrawableText(x, y + 195, "without prior written permission."));
}

void DrawTextSamples(Magick::Image& img)
{
    const int x = 40;
    int y = 60;

    //-------------------------------------------------
    // Title
    //-------------------------------------------------

    img.strokeWidth(1);
    img.fontPointsize(28);
    img.strokeColor("black");
    img.fillColor("black");
    img.strokeWidth(2);
    img.draw(Magick::DrawableText(x, y, "ImageMagick Text Demo"));


    y += 50;

    //-------------------------------------------------
    // Different colors
    //-------------------------------------------------
    img.strokeWidth(2);
    img.fontPointsize(20);
    img.strokeColor("red");
    img.fillColor("red");
    img.draw(Magick::DrawableText(x, y, "Red Text"));

    y += 35;

    img.strokeColor("green");
    img.fillColor("green");
    img.draw(Magick::DrawableText(x, y, "Green Text"));

    y += 35;

    img.strokeColor("blue");
    img.fillColor("blue");
    img.draw(Magick::DrawableText(x, y, "Blue Text"));

    y += 35;

    img.strokeColor("magenta");
    img.fillColor("magenta");
    img.draw(Magick::DrawableText(x, y, "Magenta Text"));

    y += 35;
    img.strokeColor("orange");
    img.fillColor("orange");
    img.draw(Magick::DrawableText(x, y, "Orange Text"));

    y += 50;

    //-------------------------------------------------
    // Different sizes
    //-------------------------------------------------
    img.strokeColor("black");
    img.fillColor("black");

    img.fontPointsize(12);
    img.draw(Magick::DrawableText(x, y, "Size 12"));

    y += 25;

    img.fontPointsize(18);
    img.draw(Magick::DrawableText(x, y, "Size 18"));

    y += 30;

    img.fontPointsize(24);
    img.draw(Magick::DrawableText(x, y, "Size 24"));

    y += 40;

    img.fontPointsize(32);
    img.draw(Magick::DrawableText(x, y, "Size 32"));

    y += 50;

    img.fontPointsize(48);
    img.draw(Magick::DrawableText(x, y, "Size 48"));
}



void DrawText(
    Magick::Image& img,
    const std::string& text,
    int x,
    int y,
    const std::string& color = "black",
    int size = 20)
{
    img.fillColor(color);
    img.strokeColor("transparent");
    img.fontPointsize(size);

    img.draw(
        Magick::DrawableText(
            x,
            y,
            text
        )
    );
}




void DrawCenterCross(Magick::Image& img, int size = 25)
{
    img.strokeColor("red");      // Change color here
    img.strokeWidth(3);

    const int centerX = img.columns() / 2;
    const int centerY = img.rows() / 2;

    // Horizontal line
    img.draw(
        Magick::DrawableLine(
            centerX - size,
            centerY,
            centerX + size,
            centerY
        )
    );

    // Vertical line
    img.draw(
        Magick::DrawableLine(
            centerX,
            centerY - size,
            centerX,
            centerY + size
        )
    );
}


void DrawAngleGuide(Magick::Image& img, int radius = 400)
{
    img.strokeColor("blue");
    img.fillColor("transparent");
    img.strokeWidth(2);

    const double PI = 3.14159265358979323846;

    const int cx = img.columns() - radius - 60;   // Right side
    const int cy = img.rows() / 2;

    //-------------------------------------------------
    // Outer circle
    //-------------------------------------------------

    img.draw(
        Magick::DrawableCircle(
            cx,
            cy,
            cx + radius,
            cy
        )
    );

    //-------------------------------------------------
    // Angle lines + labels
    //-------------------------------------------------

    for(int angle = 0; angle < 360; angle += 10)
    {
        double rad = angle * PI / 180.0;

        int tick = 8;

        if(angle % 90 == 0)
            tick = 20;
        else if(angle % 30 == 0)
            tick = 14;

        double x1 = cx + (radius - tick) * cos(rad);
        double y1 = cy - (radius - tick) * sin(rad);

        double x2 = cx + radius * cos(rad);
        double y2 = cy - radius * sin(rad);

        img.draw(
            Magick::DrawableLine(
                x1, y1,
                x2, y2
            )
        );

        // Label every 30°
        if(angle % 10 == 0)
        {
            double tx = cx + (radius + 20) * cos(rad);
            double ty = cy - (radius + 20) * sin(rad);

            img.draw(
                Magick::DrawableText(
                    tx,
                    ty,
                    std::to_string(angle)
                )
            );
        }
    }

    //-------------------------------------------------
    // Crosshair
    //-------------------------------------------------

    img.draw(
        Magick::DrawableLine(
            cx - radius,
            cy,
            cx + radius,
            cy
        )
    );

    img.draw(
        Magick::DrawableLine(
            cx,
            cy - radius,
            cx,
            cy + radius
        )
    );
}

void DrawInnerSquare(Magick::Image& img, int margin = 200)
{
    const int width  = img.columns();
    const int height = img.rows();

    img.draw(
        Magick::DrawableRectangle(
            margin,
            margin,
            width  - margin - 1,
            height - margin - 1
        )
    );
}

void CreateRuler()
{
    InitializeMagick(nullptr);

    Image img(
        Geometry(1800,1200),
        Color("white")
    );

    img.strokeColor("black");
    img.fillColor("black");
    img.strokeWidth(2);

    // DrawInnerSquare(img);
    DrawCenterCross(img, 50);
    DrawAngleGuide(img);
    DrawAngleGuide(img, 200);    
    DrawTextSamples(img);



    const double px_per_mm = 300.0 / 25.4;

    const int width  = img.columns();
    const int height = img.rows();

    //---------------------------------------------------
    // Top + Bottom rulers
    //---------------------------------------------------

    for(int mm = 0; mm <= 152; mm++)
    {
        double x = mm * px_per_mm;

        int len = 10;

        if(mm % 10 == 0)
            len = 60;
        else if(mm % 5 == 0)
            len = 35;

        img.draw(DrawableLine(x, 0, x, len));
        img.draw(DrawableLine(x, height - 1, x, height - 1 - len));
    }

    //---------------------------------------------------
    // Left + Right rulers
    //---------------------------------------------------

    for(int mm = 0; mm <= 102; mm++)
    {
        double y = mm * px_per_mm;

        int len = 10;

        if(mm % 10 == 0)
            len = 60;
        else if(mm % 5 == 0)
            len = 35;

        img.draw(DrawableLine(0, y, len, y));
        img.draw(DrawableLine(width - 1, y, width - 1 - len, y));
    }

    //---------------------------------------------------
    // Center horizontal ruler
    //---------------------------------------------------

    const double centerY = height / 3.0;

    for(int mm = 0; mm <= 152; mm++)
    {
        double x = mm * px_per_mm;

        int len = 4;

        if(mm % 10 == 0)
            len = 18;
        else if(mm % 5 == 0)
            len = 10;

        img.draw(DrawableLine(x, centerY - len, x, centerY + len));
    }

    //---------------------------------------------------
    // Center vertical ruler
    //---------------------------------------------------

    const double centerX = width / 3.0;

    for(int mm = 0; mm <= 102; mm++)
    {
        double y = mm * px_per_mm;

        int len = 4;

        if(mm % 10 == 0)
            len = 18;
        else if(mm % 5 == 0)
            len = 10;

        img.draw(DrawableLine(centerX - len, y, centerX + len, y));
    }



    //---------------------------------------------------
    // Center horizontal ruler
    //---------------------------------------------------

    const double centerYY = height / 4.0;

    for(int mm = 0; mm <= 152; mm++)
    {
        double x = mm * px_per_mm;

        int len = 4;

        if(mm % 10 == 0)
            len = 18;
        else if(mm % 5 == 0)
            len = 10;

        img.draw(DrawableLine(x, centerYY - len, x, centerYY + len));
    }

    //---------------------------------------------------
    // Center vertical ruler
    //---------------------------------------------------

    const double centerXX = width / 4.0;

    for(int mm = 0; mm <= 102; mm++)
    {
        double y = mm * px_per_mm;

        int len = 4;

        if(mm % 10 == 0)
            len = 18;
        else if(mm % 5 == 0)
            len = 10;

        img.draw(DrawableLine(centerXX - len, y, centerXX + len, y));
    }




// This function lets you specify:
// Text X position Y position Color Font size

    DrawText(img, "Hello", 100, 100);
    DrawText(img, "Red",   100, 150, "red",   24);
    DrawText(img, "Blue",  100, 200, "blue",  32);
    DrawText(img, "Green", 100, 260, "green", 18);
    DrawText(img, "White", 500, 500, "white", 40);
    DrawText(img, "shadow6", 200, 900, "Green", 40);
    DrawText(img, "https://github.com/Tpj-root/ImageMagickBasic", 200, 950, "Green", 40);
    DrawText(img, "version 0.1", 200, 1000, "Green", 40);

    DrawText(img, "Copyright Notice", 200, 1050, "red", 20);
    DrawText(img, "Image Size: 1800 x 1200 pixels (6 x 4 inches at 300 DPI)", 200, 1070, "red", 20);
    DrawText(img, "This image was generated using proprietary C++ software", 200, 1090, "red", 20);
    DrawText(img, "developed by Hackerspace Trichy.", 200, 1110, "red", 20);
    DrawText(img, "Copyright (c) Hackerspace Trichy. All Rights Reserved.", 200, 1130, "red", 20);
    DrawText(img, "Unauthorized printing, copying, reproduction, modification,", 200, 1150, "red", 20);
    DrawText(img, "redistribution, or commercial use is strictly prohibited", 200, 1170, "red", 20);
    DrawText(img, "without prior written permission.", 200, 1190, "red", 20);    


    DrawQRCode(img,"qrcode.png",1500,900,180);


    DrawRandomPixels(img, 1000);        // 1000 random 1x1 pixels
    DrawRandomPixels(img, 500, 2);      // 500 random 2x2 pixels
    DrawRandomPixels(img, 250, 3);      // 250 random 3x3 pixels
    DrawRandomPixels(img, 100, 4);      // 100 random 4x4 pixels
    DrawRandomPixels(img, 20, 8);      // 100 random 4x4 pixels
    DrawRandomPixels(img, 10, 16);      // 100 random 4x4 pixels
    // DrawRandomPixels(img, 5, 32);      // 100 random 4x4 pixels
    // DrawRandomPixels(img, 4, 64);      // 100 random 4x4 pixels
    // DrawRandomPixels(img, 3, 128);      // 100 random 4x4 pixels
    // DrawRandomPixels(img, 2, 256);      // 100 random 4x4 pixels
    // DrawRandomPixels(img, 1, 512);      // 100 random 4x4 pixels
    

    img.write("ruler.png");

    // img.fillColor("black");
    // img.strokeColor("black");
    // img.fontPointsize(16);
    // DrawCopyrightNotice(img);
}




