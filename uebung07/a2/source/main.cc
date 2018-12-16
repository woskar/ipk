#include <iostream>
#include <cmath>
#include "point.hh"
#include "canvas.hh"

const double pi = M_PI;

int main(int argc, char** arcv)
{
    Point p = Point(0,0);
    Canvas c = Canvas(p, 10, 10, 10, 10);
    p.print();
    std::cout << "success" << std::endl;
}

