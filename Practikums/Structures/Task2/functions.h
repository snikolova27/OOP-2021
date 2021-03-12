#ifndef FUNC_H
#define FUNC_H

struct Point
{
    double X_axis;
    double Y_axis;

    void readPoint();
    void printPoint();
    double printDistanceToCenter();
};

double distanceBetweenPoints(Point first, Point scnd);

#endif