#include "MyString.h"
#include "Vehicle.h"
#include <iostream>
#include <cstring>

int main()
{
   Vehicle car("VARNA", "dark opel", 5);
   
   std::cout << car.registration() << std::endl;
   std::cout << car.description() << std::endl;
   std::cout << car.space() << std::endl;
}