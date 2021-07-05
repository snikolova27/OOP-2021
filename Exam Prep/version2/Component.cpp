#include "Component.h"
#include <iostream>

Component::Component(std::string label) : m_label(label) {};

void Component::output(std::ostream &out) const
{
    out << "Label: " << this->m_label << std::endl;
    out << "Price: " << this->price() << std::endl;
}