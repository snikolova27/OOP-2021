#ifndef PIZZA_H
#define PIZZA_H
#include "Food.h"
#include <string>

class Pizza: public Food
{
    private:
    std::string type;

    public:
    Pizza(const double weight, const unsigned int parts, const double price, const std::string type);
};
#endif