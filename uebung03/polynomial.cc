#include <cmath>
#include <iostream>

int main(int argc, char** argv)
{
    double a; 
    std::cout << "a = " << std::flush; 
    std::cin >> a;

    double b;
    std::cout << "b = " << std::flush;
    std::cin >> b;

    double c;
    std::cout << "c = " << std::flush;
    std::cin >> c;

    if(a == 0 && b == 0){
        std::cout << "Keine eindeutige Lösung, a und b sind 0." << std::endl;
    }
    else if(a == 0){
        std::cout << "Keine eindeutige Lösung, a darf nicht 0 sein." << std::endl;
    }
    else if((b*b - 4*a*c) < 0 ){
        std::cout << "Lösung imaginär, bitte andere Eingabe wählen." << std::endl;
    }
    else{
        double r1 = (-1 * b + std::sqrt(b*b - 4*a*c)) / 2*a;
        double r2 = (-1 * b - std::sqrt(b*b - 4*a*c)) / 2*a;
        std::cout << "Die Lösungen sind " << r1 << " und " << r2 << "." << std::endl;
    }

}