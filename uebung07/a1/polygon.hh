#ifndef POLYGON_HH
#define POLYGON_HH

#include <vector>
#include "point.hh"

class Polygon {
private:
    std::vector<Point> _corners;
    unsigned int _num_corners; 

protected:
    const Point& corner(int i) const;

public: 
    // Konstruktoren
    Polygon();

    Polygon(const std::vector<Point>& corners);
    
    Polygon(const std::vector<double>& x,
            const std::vector<double>& y);

    // Methoden
    std::size_t corners() const;

    const Point& corner(std::size_t i) const;

    double area() const;

    void print();

};


#endif // POLYGON_HH