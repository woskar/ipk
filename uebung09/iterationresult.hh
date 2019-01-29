#ifndef ITERATIONRESULT_HH
#define ITERATIONRESULT_HH

#include "point.hh"

class IterationResult
{

public:

  // default constructor
  IterationResult();

  // constructor für übergebene Koordinaten
  IterationResult(Point p, int i);

  // Accessors

  Point point() const;

  int iterations() const;

private:

  Point _point;
  int _iterations;


};

#endif // ITERATIONRESULT_HH
