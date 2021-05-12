#include "Student.h"

void Student::copy(const Student &other)
{
    this->name = other.name;
    this->fn = other.fn;
    this->signedUp = other.signedUp;
}

Student::Student(const Student &other)
{
    this->copy(other);
}
Student::Student(std::string _name, std::string _fn, bool _signedUp)
{
    this->name = _name;
    this->fn = _fn;
    this->signedUp = _signedUp;
}
std::string Student::getName() const
{
    return this->name;
}
std::string Student::getFn() const
{
    return this->fn;
}
bool Student::getSignedUp() const
{
    return this->signedUp;
}
Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        this->copy(other);
    }

    return *this;
}
std::ostream &operator<<(std::ostream &out, Student &student)
{
    out << "Name of student:" << student.getName() << std::endl;
    out << "Faculty number: " << student.getFn() << std::endl;
    return out;
}