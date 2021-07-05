#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <iostream>
#include "ComponentType.h"


class Component
{
protected:
    std::string m_label;
    double m_price;
    ComponentType type;
      
public:
    Component() = default;
    double price() const;
    void output(std::ostream &out) const;
    ComponentType getType() const;
};
#endif