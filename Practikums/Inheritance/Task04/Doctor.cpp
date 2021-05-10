#include "Doctor.h"
#include <iostream>

Doctor::Doctor (std::string _name)
{
    this->name = _name;
}
void Doctor::performOperation()
{
    std::cout << "Operation performed by " << this->name << std::endl;
}