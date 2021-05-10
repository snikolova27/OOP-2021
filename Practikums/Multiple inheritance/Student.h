#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : virtual public Person
{
protected:
    int number;

public:
    int getNumber() const;
    Student(std::string name, int number);
};

#endif