#include "Vehicle.h"

//------------ constructor ------------
Vehicle::Vehicle(const char *_licensePlate, const char *_description, std::size_t _parkingSpace)
{
    this->licensePlate.setString(_licensePlate);
    this->desc.setString(_description);
    this->parkingSpace = _parkingSpace;
}

//------------ getters ------------
const char *Vehicle::registration() const
{
    return this->licensePlate.c_str();
}
const char *Vehicle::description() const
{
    return this->desc.c_str();
}
std::size_t Vehicle::space() const
{
    return this->parkingSpace;
}