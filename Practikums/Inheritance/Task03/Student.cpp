#include "Student.h"
#include <iostream>

int Student:: cnt = 6000;

Student::Student(std::string _firstName, std::string _lastName, int _age, std::string _major) : Human(_firstName, _lastName, _age)
{
    this->major=_major;
    this->fn = ++cnt;
}
void Student::print()
{
    std::cout << "Faculty number: " << this->fn << std::endl;
    std::cout << "First name: " << this->getFirstName() << std::endl;
    std::cout << "Last name: " << this->getLastName() << std::endl;
    std::cout << "Age: " << this->getAge() << std::endl;
    std::cout << "Major: " << this->major << std::endl;
}