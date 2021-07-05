#include "Component.h"

double Component::price() const
{
    return this->m_price;
}
void Component::output(std::ostream &out) const
{
    if (this == nullptr)
    {
        return;
    }
    else
    {
        out << "Name: " << this->m_label << std::endl;
        out << "Price: " << this->price() << std::endl;
    }
}
ComponentType Component::getType() const
{
    return this->type;
}
