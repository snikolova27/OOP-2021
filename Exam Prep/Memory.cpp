#include "Memory.h"

const double Memory::PRICE_PER_GIGABYTE = 89.99;

Memory::Memory(const unsigned short capacity)
{
    if (!capacity || capacity > 10000)
    {
        throw std::out_of_range("Capacity cannot be more than 10 000");
    }
    else
    {
        this->capacity = capacity;
        this->m_label = "memory";
        this->m_price = capacity * PRICE_PER_GIGABYTE;
        this->type = ComponentType::MEMORY;
    }
}