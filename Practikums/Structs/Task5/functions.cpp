#include <iostream>
#include "functions.h"

void Point ::getPoint()
{
    std::cout << "X coordinates: ";
    std::cin >> x;
    std::cout << "Y coordinates: ";
    std::cin >> y;
    std::cin.ignore();
}

void Rectangle::getRectangle()
{
    std::cout << '\t' << "Enter the coordinates of the upper left point of the rectangle" << std::endl;
    upperLeft.getPoint();
    std::cout << '\t' << "Enter the coordinates of the lower right point of the rectangle" << std::endl;
    lowerRight.getPoint();
}

bool Rectangle::isPointInside(Point A)
{
    return (A.x >= upperLeft.x && A.x <= lowerRight.x) && (A.y >= lowerRight.y && A.y <= upperLeft.y);
}

void Rectangle::printRectangle()
{
    if (upperLeft.x < 0 || upperLeft.y < 0)
    {
        std::cout << "Coordinates should be positive numbers";
        return;
    }
    int rows = (int)lowerRight.y;
    int cols = (int)lowerRight.x;

    char **rec = new (std::nothrow) char *[rows];
    for (int i = 0; i < lowerRight.y; i++)
    {
        rec[i] = new (std::nothrow) char[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < cols; k++)
        {
            if (i >= upperLeft.y && k >= upperLeft.x)
            {
                rec[i][k] = '*';
            }
            else
            {
                rec[i][k] = ' ';
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < cols; k++)
        {
            std::cout << rec[i][k];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] rec[i];
    }
    delete[] rec;
}

bool doRectanglesIntersect(Rectangle A, Rectangle B)
{
     if (std::max(A.upperLeft.x, B.upperLeft.x) > std::min(A.lowerRight.x, B.lowerRight.x))
    {
        return false;
    }

    if (std::max(A.lowerRight.y, B.lowerRight.y) > std::min(A.upperLeft.y, B.upperLeft.y))
    {
        return false;
    }

    return true;
}