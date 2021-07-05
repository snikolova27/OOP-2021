#include "Memory.h"
#include <stdexcept>

 const double Memory::PRICE_PER_GB = 89.99;

Memory::Memory(std::string label, const unsigned short capacity) : Component(label)
{
    if (capacity > 10000 || !capacity)
    {
        throw std::invalid_argument("Capacity should be less than 10 000");
    }
    else
    {
        this->capacity = capacity;
    }
}

double Memory::price() const
{
    return this->capacity * PRICE_PER_GB;
}
