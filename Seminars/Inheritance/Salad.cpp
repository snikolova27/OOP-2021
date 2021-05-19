#include "Salad.h"

Salad::Salad(const double weight, const double price, const bool isSpiced, const unsigned int ingredients) : Food(weight, 1, price)
{   
    this->isSpiced = isSpiced;
    this->ingredients = ingredients;

}
