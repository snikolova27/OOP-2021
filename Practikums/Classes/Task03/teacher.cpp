#include <iostream>
#include <cstring>
#include "Teacher.hpp"

Teacher::Teacher()
{
    this->name = nullptr;
    this->teachingClass = nullptr;
}

Teacher::Teacher(const char* name, const char* teachingClass)
{
    size_t size = strlen(name);
    this->name = new char[size + 1];
    strcpy(this->name, name);\

    size = strlen(teachingClass);
    this->teachingClass = new char[size + 1];
    strcpy(this->teachingClass, teachingClass);

}

Teacher::~Teacher()
{
    deallocate();
}

void Teacher::input()
{
    char buffer[100];

    std::cout << "Please enter the name of the teacher: ";
    std::cin.getline(buffer, 100);
    size_t size = strlen(buffer);
    this->name = new(std::nothrow) char[size + 1];
    strcpy(this->name, buffer);
    this->name[size] = '\0';

    std::cout << "Please enter the class the teacher teaches: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    this->teachingClass = new(std::nothrow) char[size + 1];
    strcpy(this->teachingClass, buffer);
    this->teachingClass[size] = '\0';
}

void Teacher::deallocate()
{
    delete[] this->name;
    delete[] this->teachingClass;
}

void Teacher::copyTeacher(Teacher& teacher)
{
    teacher.setName(this->name);
    teacher.setTeachingClass(this->teachingClass);
}

char* Teacher::getName() const
{
    return this->name;
}

void Teacher::print()
{
    std::cout << this->name << ", " << this->teachingClass << std::endl;
}

void Teacher::setName(const char* _name)
{
    size_t size = strlen(_name);
    this->name = new(std::nothrow) char[size + 1];
    if (!this->name)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->name, _name);
    this->name[size] = '\0';
}

void Teacher::setTeachingClass(const char* _teachingClass)
{
    size_t size = strlen(_teachingClass);
    this->teachingClass = new(std::nothrow) char[size + 1];
    if (!this->teachingClass)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->teachingClass, _teachingClass);
    this->teachingClass[size] = '\0';
}