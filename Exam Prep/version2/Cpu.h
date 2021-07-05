#pragma once
#include "Component.h"

class CPU : public Component
{
private:
    unsigned short cores;
    unsigned short clockSpeed;
    static const double PRICE_PER_CORE;

public:
    CPU(std::string label, const unsigned short cores, const unsigned short clockSpeed);

    virtual double price() const override;
};