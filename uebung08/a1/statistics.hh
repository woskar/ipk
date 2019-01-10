#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <vector>
#include <algorithm>

template<typename T>
typename T::value_type mean(const T& v) // so wär's richtig, der ganze vector ist T!!
{
  //? typename T::value_type sum = 0;
  T sum = 0;
  for (auto e : v)
    sum += e;

  return sum / v.size();
}

template<typename T>
T median(const std::vector<T>& v)
{
  auto v2(v);
  std::sort(v2.begin(),v2.end());

  auto v3(v.size(), T);
  for(int i = 0; i < v.size(); ++i)
  {
    v3.push_back()
  }


  if (v.size() % 2 == 0)
    {
      return 0.5 * (v2[v.size()/2 - 1] + v2[v.size()/2]);
    }
  else
    {
      return v2[(v.size()+1)/2 - 1];
    }
}

template<typename T>
T moment(const std::vector<T>& v, int k)
{
  T sum = 0;
  for (auto e : v)
    sum += std::pow(e,k);

  return sum / v.size();
}

template<typename T>
T std_dev(const std::vector<T>& v)
{
  T m = mean(v);
  T sum = 0;
  for (auto e : v)
    sum += (m - e)*(m - e);

  return std::sqrt(sum / v.size());
}

template<typename T>
void statistics(const std::vector<T>& v)
{
  std::cout << "mean: " << mean(v) << std::endl;
  std::cout << "median: " << median(v) << std::endl;
  std::cout << "second moment: " << moment(v,2) << std::endl;
  std::cout << "std_dev: " << std_dev(v) << std::endl;
}


#endif // STATISTICS_HH
