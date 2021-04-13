#ifndef VEHICLE_H
#define VEHICLE_H
#include "MyString.h"

class Vehicle
{
private:
    MyString licensePlate;
    MyString desc;
    std::size_t parkingSpace;

public:
    //------------ constructor ------------
    Vehicle(const char *_licensePlate, const char *_description, std::size_t _parkingSpace);

    //------------ getters ------------
    const char *registration() const;
    const char *description() const;
    std::size_t space() const;
};
#endif