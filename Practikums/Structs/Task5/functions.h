#ifndef FUNC_H
#define FUNC_H

struct Point
{
    double x;
    double y;

    void getPoint();
};

struct Rectangle
{
    Point upperLeft;
    Point lowerRight;

    void getRectangle();
    void printRectangle();
    bool isPointInside(Point A);
};

bool doRectanglesIntersect(Rectangle A, Rectangle B);

#endif