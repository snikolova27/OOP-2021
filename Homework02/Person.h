#pragma once
#include <vector>
#include <iostream>

class Vehicle;
#include "Vehicle.h"

class Person
{
private:
    std::string name;
    unsigned int id;
    std::vector<Vehicle*> vehicles;

public:
    Person(const std::string name, const unsigned int id);

    bool operator==(const Person &other);

    void addVehicle(const Vehicle &vehicle);

    std::string getName() const;
    unsigned int getId() const;
};
