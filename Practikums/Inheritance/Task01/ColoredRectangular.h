#ifndef COLORED_RECTANGULAR_H
#define COLORED_RECTANGULAR_H
#include "Rectangular.h"

class ColoredRectangular:public Rectangular
{
    private:
    std::string color;

    public:
    ColoredRectangular(const std::string _color, const int _width, const int _height);

};
#endif