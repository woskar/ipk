#ifndef IO_HH
#define IO_HH

#include <vector>
#include <random>
#include <string>

// reads numbers from stdin, one number per line until it detects an empty line
// returns all read numbers in a vector

std::vector<double> read_vector();
/*
template<template T>
std::vector<T> read_vector()
{
  std::vector<T> result;
  try
    {
      for (std::string line ; std::getline(std::cin,line) ; )
        result.push_back(std::stod(line));
    } catch (std::invalid_argument&)
    {}
  return result;
}
*/

// generates N uniformly distributed numbers between min and max.
// seed is an arbitrary number that initializes the random number generator. Using the
// same number always creates the same output. If you want to have different results each
// time, use random_seed() to generate seed.
template<typename T>
std::vector<T> uniform_distribution(int seed, int N, T min, T max)
{
  std::mt19937_64 rng(seed);
  std::uniform_real_distribution<> dist(min,max);
  std::vector<T> result(N);
  for (T& x : result)
    x = dist(rng);
  return result;
}

// generates N normally distributed numbers with given average and standard deviation.
// seed is an arbitrary number that initializes the random number generator. Using the
// same number always creates the same output. If you want to have different results each
// time, use random_seed() to generate seed.
template<typename T>
std::vector<T> normal_distribution(int seed, int N, T avg, T std_dev)
{
  std::mt19937_64 rng(seed);
  std::normal_distribution<> dist(avg,std_dev);
  std::vector<T> result(N);
  for (T& x : result)
    x = dist(rng);
  return result;
}

// returns a random seed (different on each call)
int random_seed();

#endif // IO_HH
