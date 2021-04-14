#include "Garage.h"
#include "catch2.hpp"

//the empty and at functions are tested simultaneously with the parameter constructor
TEST_CASE("Testing the parameter constructor")
{
    SECTION("Testing with non-null value")
    {
        Garage garage(5);
        REQUIRE(garage.getSize() == 0);
        REQUIRE(garage.empty());
        REQUIRE_THROWS(garage.at(2), "Such position doesn't exist in the garage");
    }
    SECTION("Testing with null value")
    {
        Garage garage(0);
        REQUIRE(garage.getSize() == 0);
        REQUIRE(garage.empty());
        REQUIRE_THROWS(garage.at(2), "Such position doesn't exist in the garage");
    }
}
// the insert, at and getSize functions are being tested simultaneously with the insert function
//not testing the [] operator because it has an assertion for validity
TEST_CASE("Testing the insert vehicle function")
{
    SECTION("Testing with non-null values")
    {
        Garage garage(10);
        Vehicle v1("VARNA 1", "New car", 1);
        Vehicle v2("PLOVDIV 2", "New boat", 4);
        Vehicle v3("SOFIA 3", "Old car", 2);

        REQUIRE_NOTHROW(garage.insert(v1));
        REQUIRE_NOTHROW(garage.insert(v2));
        REQUIRE_NOTHROW(garage.insert(v3));
        REQUIRE(garage.getSize() == 3);
        REQUIRE_THROWS(garage.at(6), "Such position doesn't exist in the garage");
    }
}
TEST_CASE("Testing the erase function")
{
    SECTION("Testing with non-null values")
    {
        Garage garage(10);
        Vehicle v1("VARNA 1", "New car", 1);
        Vehicle v2("PLOVDIV 2", "New boat", 4);
        Vehicle v3("SOFIA 3", "Old car", 2);

        garage.insert(v1);
        garage.insert(v2);
        garage.insert(v3);

        garage.erase("VARNA 1");
        REQUIRE(garage.getSize() == 2);

        //erase function should return that there is no such vehicle
        garage.erase("VARNA 1");
        REQUIRE(garage.getSize() == 2);

        garage.erase("VARNA 2");
        REQUIRE(garage.getSize() == 2);

        garage.erase("PLOVDIV 2");
        REQUIRE(garage.getSize() == 1);
        garage.erase("SOFIA 3");
        REQUIRE(garage.getSize() == 0);

        REQUIRE(garage.empty());

        REQUIRE_THROWS(garage.at(0), "Such position doesn't exist in the garage");
    }
}
TEST_CASE("Testing the find in garage function")
{
    Garage garage(10);
    Vehicle v1("VARNA 1", "New car", 1);
    Vehicle v2("PLOVDIV 2", "New boat", 4);
    Vehicle v3("SOFIA 3", "Old car", 2);

    garage.insert(v1);
    garage.insert(v2);
    garage.insert(v3);

    SECTION("Testing with non-null value")
    {
        REQUIRE(garage.find("VARNA 2") == nullptr);
        REQUIRE(strcmp(garage.find("VARNA 1")->registration(), "VARNA 1") == 0);
    }
    SECTION("Testing with an empty string")
    {
        REQUIRE(garage.find("") == nullptr);
    }
    SECTION("Testing with a null pointer")
    {
        REQUIRE(garage.find(nullptr) == nullptr);
    }
}
TEST_CASE("Testing the clear function")
{
    SECTION("Testing with non-empty garage")
    {
        Garage garage(10);
        Vehicle v1("VARNA 1", "New car", 1);
        Vehicle v2("PLOVDIV 2", "New boat", 4);
        Vehicle v3("SOFIA 3", "Old car", 2);

        garage.insert(v1);
        garage.insert(v2);
        garage.insert(v3);

        garage.clear();

        REQUIRE(garage.getSize() == 0);
    }
    SECTION("Testing with an empty garage")
    {
        Garage garage(0);
        garage.clear();
        REQUIRE(garage.getSize() == 0);
    }
}
