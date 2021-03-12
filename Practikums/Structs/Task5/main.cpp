#include <iostream>
#include "functions.h"

int main()
{
    Rectangle A, B;

    std::cout << "Rectangle 1" << std::endl;
    A.getRectangle();
    std::cout << "Rectangle 2" << std::endl;
    B.getRectangle();

    Point point;

    std::cout << "Point" << std::endl;
    point.getPoint();

    if (A.isPointInside(point))
    {
        std::cout << "The point is inside rectangle 1" << std::endl;
    }
    else
    {
        std::cout << "The point is outside rectangle 1" << std::endl;
    }
    if (B.isPointInside(point))
    {
        std::cout << "The point is inside rectangle 2" << std::endl;
    }
    else
    {
        std::cout << "The point is outside rectangle 2" << std::endl;
    }

    if (doRectanglesIntersect(A, B))
    {
        std::cout << "The rectangles intersect" << std::endl;
    }
    else
    {
        std::cout << "The rectangles do not intersect" << std::endl;
    }

    A.printRectangle();
    return 0;
}