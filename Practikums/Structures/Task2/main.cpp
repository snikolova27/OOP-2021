#include <iostream>
#include "functions.h"

int main()
{
    Point pointA, pointB;

    pointA.readPoint();
    pointB.readPoint();

    std::cout << std::endl;

    pointA.printPoint();
    pointB.printPoint();

    std::cout << std::endl;

    std::cout << "Distance of first point to center: " << pointA.printDistanceToCenter() << std::endl;
    std::cout << "Distance of second point to center: " << pointB.printDistanceToCenter() << std::endl;

    std::cout << std::endl;

    std::cout << "Distance between the two points: " << distanceBetweenPoints(pointA, pointB) << std::endl;

    return 0;
}