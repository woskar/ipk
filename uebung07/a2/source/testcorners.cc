#undef NDEBUG
#include <cassert>
#include <iostream>
#include "canvas.hh"
#include "point.hh"

int main()
{
    double x_center = 0;
    double y_center = 0;

    double width = 4; 
    double height = 3;
    int horPixels = 4000;
    int vertPixels = 3000;

    Point p = Point(x_center, y_center);
    Canvas c = Canvas(p, width, height, horPixels, vertPixels);

    // Linke untere Ecke
    Point p1 = c.coord(0, 0);
    p1.print();
    std::cout << x_center - width/2 << std::endl;
    std::cout << y_center - height/2 << std::endl;
    assert(p1.x() == x_center - width/2);
    assert(p1.y() == y_center - height/2);

    // Rechte untere Ecke
    Point p2 = c.coord(horPixels - 1, 0);
    p2.print();
    std::cout << x_center + width/2 << std::endl;
    std::cout << y_center - height/2 << std::endl;
    assert(p2.x() == x_center + width/2);
    assert(p2.y() == y_center - height/2);

    // Linke obere Ecke
    Point p3 = c.coord(0, vertPixels - 1);
    p3.print();
    assert(p3.x() == x_center - width/2);
    assert(p3.y() == y_center + height/2);

    // Rechte obere Ecke
    Point p4 = c.coord(horPixels - 1, vertPixels - 1);
    p4.print();
    assert(p4.x() == x_center + width/2);
    assert(p4.y() == y_center + height/2);
}
