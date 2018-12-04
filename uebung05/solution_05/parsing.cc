#include <iostream>
#include <utility>
#include <string>

std::pair<int,int> parse_int(const std::string& s)
{
  // the number we want to return
  int result = 0;
  // flag that will be true once we have encountered a number
  bool in_number = false;
  // flag that will be true once we are done parsing. Used to exit the loop
  bool done = false;
  // flag that indicates a negative number
  bool negative = false;
  // the current position in the string
  std::size_t i = 0;

  for ( ; i < s.size() ; ++i)
    {
      switch (s[i])
        {
        case ' ':
          if (in_number)
            done = true;
          break;
        case '+':
          negative = false;
          in_number = true;
          break;
        case '-':
          negative = true;
          in_number = true;
          break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          in_number = true;
          result = result * 10 + static_cast<int>((s[i] - '0'));
          break;
        default:
          done = true;
        }

      // we have encountered an invalid character, abort
      if (done)
        break;
    }

  if (in_number)
    {
      if (negative)
        result = -result;
      return {result,i};
    }
  else
    {
      //return {0,0};
      throw std::invalid_argument("Could not parse number");
    }

}


int main()
{
  std::string s;
  std::getline(std::cin,s);
  auto r = parse_int(s);
  std::cout << "Found integer: " << r.first << std::endl;
  std::cout << "Next character: " << r.second << std::endl;
}
