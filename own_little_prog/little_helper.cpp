#include "little_helper.h"

#include <iostream>
#include <cmath>

void type_what()
{
  std::cout << "What?!" << std::endl;
  
  const int count_max
  { 1000000000 };
  
  for (int count{ 0 }; count < count_max; ++count)
  {}
}

void type_what(const double output)
{
  std::cout << output << std::endl;
  
  const int count_max
  { 1000000000 };
  
  for (int count{ 0 }; count < count_max; ++count)
  {}
}

double powering(const double base, const double power)
{ return std::pow(base, power); }
  
  
