#include "Vehicle.h"

Vehicle::Vehicle(const std::string registration, const std::string description) : registration(registration.c_str())
{
    this->description = description;
    this->owner = nullptr;
}
std::string  Vehicle:: getRegistration() const
{
    return this->registration.getRegistration();
}