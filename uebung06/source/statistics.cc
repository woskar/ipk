#include <iostream>
#include <string>
#include <random>

#include "statistics.hh"
#include "io.hh"
#include "math.h"

double mean(const std::vector<double>& v)
{
    if(v.size() <= 0)
    {
        std::cout << "Caution! Empty vector! No mean! " << std::endl;
        return 0;
    }
    double sum = 0; 
    for(int i = 0; i < v.size(); ++i)
    {
        sum += v[i];
    }
    return sum/v.size();
}

double median(const std::vector<double>& v)
{
    std::vector<double> w = v;
    std::sort(w.begin(),w.end());
    int n = w.size();
    if(n <= 0)
    {
        std::cout << "Caution! Empty vector! No median! " << std::endl;
        return 0;
    }
    else if(n%2 == 1)
    {
        return w[(n-1)/2];
    }
    else
    {
        return (w[n/2] + w[(n/2)-1]) / 2;
    }
}

double moment(const std::vector<double>& v, int k)
{
    double sum = 0; 
    for(int i = 0; i < v.size(); ++i)
    {
        sum += pow(v[i], k);
    }
    return sum/v.size();
}

double standard_deviation(const std::vector<double>& v)
{
    std::vector<double> v1 = v;
    //print_vector(v1);
    std::vector<double> w(v.size(), mean(v));
    //print_vector(w);
    std::vector<double> diff(v.size());
    //print_vector(diff);
    std::transform(v1.begin(),v1.end(),w.begin(),diff.begin(),std::minus<double>());
    //print_vector(diff);
    return std::sqrt(moment(diff, 2));
}

void stats_vector(std::vector<double>& v, int k)
{
    std::cout << "Mean:     " << mean(v) << std::endl;
    std::cout << "Median:   " << median(v) << std::endl;
    std::cout << "k-Moment: " << moment(v, k) << std::endl;
    std::cout << "std-dev:  " << standard_deviation(v) << std::endl;
    std::cout << "check 0:  " << pow(standard_deviation(v), 2) - moment(v, 2) + pow(mean(v), 2) << std::endl;
}