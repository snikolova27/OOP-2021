#include "VehicleAllocator.h"
#include "catch2.hpp"

//getters, the isEmpty and the at function are simultaneously tested with the default constructor
TEST_CASE("Testing the default constructor")
{
    VehicleAllocator va;
    REQUIRE(va.getUsed() == 0);
    REQUIRE(va.getCapacity() == 2);
    REQUIRE(va.isEmpty());
}
//resize function is also being tested here
TEST_CASE("Testing the add a new vehicle function")
{
    VehicleAllocator va;
    va.createVehicle("VARNA 1", "dark opel", 2);

    SECTION("Adding first vehicle")
    {
        REQUIRE(va.getCapacity() == 2);
        REQUIRE(va.getUsed() == 1);
        REQUIRE(!va.isEmpty());
        REQUIRE(va.at(0).space() == 2);
        REQUIRE(strcmp(va.at(0).description(), "dark opel") == 0);
        REQUIRE(strcmp(va.at(0).registration(), "VARNA 1") == 0);
    }
    va.createVehicle("SOFIA2", "Mazda", 1);

    SECTION("More vehicles and resizing")
    {
        va.createVehicle("PLOVDIV3", "boat", 3);
        REQUIRE(va.getCapacity() == 4);
        REQUIRE(va.getUsed() == 3);
        REQUIRE(!va.isEmpty());
        REQUIRE(strcmp(va.at(1).description(), "Mazda") == 0);
        REQUIRE(strcmp(va.at(2).registration(), "PLOVDIV3") == 0);
    }

    va.createVehicle("SOFIA2", "Mazda", 1);

    SECTION("Trying to add a vehicle with the same license plate")
    {
        REQUIRE(va.getCapacity() == 4);
        REQUIRE(va.getUsed() == 2);
        REQUIRE(!va.isEmpty());
        REQUIRE(strcmp(va.at(1).description(), "Mazda") == 0);
    }
}
TEST_CASE("Testing the delete a vehicle function")
{
    VehicleAllocator va;
    va.createVehicle("VARNA 1", "dark opel", 2);
    va.createVehicle("SOFIA2", "Mazda", 1);
    va.createVehicle("PLOVDIV", "Mazda", 1);

    SECTION("Removing a created vehicle")
    {
        va.deleteVehicle("SOFIA2");
        REQUIRE(va.getCapacity() == 4);
        REQUIRE(va.getUsed() == 2);
        REQUIRE(!va.isEmpty());
        REQUIRE(strcmp(va.at(1).registration(), "PLOVDIV") == 0);
    }
    SECTION("Removing a vehicle with a license plate that doesn't match any of the ones in the allocator")
    {
        va.deleteVehicle("BLAGOEVGRAD");
        REQUIRE(va.getCapacity() == 4);
        REQUIRE(va.getUsed() == 3);
        REQUIRE(!va.isEmpty());
    }
}
TEST_CASE("Testing the find function")
{
    VehicleAllocator va;
    va.createVehicle("VARNA 1", "dark opel", 2);
    va.createVehicle("PLOVDIV", "Mazda", 1);
    SECTION("Searching for an existing vehicle")
    {
        Vehicle *vehicle1 = va.findVehicle("VARNA 1");
        REQUIRE(strcmp(vehicle1->registration(), "VARNA 1") == 0);
        REQUIRE(strcmp(vehicle1->description(), "dark opel") == 0);
        REQUIRE(vehicle1->space() == 2);
    }
    SECTION("Testing with a non-existing vehicle")
    {
        Vehicle *invalid = va.findVehicle("SOFIA2");
        REQUIRE(invalid == nullptr);
    }
}
TEST_CASE("Testing the at function")
{
    VehicleAllocator va;
    va.createVehicle("VARNA 1", "dark opel", 2);
    va.createVehicle("PLOVDIV", "Mazda", 1);
    SECTION("Testing with valid position")
    {
        REQUIRE(va.at(0).space() == 2);
        REQUIRE(va.at(1).space() == 1);
    }
    SECTION("Testing with an invalid position")
    {
        REQUIRE_THROWS(va.at(4));
    }
}
TEST_CASE("Testing the destroy function")
{
    VehicleAllocator va;
    va.createVehicle("VARNA 1", "dark opel", 2);
    va.createVehicle("PLOVDIV", "Mazda", 1); 

    va.deleteAll();

    REQUIRE(va.isEmpty());
    REQUIRE(va.getUsed() == 0);
    REQUIRE(va.getCapacity() == 2);
 }