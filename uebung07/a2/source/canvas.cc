#include "point.hh"
#include "canvas.hh"
#include "pgm.hh"
#include <iostream>
#include <vector>

Canvas::Canvas(const Point& center, double width, double height,
               int horPixels, int vertPixels)
  : _width(width), _height(height), 
    _horPixels(horPixels), _vertPixels(vertPixels),
    _center(center), _pixels(horPixels, std::vector<int>(vertPixels, 0))
  {}

const std::vector<std::vector<int> >& Canvas::pixels()
{
  return _pixels;
}

int Canvas::brightness(int i, int j) const
{
  return _pixels.at(i).at(j);
}

void Canvas::setBrightness(int i, int j, int brightness)
{
  _pixels.at(i).at(j) = brightness;
}

Point Canvas::coord(int i, int j) const
{
  return Point( ((i * _width)/(_horPixels-1)) - _width/2 - _center.x(), 
                ((j * _height)/(_vertPixels-1)) - _height/2 - _center.y());
}

void Canvas::write(const std::string& filename)
{
  write_pgm(_pixels, filename);
}
