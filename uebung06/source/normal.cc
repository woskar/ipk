// IPK Blatt 6 Aufgabe 1a)

#include <iostream>
#include "io.hh"
#include "statistics.hh"

int main(int argc, char** argv)
{
    std::cout << "Please provide int seed, int N, double avg, double std_dev" << std::endl;
    std::vector<double> vector = read_vector();
    std::cout << "Please provide integer for k-th moment" << std::endl;
    int k = read_k();
    std::vector<double> normal = normal_distribution(int(vector[0]), int(vector[1]), vector[2], vector[3]);
    print_vector(normal);
    stats_vector(vector, k);
}