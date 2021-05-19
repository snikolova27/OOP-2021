#include "Pizza.h"

Pizza::Pizza(const double weight, const unsigned int parts, const double price, const std::string type) : Food(weight, parts, price)
{
    this->type = type;
}