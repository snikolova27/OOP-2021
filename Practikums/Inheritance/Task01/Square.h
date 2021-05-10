#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square : public Shape
{
private:
    int side;

public:
      Square(const int _side);
};
#endif