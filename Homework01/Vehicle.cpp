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

//----------- operator overloading ------------
//used for printing the information about the vehicle
std::ostream &operator<<(std::ostream &out, const Vehicle &v)
{
    std::cout << "License plate: " << v.registration() << std::endl;
    std::cout << "Description: " << v.description() << std::endl;
    std::cout << "Needed parking space: " << v.space() << std::endl;

    return out;
}
