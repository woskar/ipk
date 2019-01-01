#include <iostream>
#include <string>
#include <random>

#include "io.hh"

int random_seed()
{
  std::random_device rng;
  return rng();
}

std::vector<double> read_vector()
{
  std::vector<double> result;
  try
    {
      for (std::string line ; std::getline(std::cin,line) ; )
        result.push_back(std::stod(line));
    } catch (std::invalid_argument&)
    {}
  return result;
}
