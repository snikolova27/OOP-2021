#include "facultyMember.h"
#include <iostream>
#include <fstream>

FacultyMember :: FacultyMember() :Person("not set"),  Student ("not set", 0), Lecturer("not set" , 0.0)
{
    
}
FacultyMember::FacultyMember(std::string name, int number, double salary) : Person(name), Student(name, number), Lecturer(name, salary)
{
}
void FacultyMember::print()
{
    std::cout << "Name: " << Person::getName() << std::endl;
    std::cout << "Number: " << Student::getNumber() << std::endl;
    std::cout << "Salary: " << Lecturer::getSalary() << std::endl;
}
std::istream& operator >> (std::istream& in, FacultyMember& facultyMember)
{
    std::cout << "Please enter name: ";
    getline(in, facultyMember.name);

    std::cout << "Please enter number: ";
    in >> facultyMember.number;

    std::cout << "Please enter salary: ";
    in >> facultyMember.salary;
    in.ignore();

    return in;
}
void FacultyMember::saveInFile(std::ofstream& file)
{
   
    if (file.is_open())
    {
        file << "Name: " << Person::getName() << std::endl;
        file << "Number: " << Student::getNumber() << std::endl;
        file << "Salary: " << Lecturer::getSalary() << std::endl;
        file.close();
    }
}
void FacultyMember::readFromFile(std::ifstream &file)
{
    if (file.is_open())
    {
        file >> this->name >> this->number >> this->salary;
        file.close();
    }
   
}