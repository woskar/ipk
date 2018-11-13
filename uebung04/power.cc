#include <iostream>
#include <string.h>

namespace power{
    
    int iterative(int q, int n){
        int result = q;
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

    int advanced(int q, int n){
        int result = q; 
        int remaining_n = n;
        
        while(remaining_n > 1){
            int m = 1;
            while(m+m < remaining_n){
                result *= result;
                m += m;
            }
            while(m < remaining_n){
                result *= q;
                m++;
            }
            remaining_n -= m;
        }
        return result;
    }
}

bool isNumber(std::string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
    return true; 
} 

int main(int argc, char** argv){
    if(argc < 3){
        std::cout << "Not enough arguments given. Please provide q and n." << std::endl;
        return 0;   
    } else if(argc > 3){
        std::cout << "Too many arguments given. Please provide only q and n." << std::endl;
        return 0; 
    } else if(not isNumber(argv[1]) or not isNumber(argv[2])){
        std::cout << "The numbers q and n have to be integers with n >= 0." << std::endl;
        return 0;
    } else if(atoi(argv[2]) < 0){
        std::cout << "The numbers n has to be greater 0." << std::endl;
        return 0;
    } else {
        int q = std::atoi(argv[1]);
        int n = std::atoi(argv[2]);

        std::cout << "Calculating " << q << " to the power of " << n << ":" << std::endl;
        std::cout << "Iterative: " << power::iterative(q, n) << std::endl;
        std::cout << "Recursive: " << power::recursive(q, n) << std::endl;
        std::cout << "Advanced:  " << power::advanced(q, n) << std::endl;
    }


}



