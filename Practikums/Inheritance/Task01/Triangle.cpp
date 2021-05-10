#include "Triangle.h"

Triangle::Triangle(const std::string _typeTriangle, const int _side1, const int _side2, const int _side3) : Shape("triangle")
{
    this->typeTriangle = _typeTriangle;
    this->side1 = _side1;
    this->side2 = _side2;
    this->side3 = _side3;
}
