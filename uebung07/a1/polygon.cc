#include "polygon.hh"
#include "point.hh"
#include <iostream>
#include <cmath>
const double pi = M_PI;


Polygon::Polygon()
    : _num_corners(0)
    {
        _corners = std::vector<Point>();
    }

Polygon::Polygon(const std::vector<Point>& corners)
    : _num_corners(corners.size())
    {
        _corners = corners;
    }


Polygon::Polygon(const std::vector<double>& x, 
                 const std::vector<double>& y)
    : _num_corners(x.size())
    {
        std::vector<Point> corners;
        for(int i = 0; i < _num_corners; ++i)
        {
            corners.push_back(Point(x[i], y[i]));
        }
        _corners = corners;
    }


void Polygon::print()
{
    std::cout << _num_corners << " Corners, Area " << area() << " [";
    for(int i = 0; i < _num_corners; ++i)
    {
        std::cout << "( " << _corners[i].x() 
                  << ", " << _corners[i].y() << ")";
        if(i + 1 < _num_corners) 
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

std::size_t Polygon::corners() const
{
    return _num_corners;
}

const Point& Polygon::corner(std::size_t i) const
{
    return _corners[i];
}

double Polygon::area() const
{
    return double(_num_corners) / 2.0 * std::sin(2 * pi / double(_num_corners));
}

/*
Polygon(const std::vector<Point>& corners)
    : _Points(corners)
{}
*/
