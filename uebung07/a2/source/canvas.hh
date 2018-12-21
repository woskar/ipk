#ifndef CANVAS_HH
#define CANVAS_HH

#include <vector>
#include "point.hh"
#include "pgm.hh"

class Canvas {
    
    const Point _center;
    const double _width;
    const double _height;
    const int _horPixels; 
    const int _vertPixels;

    std::vector<std::vector<int> > _pixels;

public:

    Canvas(const Point& center, double width, double height,
           int horPixels, int vertPixels);

    const std::vector<std::vector<int> >& pixels();

    int brightness(int i, int j) const;

    void setBrightness(int i, int j, int brightness);

    Point coord(int i, int j) const;

    void write(const std::string& filename);
    
};

#endif // CANVAS_HH