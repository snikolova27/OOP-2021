#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "functions.h"

TEST_CASE("Is point contained", "[point]")
{
    Point testPoint1;
    Rectangle rec1;
    rec1.upperLeft.x = 1;
    rec1.upperLeft.y = 6;
    rec1.lowerRight.x = 8;
    rec1.lowerRight.y = 2;

    SECTION("Test if point is inside the rectangle")
    {
        testPoint1.x = 2;
        testPoint1.y = 5;

        REQUIRE(rec1.isPointInside(testPoint1) == true);
    }
    SECTION("Test if point is outside the rectangle")
    {
        testPoint1.x = 0;
        testPoint1.y = 9;

        REQUIRE(rec1.isPointInside(testPoint1) == false);
    }
}

TEST_CASE("Do the rectangles intersect", "[rectangles]")
{
    Rectangle rec1, rec2;

    SECTION("Rectangles should intersect")
    {
        rec1.upperLeft.x = 1;
        rec1.upperLeft.y = 6;
        rec1.lowerRight.x = 8;
        rec1.lowerRight.y = 2;
        rec2.upperLeft.x = 3;
        rec2.upperLeft.y = 5;
        rec2.lowerRight.x = 7;
        rec2.lowerRight.y = 3;

        REQUIRE(doRectanglesIntersect(rec1, rec2) == true);
    }
    SECTION("Rectangles should not intersect")
    {
        rec1.upperLeft.x = 3;
        rec1.upperLeft.y = 6;
        rec1.lowerRight.x = 8;
        rec1.lowerRight.y = 3;
        rec2.upperLeft.x = 0;
        rec2.upperLeft.y = 2;
        rec2.lowerRight.x = 2;
        rec2.lowerRight.y = 0;

        REQUIRE(doRectanglesIntersect(rec1, rec2) == false);
    }
}