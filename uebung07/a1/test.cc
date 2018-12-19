#include <iostream>
#include <ostream>
#include <cmath>
#include "point.hh"
#include "polygon.hh"

const double pi = M_PI;

int main(int argc, char** arcv)
{
    Point p1 = Point();
    p1.print();

    Point p2 = Point(1,1);
    p2.print();
    p2.scale(3);
    p2.print();

    Polygon pg1 = Polygon();
    pg1.print();

    std::vector<Point> points = {p1, p2};
    Polygon pg2 = Polygon(points);
    pg2.print();

    std::vector<double> x = {1,2,3,4,5};
    std::vector<double> y = {1,2,3,4,5};
    Polygon pg3 = Polygon(x,y);
    pg3.print();

    for(int i = 0; i <= 10; ++i)
    {
        std::vector<double> xs;
        std::vector<double> ys;

        for(int j = 0; j < i; ++j)
        {
            xs.push_back(std::cos(2 * pi * double(j) / double(i)));
            ys.push_back(std::sin(2 * pi * double(j) / double(i)));
        }
        Polygon pg = Polygon(xs,ys);
        pg.print();
    }

        

    std::cout << "success" << std::endl;
}