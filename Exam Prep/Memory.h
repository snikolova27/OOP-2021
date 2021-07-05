#ifndef MEMORY_H
#define MEMORY_H
#include "Component.h"

class Memory : public Component
{
private:
    unsigned short capacity;
    static const double PRICE_PER_GIGABYTE;

public:
    Memory(const unsigned short capacity);
};
#endif