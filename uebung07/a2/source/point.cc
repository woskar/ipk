#include "point.hh"
#include <iostream>

// Default Konstruktor
Point::Point(): _x(0), _y(0){}

// Konstruktor
Point::Point(double x, double y)
    : _x(x), _y(y)
{}

double Point::x() const {
    return _x;
}

double Point::y() const {
    return _y;
}

void Point::scale(double factor) {
    _x *= factor;
    _y *= factor; 
}

void Point::print()
{
    std::cout << "( " << _x << ", " << _y << ")" << std::endl;
}

