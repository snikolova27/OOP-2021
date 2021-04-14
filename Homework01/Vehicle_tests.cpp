#include "catch2.hpp"
#include "Vehicle.h"

//not testing the getter functions on their own because they're used in the constructor
TEST_CASE("Testing the constructor with parameters")
{
    SECTION("Testing with non-null values")
    {
        Vehicle v("SOFIA", "black Mazda", 2);
        REQUIRE(strcmp(v.registration(), "SOFIA") == 0);
        REQUIRE(strcmp(v.description(), "black Mazda") == 0);
        REQUIRE(v.space() == 2);
    }
    SECTION("Testing with empty strings")
    {
        Vehicle v("", "", 2);
        REQUIRE(strcmp(v.registration(), "") == 0);
        REQUIRE(strcmp(v.description(), "") == 0);
        REQUIRE(v.space() == 2);
    }
    SECTION("Testing with null pointers")
    {
        Vehicle v(nullptr, nullptr, 2);
        REQUIRE(v.registration() == nullptr);
        REQUIRE(v.description() == nullptr);
        REQUIRE(v.space() == 2);
    }
}