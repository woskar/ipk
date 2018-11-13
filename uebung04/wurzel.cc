#include <iostream>
#include <iomanip>

namespace power{
    
    double iterative(double q, int n){
        double result = q;
        for(int i = 1; i < n; i++){
            result *= q;
        }
        return result;
    }

    int recursive(int q, int n){
        if(n == 0){
            return 1;
        } else {
            return q * recursive(q, n-1);
        }
    }
}

double root_iterative(double q, int n, int steps){
    std::cout << "Starting root calculation..." << std::endl;
    std::cout << "a0: 1" << std::endl;
    double a = 1; 
    for(int i = 1; i < steps; i++){
        a += (1.0/n) * ((q/power::iterative(a, n-1)) - a);
        std::cout << "a" << i << ": " << a << std::endl;
    }
    return a; 
}


bool isNumber(std::string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
    return true; 
} 


void test_root(double q, int n, int steps){
    double approximation = root_iterative(q,n,steps);
    double potenz = power::iterative(approximation, n);
    std::cout << std::endl;
    std::cout << "Testing root function:" << std::endl;
    std::cout << "q:                 " << q << std::endl;
    std::cout << "n:                 " << n << std::endl;
    std::cout << "approximation:     " << approximation << std::endl;
    std::cout << "approximation^n:   " << potenz << std::endl;
    std::cout << "difference q-a^n:  " << q - potenz << std::endl;

}


int main(int argc, char** argv){
    if(argc < 4){
        std::cout << "Not enough arguments given. Please provide q, n and steps." << std::endl;
        return 0;   
    } else if(argc > 4){
        std::cout << "Too many arguments given. Please provide only q, n and steps." << std::endl;
        return 0; 
    } else if(not isNumber(argv[2]) or not isNumber(argv[3])){
        std::cout << "The numbers n and steps have to be integers >= 0." << std::endl;
        return 0;
    } else if(atoi(argv[2]) < 0 or atoi(argv[3]) < 0){
        std::cout << "The numbers n and steps have to be non-negative." << std::endl;
        return 0;
    } else { 
        double q = std::stod(argv[1]);
        int n = std::atoi(argv[2]);
        int steps = std::atoi(argv[3]);

        std::cout << "Calculating the " << n << "th root of " << q << " in " << n << " steps:" << std::endl;
        std::cout << std::setprecision(30) << root_iterative(q, n, steps) << std::endl;
        test_root(q,n,steps);
    }




}