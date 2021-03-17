#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "functions.h"
//const double EPSILON = 0.00000015446165;

TEST_CASE("Check if the letter is in upper case", "[letter]")
{
    char lower = 'a';
    char upper = 'A';

    SECTION("Test with letter in lower case")
    {
        REQUIRE(toUpper(lower) == 'A');
    }
    SECTION("Test with letter in upper case")
    {
        REQUIRE(toUpper(upper) == 'A');
    }
}

// TEST_CASE("Check average speed function")
// {
//     Runner runner1, runner2;
//     runner1.times[0] = 2544;
//     runner1.times[1] = 2784;
//     runner1.times[2] = 3210;
//     runner1.times[3] = 4598;
//     runner1.times[4] = 2544;
//     runner1.times[5] = 2544;
//     runner1.times[6] = 7844;
//     runner1.times[7] = 1544;
//     runner1.times[8] = 8741;
//     runner1.times[9] = 251444;
//     runner1.times[10] = 2546344;
//     runner1.times[11] = 251244;

//     REQUIRE(runner1.avgSpeed() <= (0.5880627539 - EPSILON));
// }

TEST_CASE("test beat>Runner function ")
{
    Runner runner1, runner2;
    runner1.times[0] = 2544;
    runner1.times[1] = 2784;
    runner1.times[2] = 3210;
    runner1.times[3] = 4598;
    runner1.times[4] = 2544;
    runner1.times[5] = 2544;
    runner1.times[6] = 7844;
    runner1.times[7] = 1544;
    runner1.times[8] = 8741;
    runner1.times[9] = 251444;
    runner1.times[10] = 2546344;
    runner1.times[11] = 251244;

    runner2.times[0] = 25414;
    runner2.times[1] = 27845;
    runner2.times[2] = 321078;
    runner2.times[3] = 459845;
    runner2.times[4] = 2544;
    runner2.times[5] = 2544;
    runner2.times[6] = 7844;
    runner2.times[7] = 1544;
    runner2.times[8] = 8741;
    runner2.times[9] = 251444;
    runner2.times[10] = 2546344;
    runner2.times[11] = 251244;

    REQUIRE(runner2.beatRunner(runner1) == 4);
}