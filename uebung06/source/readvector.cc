// IPK Blatt 6 Aufgabe 1a)

#include <iostream>
#include "io.hh"
#include "statistics.hh"


int main(int argc, char** argv)
{
    std::cout << "Please provide vector" << std::endl;
    std::vector<double> vector = read_vector();
    std::cout << "Please provide integer for k-th moment" << std::endl;
    int k = read_k();
    print_vector(vector);
    stats_vector(vector, k);
}