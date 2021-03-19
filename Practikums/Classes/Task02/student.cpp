#include <iostream>
#include <cmath>
#include <cstring>
#include "Student.hpp"
#include "Grades.hpp"

void Student::input()
{
    size_t len;
    char buffer[100];

    std::cout << "Enter name of student: ";
    std::cin.getline(buffer, 100);
    len = strlen(buffer);
    name = new (std::nothrow) char[len + 1];
    if (!name)
    {
        std::cout << "Memory problem";
    }
    strcpy(name, buffer);
    name[len] = '\0';

    std::cout << "Enter EGN of student: ";
    std::cin >> EGN;
    std::cin.ignore();

    std::cout << "Enter faculty number of student: ";
    std::cin >> facultyNum;
    std::cin.ignore();

    std::cout << "Enter grades of student" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        grades[i].Grades::input();
    }
}

double Student::avgGrade()
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += grades[i].grade;
    }
    return sum / 5;
}
void Student::printStudent()
{
    std::cout << "Name of student: " << name << std::endl;
    std::cout << "EGN of student: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << EGN[i];
    }
    std::cout << std::endl;
    std::cout << "Faculty number of student: " << facultyNum << std::endl;
    std::cout << "Average grade: " << Student::avgGrade() << std::endl;
}
void Student::printFacNumAndGrades()
{
    std::cout << "Faculty number of student: " << facultyNum << std::endl;
    std::cout << "Grades: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << grades[i].subject << ": " << grades[i].grade << std::endl;
    }
}
void Student::clearMemory()
{
    delete[] name;
}
