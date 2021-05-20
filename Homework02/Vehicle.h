#pragma once
#include "Registration.h"

class Person;
#include "Person.h"

class Vehicle
{
private:
    Registration registration;
    std::string description;
    Person *owner;

public:
Vehicle(const std::string registration, const std::string description);
std::string getRegistration() const;
void setOwner(const Person& owner); //todo
void clearOwner(); //todo
};
