#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "Parking.h"

TEST_CASE("Test default constructor")
{
    Parking p;

    REQUIRE(p.getFirmmName() == nullptr);
    REQUIRE(p.getCapacity() == INITAL_CAPACITY);
    REQUIRE(p.getSize() == 0);
   
}