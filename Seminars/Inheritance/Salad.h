#ifndef SALAD_H
#define SALAD_H
#include "Food.h"

class Salad : public Food
{
     private:
     bool isSpiced;
     unsigned int ingredients;

     public:
     Salad(const double weight, const double price, const bool isSpiced, const unsigned int ingredients);
};
#endif