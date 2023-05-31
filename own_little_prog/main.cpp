#include "little_helper.h"

#include <iostream>

void type_what()
{
  std::cout << "What?!" << std::endl;
  
  const int count_max
  { 1000000000 };
  
  for (int count{ 0 }; count < count_max; ++count)
  {}
}

int main()
{
  type_hoi();
  
  type_what();
}
