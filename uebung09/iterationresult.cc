#include "iterationresult.hh"

IterationResult::IterationResult()
  : _point()
  , _iterations(0)
{}

IterationResult::IterationResult(Point p, int i)
  : _point(p.x(), p.y())
  , _iterations(i)
{}


Point IterationResult::point() const
{
  return _point;
}

int IterationResult::iterations() const
{
  return _iterations;
}
