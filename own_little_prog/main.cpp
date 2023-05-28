// #include "little_helper.h"

#include <iostream>

int main()
{
  // type_hoi();
  
  unsigned number
  { 1 };
  
  while (number)
  {
    ++number;
    
    if (number % 100000 == 0)
    { std::cout << number << std::endl; }
  }
}
