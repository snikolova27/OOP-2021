#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "Time.h"

TEST_CASE("Check if setters work properly")
{
    Time t;
    t.setHour(10);
    t.setMinute(59);
    Time t2;
    t2.setHour(25);
    t2.setMinute(60);

    SECTION("Test hours setter when hours <=23")
    {
        REQUIRE(t.getHour() == 10);
    }
    SECTION("Test hours setter whe hours >= 24")
    {
        REQUIRE(t2.getHour() == 0);
    }
    SECTION("Test minutes setter when minutes <= 59")
    {
        REQUIRE(t.getMinute() == 59);
    }
    SECTION("Test minutes setter when minutes >=60 ")
    {
        REQUIRE(t2.getMinute() == 0);
    }
}
TEST_CASE("Check if getters work properly")
{
    Time t(12, 25);

    SECTION("Check if hour getter works ")
    {
        REQUIRE(t.getHour() == 12);
    }
    SECTION("Check if minutes getter works")
    {
        REQUIRE(t.getMinute() == 25);
    }
}

TEST_CASE("Check if default constructor works properly")
{
    Time t;

    SECTION("Test if default hours value is 0")
    {
        REQUIRE(t.getHour() == 0);
    }
    SECTION("Test if default minutes value is 0")
    {
        REQUIRE(t.getMinute() == 0);
    }
}

TEST_CASE("Check if constructor with parameters works correctly")
{
    Time t(14, 45);

    SECTION("Test the parameter constructor")
    {
        REQUIRE(t.getHour() == 14);
        REQUIRE(t.getMinute() == 45);
    }
}

TEST_CASE("Check if copy constructor works correctly")
{
    Time t1(15, 21);
    Time t2(t1);

    REQUIRE(t2.getHour() == 15);
    REQUIRE(t2.getMinute() == 21);
}

TEST_CASE("Check if += operator works correctly")
{
    Time t1(14, 10);
    Time t2;
    Time t3(11, 52);
    t2 += t1;
    Time t4;
    t4 += t3;
    t4 += t1;

    SECTION("Check if hours are correct when they are < 24")
    {
        REQUIRE(t2.getHour() == 14);
    }
    SECTION ("Check if hours are correct when they are > 24")
    {
        REQUIRE(t4.getHour() == 2 );
    }
    SECTION("Check if minutes are correct when they are < 60")
    {
        REQUIRE(t2.getMinute() == 10);
    }
    SECTION("Check if minutes are correct when they are > 59")
    {
        REQUIRE(t4.getMinute() == 2);
    }
}
