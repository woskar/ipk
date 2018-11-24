// IPK Blatt 5 
// Aufgabe 2

#include <iostream>


// Teil a) bis c) 
int number(std::string s)
{
    int number = 0; 
    int sign = 1; 
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i]==' '){continue;}
        else if(s[i]=='+'){continue;}
        else if(s[i]=='-'){sign = -1;}
        else if(s[i] < '0' or s[i] > '9'){break;}
        else
        {
            number = (number * 10) + (s[i] - '0');
        }
    }
    return number *= sign;
}

std::pair<int, int> pair(std::string s)
{
    int number = 0; 
    int sign = 1; 
    int last;
    for(int i = 0; i < s.size(); ++i)
    {
        last = i;
        if(s[i]==' '){continue;}
        else if(s[i]=='+'){continue;}
        else if(s[i]=='-'){sign = -1;}
        else if(s[i] < '0' or s[i] > '9'){break;}
        else
        {
            number = (number * 10) + (s[i] - '0');
        }
    }
    number *= sign;
    return std::make_pair(number, last); 
}

std::pair<int, int> exception(std::string s)
{
    int number = 0; 
    int sign = 1; 
    int last;
    for(int i = 0; i < s.size(); ++i)
    {
        last = i;
        if(s[i]==' '){continue;}
        else if(s[i]=='+'){continue;}
        else if(s[i]=='-'){sign = -1;}
        else if(s[i] < '0' or s[i] > '9'){
            throw std::invalid_argument("Invalid syntax.");
            break;
        }
        else
        {
            number = (number * 10) + (s[i] - '0');
        }
    }
    number *= sign;
    return std::make_pair(number, last); 
}

int main(int argc, char** argv)
{
    std::cout << "Please insert a number: " << std::endl;
    std::string s;
    std::getline(std::cin, s);

    std::cout << "Your number is " << number(s) << std::endl;
    std::cout << "The square is " << number(s) * number(s) << std::endl;
    std::cout << "The pair function generates " << pair(s).first
              << " " << pair(s).second << std::endl;
    std::cout << "Trying exception function: " << exception(s).first
              << " " << exception(s).second << std::endl;
}




    /* example
    std::string s = "47218";
    std::getline(std::cin,s);
    int size = s.size();
    char c = s[0];
    char d = s[size-1];
    std::cout << size << c << d << std::endl;

    char three = '3';
    std::cout << three << std::endl; // Ausgabe: 51
    three = three - '0'; // alternativ: three - 48
    std::cout << three << std::endl; // Ausgabe: 3
    */