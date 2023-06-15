#include "functions.h"

#include <iostream>

void counter()
{
  std::cout << "From which integer to another integer do you want to count?" << std::endl;
  std::cout << "Type your first integer, then press [Enter]: ";
  
  int first
  { 0 };
  
  std::cin >> first;
  
  std::cout << "Type your second integer, then press [Enter]: ";
  
  int second
  { 0 };
  
  std::cin >> second;
  
  
  if (first < second)
  {
    for (int count{ first }; count <= second; ++count)
    { std::cout << count << std::endl; }
  } else if (second < first)
  {
    std::cout << "Reached!" << std::endl;
    
    for (int count{ first }; count >= second; --count)
    { std::cout << count << std::endl; }
  } else
  { std::cout << first << std::endl; }  
}

void end_program()
{  
  std::cout << std::endl << "Type any key and then press [Enter] to end the program." << std::endl;
  
  char holder
  { ' ' };
  
  std::cin >> holder;
}
