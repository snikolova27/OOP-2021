#include "ColoredRectangular.h"

ColoredRectangular::ColoredRectangular(const std::string _color, const int _width, const int _height) : Rectangular(_width, _height, "colored rectangular")
{
    this->color = _color;
}
