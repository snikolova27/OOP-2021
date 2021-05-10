#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
    private:
    std::string typeTriangle;
    int side1;
    int side2;
    int side3;

    public:
    Triangle(const std::string _typeTriangle, const int _side1, const int _side2, const int _side3);

};

#endif