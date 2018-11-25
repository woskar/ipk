// IPK Blatt 5 
// Aufgabe 1

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

std::pair<double, double> minMax(std::vector<double> & vec)
{
    if(vec.size() == 0){
        std::cout << "Size of given vector is zero, there are no elements." << std::endl;
        return std::make_pair(NULL, NULL);
    }

    double min = vec[0];
    double max = vec[0];

    for(int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] < min){min = vec[i];};
        if (vec[i] > max){max = vec[i];};
    }
    return std::make_pair(min, max);
}

std::vector<double> reversed(std::vector<double> & v)
{
    std::vector<double> result(v.size());
    for(int i = 0; i < v.size(); ++i)
    {
        result[v.size()-i] = v[i];
    }
    return result;
}

void print(std::vector<double> &v)
{
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
}

void round(std::vector<double> & v)
{
    for (double& value : v)
    {
        value = std::round(value);
    }
}

void swap(std::vector<double> & v)
{
    if(v.empty() or v.size()==1){return;}

    for(int i = 0; i < int(floor((v.size()-1)/2)); i++)
    {
        std::swap(v[i],v[v.size()-1-i]);
    }
}

int main(int argc, char** argv)
{
    // a) Werte ohne explizite Zuweisung werden mit 0 initialisiert

    std::vector<double> v1; 
    std::vector<double> v2(7); 
    std::vector<double> v3 = {{3.141, 2.718, 1, 2, 3, 4, 5}};


    // a) Vektoren ausgeben
    std::cout << "a) Vektoren ausgeben" << std::endl;

    std::cout << "Elemente von v1:" << std::endl;
    for(int i = 0; i < v1.size(); ++i)
    {
        std::cout << v1[i] << std::endl;
    }

    std::cout << "Elemente von v2:" << std::endl;
    for(int i = 0; i < v2.size(); ++i)
    {
        std::cout << v2[i] << std::endl;
    }

    std::cout << "Elemente von v1:" << std::endl;
    for(int i = 0; i < v3.size(); ++i)
    {
        std::cout << v3[i] << std::endl;
    }

    // b) Funktion, die größten und kleinsten Wert als std::pair zurückgibt
    std::cout << "b) Min-Max-Pair" << std::endl;

    std::pair<double, double> p1 = minMax(v1);
    std::cout << "v1: (" << p1.first << ", " << p1.second << ")" << std::endl;

    std::pair<double, double> p2 = minMax(v2);
    std::cout << "v2: (" << p2.first << ", " << p2.second << ")" << std::endl;

    std::pair<double, double> p3 = minMax(v3);
    std::cout << "v3: (" << p3.first << ", " << p3.second << ")" << std::endl;

    // c) Umgekehrten Vektor ausgeben
    std::cout << "c) Reversed Vector" << std::endl;
    
    std::vector<double> r1 = reversed(v1);
    std::vector<double> r2 = reversed(v2);
    std::vector<double> r3 = reversed(v3);
    
    print(r1);
    print(r2);
    print(r3);

    // d) Vektor runden
    std::cout << "d) Vektor runden" << std::endl;
    round(v1);
    round(v2);
    round(v3);

    print(v1);
    print(v2);
    print(v3);

    // e) Swappen 
    std::cout << "e) Swappen ohne Kopieren" << std::endl;
    swap(v1);
    swap(v2);
    swap(v3);

    print(v1);
    print(v2);
    print(v3);

}