#include "Cpu.h"
#include <stdexcept>

const double CPU::PRICE_PER_CORE = 29.99;

CPU::CPU(std::string label, const unsigned short cores, const unsigned short clockSpeed)
    : Component(label)
{
    if (!cores || cores > 8)
    {
        throw std::invalid_argument("Cores should be less than 8");
    }
    else
    {
        this->cores = cores;
        this->clockSpeed = clockSpeed;
    }
}
double CPU::price() const
{
    return this->cores * PRICE_PER_CORE;
}