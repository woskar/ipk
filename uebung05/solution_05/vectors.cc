#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
#include <cmath>
#include <iostream>

std::pair<double,double> minmax1(const std::vector<double>& v)
{
  if (v.size() == 0)
    return {0.,0.};

  double min = v[0];
  double max = v[0];

  for (std::size_t i = 1 ; i < v.size() ; ++i)
    {
      if (min > v[i])
        min = v[i];
      if (max < v[i])
        max = v[i];
    }

  return {min,max};
}


std::pair<double,double> minmax2(const std::vector<double>& v)
{
  double min = +std::numeric_limits<double>::infinity();
  double max = -std::numeric_limits<double>::infinity();

  for (auto& value : v)
    {
      min = std::min(min,value);
      max = std::max(max,value);
    }

  return {min,max};
}



std::vector<double> reversed(const std::vector<double>& v)
{
  std::vector<double> out(v.size());

  for (std::size_t i = 0 ; i < v.size() ; ++i)
    out[v.size() - i - 1] = v[i];

  return out;
}


void round(std::vector<double>& v)
{
  for (auto& entry : v)
    {
      entry = std::round(entry);
    }
}


void reverse(std::vector<double>& v)
{
  for (std::size_t i = 0 ; i < v.size() / 2 ; ++i)
    std::swap(v[i],v[v.size() - 1 - i]);
}

void print(const std::vector<double>& v)
{
  for (auto& entry : v)
    std::cout << entry << " ";
  std::cout << std::endl;
}

int main()
{
  std::vector<double> v = {{ 7.2,11.3,16.6,12.4 }};
  print(v);
  auto r = minmax2(v);
  std::cout << r.first << " " << r.second << std::endl;
  auto v2 = reversed(v);
  print(v2);
  round(v2);
  print(v2);
  reverse(v);
  print(v);
}
