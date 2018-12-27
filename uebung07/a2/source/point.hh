#ifndef POINT_HH
#define POINT_HH

class Point {
    double _x; 
    double _y;

public:

    Point();
    Point(double x, double y);

    double x() const;
    double y() const;

    void scale(double factor);

    void print();

    //std::ostream& Point::operator<<(std::ostream &os, Point const &m);
};

#endif // POINT_HH