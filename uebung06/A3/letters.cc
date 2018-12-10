// IPK Blatt 6 Aufgabe 3

#include <iostream>
#include <map>
#include "sanitizeword.hh"


// Aufgabe 3: Häufigkeit von Buchstaben
std::pair<std::map<char, int>, unsigned int> get_frequencies()
{
    unsigned int count = 0;
    std::map<char, int> dictionary;
    while (true)
    {

        unsigned char c;
        // read in character
        std::cin >> c;
        // abort if input closed
        if (not std::cin)
        break;
        // work with c
        c = std::toupper(c);
        if(std::isalpha(c))
        {
            dictionary[c] += 1;
            count++;
        }
        else 
        {
            continue;
        }
        
    }
    std::cout << "Total of " << count << " letters included." << std::endl;
    return std::make_pair(dictionary, count);
}


// Aufgabe 4: Häufigkeit von Wörtern
std::map<std::string,int> get_word_frequencies()
{
    unsigned int count = 0;
    std::map<std::string, int> dictionary;
    while (true)
    {
        std::string s;
        // read in character
        std::cin >> s;
        // abort if input closed
        if (not std::cin)
        break;
        // work with c
        //s = sanitize_word(s);
        if(s.size() > 0)
        {
            dictionary[s] += 1;
            count++;
        }
        else 
        {
            continue;
        }
        
    }
    std::cout << "Total of " << count << " letters included." << std::endl;
    return dictionary;
}


void print_frequencies(const std::pair<std::map<char, int>, unsigned int>& frequencies)
{
    for (const std::pair<char,int>& entry : frequencies.first)
    {
        std::cout << entry.first << ": " << static_cast<double>(entry.second)/frequencies.second << std::endl;
    }
}

void print_word_frequencies(const std::map<std::string, int>& frequencies)
{
    for (const std::pair<std::string, int>& entry : frequencies)
    {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}

void wordfrequencies(const std::map<std::string,int>& dict)
{
    unsigned int count = 0;
    for (const std::pair<std::string,int>& entry : dict)
    {
        count += entry.second;
    }
    std::cout << "Now printing the word-frequencies:" << std::endl;
    for (const std::pair<std::string,int>& entry : dict)
    {
        std::cout << entry.first << ": " << static_cast<double>(entry.second)/count << std::endl;
    }
}

int main(int argc, char** argv)
{
    std::cout << "Please provide letters, end with ctrl+D" << std::endl;
    
    std::pair<std::map<char, int>, unsigned int> dict = get_frequencies();
    std::cout << "Dictionary with frequencies created, it looks like this:" << std::endl;
    print_frequencies(dict);
    
    //std::map<std::string, int> dict = get_word_frequencies();
    //print_word_frequencies(dict);
    //wordfrequencies(dict);

}