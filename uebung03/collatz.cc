#include <cmath>
#include <iostream>

void collatz(int zahl){ 
    while(zahl != 1 && zahl != 0 && zahl != -1 && zahl != -5 && zahl != -17){
        std::cout << zahl << std::endl;
        if(zahl%2 == 0){
            zahl = zahl/2;
        } else {
            zahl = (zahl * 3) + 1;
        }
    }
    std::cout << zahl << " stopped." << std::endl;   
}

int main(int argc, char** argv)
{
    double a; 
    std::cout << "Please enter a number for Collatz: " << std::flush; 
    std::cin >> a;

    collatz(a);
}

