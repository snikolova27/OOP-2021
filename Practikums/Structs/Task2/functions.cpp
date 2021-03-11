#include <iostream>
#include <cmath>
#include "functions.h"

void Point::readPoint()
{
    std::cout << '\t'<< "Enter coordinates of point " << std::endl;
    std::cout << "X axis: ";
    std::cin >> X_axis;
    std::cout << "Y axis: ";
    std::cin >> Y_axis;
}

void Point::printPoint()
{
    std::cout << "(" << X_axis << "," << Y_axis << ")" << std::endl;
}

double Point::printDistanceToCenter()
{
    return sqrt(X_axis*X_axis + Y_axis*Y_axis);
}
double distanceBetweenPoints(Point first, Point scnd)
{
    double x_axis = fabs(first.X_axis - scnd.X_axis);
    double y_axis = fabs(first.Y_axis - scnd.Y_axis);

    return sqrt(x_axis*x_axis + y_axis*y_axis);
}   
