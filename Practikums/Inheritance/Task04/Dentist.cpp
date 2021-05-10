#include "Dentist.h"
#include <iostream>

Dentist::Dentist(std::string _name) : Doctor(_name)
{
}
void Dentist::performOperation()
{
    Doctor::performOperation();
    std::cout << "Dentist" << std::endl;
}