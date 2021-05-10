#ifndef LECTURER_H
#define LECTURER_H
#include "Person.h"

class Lecturer : virtual public Person
{
protected:
    double salary;

public:
    Lecturer(std::string name, double salary);
    double getSalary() const;
};
#endif