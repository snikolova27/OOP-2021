#include "Cpu.h"

const double Cpu::PRICE_PER_CORE = 29.99;

Cpu::Cpu(const unsigned short cores, unsigned short clockSpeed)
{

    if (!(cores >= 1 && cores <= 8))
    {
        throw std::out_of_range("Number of cores should be between 1 and 8");
    }
    else
    {
        this->cores = cores;
        this->clockSpeed = clockSpeed;
        this->m_label = "cpu";
        this->m_price = cores * PRICE_PER_CORE;
        this->type = ComponentType::CPU;
    }
}