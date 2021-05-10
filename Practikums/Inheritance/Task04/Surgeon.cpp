#include "Surgeon.h"
#include <iostream>

Surgeon::Surgeon (std::string _name) : Doctor(_name)
{

};
void Surgeon::performSurgery()
{
    Doctor::performOperation();
    std::cout << "Surgeon" << std::endl;
}