#include "Student.h"

Student::Student(std::string name, int number) : Person(name)
{

    this->number = number;
}
int Student::getNumber() const
{
    return this->number;
}
