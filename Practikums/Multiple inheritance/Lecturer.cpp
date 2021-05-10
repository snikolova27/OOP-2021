#include "Lecturer.h"

Lecturer::Lecturer(std::string name, double salary) : Person(name)
{
    this->salary = salary;
}
double Lecturer::getSalary() const
{
    return this->salary;
}