#include "ruler.hpp"

#include <Magick++.h>

using namespace Magick;

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

    const double px_per_mm = 300.0 / 25.4;

    //---------------------------------------------------
    // Draw horizontal ruler
    //---------------------------------------------------

    for(int mm=0; mm<=152; mm++)
    {
        double x = mm * px_per_mm;

        int len = 10;

        if(mm % 10 == 0)
            len = 60;
        else if(mm % 5 == 0)
            len = 35;

        img.draw(
            DrawableLine(
                x,
                0,
                x,
                len
            )
        );
    }

    //---------------------------------------------------
    // Draw vertical ruler
    //---------------------------------------------------

    for(int mm=0; mm<=102; mm++)
    {
        double y = mm * px_per_mm;

        int len = 10;

        if(mm % 10 == 0)
            len = 60;
        else if(mm % 5 == 0)
            len = 35;

        img.draw(
            DrawableLine(
                0,
                y,
                len,
                y
            )
        );
    }

    img.write("output/ruler.png");
}
