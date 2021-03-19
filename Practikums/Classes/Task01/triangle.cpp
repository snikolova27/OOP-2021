#include <iostream>
#include <cmath>
#include "Triangle.hpp"

bool Triangle::validate()
{
    return (sideA > 0 && sideB > 0 & sideC > 0 & (sideC < sideA + sideB));
}

void Triangle::input()
{
    std::cout << "Enter the sizes of the sides of the triangle" << std::endl;
    std::cout << "Side A: ";
    std::cin >> sideA;
    std::cout << "Side B: ";
    std::cin >> sideB;
    std::cout << "Side C: ";
    std::cin >> sideC;

    if (validate())
    {
        std::cout << "Triangle entered correctly" << std::endl;
    }
    else
    {
        std::cout << "Sides shouldn't be negative or equal to 0, side C should be < (side A + aide B)" << std::endl;
    }
}

double Triangle::perimeter()
{
    if (validate())
    {
        return sideA + sideB + sideC;
    }
    else
    {
        std::cout << "Input is not valid" << std::endl;
        return -1;
    }
}

double Triangle::area()
{
    double halfPerimeter = perimeter() / 2;

    if (validate())
    {
        return sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));
    }
    else
    {
        std::cout << "Input is not valid" << std::endl;
        return -1;
    }
}