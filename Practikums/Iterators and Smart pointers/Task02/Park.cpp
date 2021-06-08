#include "Park.h"
#include <iostream>

Park::Park(const std::string& name)
{
    this->name = name;
}

std::string Park::getName() const
{
    return this->name;
}
