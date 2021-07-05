#pragma once
#include <string>

class Component
{
protected:
    const std::string m_label;

public:
    Component(std::string label);
    virtual double price() const = 0;
    void output(std::ostream &out) const;

    static Component* createComponent();
    virtual ~Component() = default;
};