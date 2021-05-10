#include "Rectangular.h"

Rectangular::Rectangular(const int _widht, const int _height) : Shape("rectangular")
{
    this->width = _widht;
    this->height = _height;
}
Rectangular::Rectangular(const int _width, const int _height, const std::string _type) : Shape("_type")
{
    this->width = _width;
    this->height = _height;
}