#include <iostream>

template<typename T>
void swap(T& t1, T& t2)
{
  T t3 = t1;
  t1 = t2; 
  t2 = t3; 
}

int main(int argc, char** argv)
{
  int a = 1; 
  int b = 2; 
  std::cout << "a = " << a << " b = " << b << std::endl;
  swap(a, b);
  std::cout << "a = " << a << " b = " << b << std::endl;

  double c = 3; 
  double d = 4;
  std::cout << "c = " << c << " d = " << d << std::endl;
  swap(c, d);
  std::cout << "c = " << c << " d = " << d << std::endl;

  // Code soll mit folgender Zeile nicht mehr kompilieren
  // swap(a, c);

  return 0;
}