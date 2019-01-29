#include <iostream>
#include <cmath>

#include "pgm.hh"
#include "point.hh"
#include "canvas.hh"
#include "iterationresult.hh"

IterationResult iterate(Point z, Point c, double threshold, int maxIt)
{
  int i = 0;
  while(i < maxIt and (z.x()*z.x() + z.y()*z.y() < threshold*threshold))
  {
    z = Point(z.x()*z.x() - z.y() * z.y() + c.x(),
              2 * z.x() * z.y() + c.y()
      );
    ++i;
  }
  return {i,z};
}

void mandelbrot (Canvas& canvas, double threshold,int maxIt, std::string filename)
{
  for (int i = 0 ; i < canvas.horPixels() ; ++i)
    for (int j = 0 ; j < canvas.vertPixels() ; ++j)
    {
      auto result = iterate({},canvas.coord(i,j),threshold,maxIt);
      if (result.iterations() == maxIt)
        canvas(i,j) = 0;
      else {
        canvas(i,j) = std::log(result.iterations()) * 100.0;
      }
    }
  canvas.write(filename);
}


void julia (Point c, Canvas& canvas, double threshold,int maxIt, std::string filename)
{
  for (int i = 0 ; i < canvas.horPixels() ; ++i)
    for (int j = 0 ; j < canvas.vertPixels() ; ++j)
    {
      auto result = iterate(canvas.coord(i,j),c,threshold,maxIt);
      if (result.iterations() == maxIt)
        canvas(i,j) = 0;
      else {
        canvas(i,j) = std::log(result.iterations()) * 100.0;
      }
    }
  canvas.write(filename);
}


int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " [mandelbrot/julia]" << std::endl;
    return 1;
  }
    using namespace std::literals;
  if ("mandelbrot"s == argv[1])
  {
    Canvas canvas({-1,0},4,3,2400,1800);
    mandelbrot(canvas,1000,1000,"mandelbrot.pgm");
  } else if ("julia"s == argv[1])
  {
    Point c{-.8,.156};
    Canvas canvas(c,.04,.03,2400,1800);
    julia(c,canvas,1000,1000,"julia.pgm");
  }
  return 0;
}
