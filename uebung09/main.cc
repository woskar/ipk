#include <iostream>
#include <cmath>
#include "pgm.hh"
#include "canvas.hh"
#include "point.hh"
#include "iterationresult.hh"

double distance(Point p1, Point p2)
{ 
  return std::sqrt( ( (p2.x()-p1.x())*(p2.x()-p1.x()) ) + ( (p2.y()-p1.y())*(p2.y()-p1.y())));
  
  //nur mal test, keine Veränderung
  //return p1.x()+p1.y()+p2.x()+p2.y();
}

IterationResult iterate (Point z, Point c, double threshold, int maxIt)
{
  Point old = z;
  Point result = z;
  int iterations = 0;
  // Solange x^2 + y^2 < z^2 und weniger als maximal erlaubte Iterationen
  while(distance(z, result) < threshold and iterations < maxIt)
  {
    old = result;
    //Rekursionsvorschrift
    result.setX( (old.x() * old.x()) - (old.y() * old.y()) + c.x());
    result.setY(2 * old.x() * old.y() + c.y());
    iterations++;
    //std::cout << result.x() << " " << result.y() << std::endl;
  }
  return IterationResult(result, iterations);
}

double continuous(IterationResult r, double t)
{
  int k = r.iterations();
  Point z = r.point();
  return k - std::log2(std::log(std::sqrt(z.x()*z.x() + z.y()*z.y())) / std::log(t) );
}


void mandelbrot (Canvas& canvas, double threshold, 
  int maxIt, std::string filename, bool smooth = false)
{
  for (int j = 0; j < canvas.vertPixels(); ++j)
  {
    for (int i = 0; i < canvas.horPixels(); ++i)
    {
      IterationResult res = iterate(Point(), canvas.coord(i,j), threshold, maxIt);

      if(res.iterations() >= maxIt and distance(Point(i,j), Point()) <= threshold)
      {
        //std::cout << "beschränkt" << std::endl;
        canvas(i, j) = 0;
      }
      else 
      {
        //std::cout << "unbeschränkt" << std::endl;
        if(smooth) {
          canvas(i, j) = std::log(continuous(res, threshold)) * 100;
        } else {
          canvas(i, j) = std::log(res.iterations()) * 100;
        }
      }
    }
  }
  canvas.write(filename);
}

void julia (Point c, Canvas& canvas, double threshold, 
  int maxIt, std::string filename, bool smooth = false)
{
  for (int j = 0; j < canvas.vertPixels(); ++j)
  {
    for (int i = 0; i < canvas.horPixels(); ++i)
    {
      IterationResult res = iterate(canvas.coord(i,j), c, threshold, maxIt);

      if(res.iterations() >= maxIt and distance(c, Point(i,j)) <= threshold)
      {
        //std::cout << "beschränkt" << std::endl;
        canvas(i, j) = 0;
      }
      else 
      {
        //std::cout << "unbeschränkt" << std::endl;
        //canvas(i, j) = std::log(res.iterations()) * 100;
        if(smooth) {
          canvas(i, j) = continuous(res, threshold);
        } else {
          canvas(i, j) = std::log(res.iterations()) * 100;
        }
      }
    }
  }
  canvas.write(filename);
}


int main()
{
  int threshold = 1000;
  Canvas canvas(Point(-1,0), 4, 3, 400, 300);
  mandelbrot(canvas, threshold, 1000, "Mandelbrot.pgm", true);
  
  /*
  Point c(-0.8, 0.156);
  Canvas canvas_julia(c, 4, 3, 800, 600);
  julia(c, canvas_julia, 1000, 1000, "Julia.pgm", true);
  */

  std::cout << "Success." << std::endl;
}