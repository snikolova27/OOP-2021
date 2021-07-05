#ifndef CPU_H
#define CPU_H
#include "Component.h"

class Cpu : public Component
{
private:
    unsigned short cores;
    unsigned short clockSpeed;
    static const double PRICE_PER_CORE;

public:
    Cpu(const unsigned short cores, unsigned short clockSpeed);
};

#endif