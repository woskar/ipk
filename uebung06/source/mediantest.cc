#undef NDEBUG
#include <cassert>
#include "statistics.hh"

int main()
{
  std::vector<double> e;
  std::vector<double> v = {{1,2,3,4,5}};
  std::vector<double> w = {{1,2,3,4}};
  
  assert(median(e) == 0);
  assert(median(v) == 3);
  assert(median(w) == 2.5);
}
