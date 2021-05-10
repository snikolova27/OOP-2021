#include "Human.h"

Human::Human(std::string _firstName, std::string _lastName, int _age)
{
    this->firstName = _firstName;
    this->lastName = _lastName;
    this->age = _age;
}
std::string Human::getFirstName() const
{
    return this->firstName;
}
std::string Human::getLastName() const
{
    return this->lastName;
}
int Human::getAge() const
{
    return this->age;
}