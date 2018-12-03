#include <cmath>
#include <iostream>

int fib(int zahl){
    if(zahl == 2){
        return 1;
    }
    else if(zahl <= 1){
        return 0;
    } else { 
        return fib(zahl - 1) + fib(zahl - 2);
    }
}

void fibN(int N){
    for(int i=1; i<=N; ++i){
        std::cout << "fib(" << i << "): " << fib(i) << std::endl;
    }
}

void fibBigN(int N){
    long double fib = 0;
    long double fib1 = 0;
    long double fib2 = 1;
    std::cout << "fib(1): 0" << std::endl;
    std::cout << "fib(2): 1" << std::endl;
    for(int i = 3; i <= N; ++i){
        fib = fib1 + fib2;
        std::cout << "fib(" << i << "): " << fib << std::endl;
        fib1 = fib2;
        fib2 = fib;
    }
}

int main(int argc, char** argv)
{
    double N; 
    std::cout << "Please enter a number for Fibonacci: " << std::flush; 
    std::cin >> N;

    fibBigN(N);
}

