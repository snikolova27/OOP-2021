#include "Configuration.h"

void Configuration::insert(const Component *component)
{
    std::size_t cntOfComponents = this->size();
    for (std::size_t i = 0; i < cntOfComponents; i++)
    {
        if (this->components[i]->getType() == component->getType())
        {
            throw std::invalid_argument("Component is already in configuration and won't be added! ");
        }
    }
    this->components.push_back(component);
}


double Configuration::price() const
{
    std::size_t cntOfComponents = this->size();
    double result = 0;

    for (std::size_t i = 0; i < cntOfComponents; i++)
    {
        result += this->components[i]->price();
    }
    return result;
}

std::size_t Configuration::size() const
{
    return this->components.size();
}

const Component &Configuration::operator[](std::size_t index) const
{
    std::size_t cntOfComponents = this->size();
    if (index > cntOfComponents - 1)
    {
        throw std::out_of_range("Index is out of range");
    }
    else
    {
        return *this->components.at(index);
    }
}

std::ostream &operator<<(std::ostream &out, const Configuration &config)
{
    std::size_t cntOfComponents = config.size();
    for (std::size_t i = 0; i < cntOfComponents; i++)
    {
        out << "Component #" << i + 1 << std::endl;
        config.components[i]->output(out);
    }
    out << "Price of whole configuration: " << config.price() << std::endl;

    return out;
}

Configuration::~Configuration()
{
    std::size_t cntOfComponents = this->size();
    for (std::size_t i = 0; i < cntOfComponents; i++)
    {
        delete this->components[i];
    }
}