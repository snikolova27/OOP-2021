#pragma once
#include "Component.h"

class Memory : public Component
{
private:
    unsigned short capacity;
    static const double PRICE_PER_GB;

public:
    Memory(std::string label, const unsigned short capacity);
    
    virtual double price() const override;
};