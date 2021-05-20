#include "Person.h"

Person::Person(const std::string name, const unsigned int id)

{
    this->name = name;
    this->id = id;
}

bool Person::operator==(const Person &other)
{
    return this->id == other.id;
}

std::string Person::getName() const
{
    return this->name;
}

unsigned int Person::getId() const
{
    return this->id;
}

void Person::addVehicle(const Vehicle &vehicle)
{
    //validate that same registration is not already owned by person

    for (int i = 0; i < this->vehicles.size(); i++)
    {
        if (this->vehicles[i] == vehicle)
        {
            std::cout << "This vehicle is already owned by the person" << std::endl;
            return;
            
        }
    }
    this->vehicles.push_back(vehicle);

}
