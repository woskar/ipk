#include <iostream>
#include <cmath>
#include <algorithm>
#include "point.hh"
#include "canvas.hh"
#include "pgm.hh"

const double pi = M_PI;

int main()
{
    double x_center = 0;
    double y_center = 0;

    double width = 3; 
    double height = 2;
    int horPixels = 3000;
    int vertPixels = 2000;

    Point p = Point(x_center, y_center);
    Canvas c = Canvas(p, width, height, horPixels, vertPixels);

    for(int i = 0; i < horPixels; i++)
    {
        for(int j = 0; j < vertPixels; j++)
        {
            Point p1 = c.coord(i, j);
            c.setBrightness(i, j, 
                std::max(0, int(100*(std::sin(1/p1.x()) * 
                                 std::sin(1/p1.y()) + 1)))
                );
        }
    }
    c.write("result.pgm");
}