#include <iostream>
#include "Triangle.hpp"

int main()
{
    Triangle tr;

    tr.input();
    std::cout << "Perimeter is: " << tr.perimeter() << std::endl;
   std::cout << "Area is: " <<  tr.area() << std::endl;

    return 0;
}