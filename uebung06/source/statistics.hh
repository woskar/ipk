#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <vector>

// returns mean of all entries of given vector
double mean(const std::vector<double>& v);

// returns median of given vector
double median(const std::vector<double>& v);

// output statistics to console
void stats_vector(std::vector<double>& v, int k);

// return k-th statistic moment of vector elements
double moment(const std::vector<double>& v, int k);

// calculate std deviation of vector
double standard_deviation(const std::vector<double>& v);

#endif // STATISTICS_HH