#undef NDEBUG
#include <cassert>
#include "statistics.hh"

int main()
{
  std::vector<double> e;
  std::vector<double> v = {{1,1,1,1,1}};
  std::vector<double> w = {{2,2,2,2}};
  
  assert(mean(e) == 0);
  assert(mean(v) == 1);
  assert(mean(w) == 2);
}
