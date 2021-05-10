#ifndef RECTANGULAR_H
#define RECTANGULAR_H
#include "Shape.h"

class Rectangular : public Shape
{
private:
    int width;
    int height;

public:
    Rectangular(const int _widht, const int _height);
    Rectangular(const int _width, const int _height, const std::string _type);
};
#endif