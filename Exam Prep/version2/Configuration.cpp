#include "Configuration.h"
#include <stdexcept>
#include <iostream>

double Configuration::price() const
{
    double result = 0.0;
    std::size_t size = this->size();

    for (std::size_t i = 0; i < size; i++)
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
    if (index >= this->size())
    {
        throw std::out_of_range("Invalid index");
    }
    return *this->components[index];
}
std::ostream &operator<<(std::ostream &out, const Configuration &config)
{
    std::size_t size = config.size();
    for (std::size_t i = 0; i < size; i++)
    {
        config[i].output(out);
    }
    out << "Total price: " << config.price() << std::endl;

    return out;
}

void Configuration::insert(Component *component)
{
    std::size_t size = this->size();
    if (size == 0)
    {
        this->components.push_back(component);
    }
    for (std::size_t i = 0; i < size; i++)
    {
        if (typeid(*this->components[i]) == typeid(*component))
        {
            throw std::invalid_argument("Component of this type already exists in the configuration");
        }
        else
        {
            this->components.push_back(component);
        }
    }
}

Configuration::~Configuration()
{
    std::size_t size = this->size();
    for (std::size_t i = 0; i < size; i++)
    {
        if (this->components[i])
        {
            delete this->components[i];
        }
    }
}
