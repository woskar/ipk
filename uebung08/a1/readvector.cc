#include <iostream>
#include <vector>
#include "io.hh"
#include "statistics.hh"

int main()
{
  std::vector<double> v = read_vector();
  statistics(v);
}
