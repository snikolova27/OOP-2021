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

char* Student::getName()
{
    return this->name;
}

char* Student::getFN()
{
    return this->facultyNum;
}

void Student::setName(const char* wantedName)
{
    size_t size = strlen(wantedName);
    this->name = new(std::nothrow) char[size + 1];
    if (!this->name)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->name, wantedName);
    this->name[size] = '\0';
}

void Student::setEGN(const char* wantedEGN)
{
    strcpy(this->EGN, wantedEGN);
    this->EGN[strlen(wantedEGN)] = '\0';
}

void Student::setFacultyNumber(const char* wantedFN)
{
    strcpy(this->facultyNum, wantedFN);
    this->facultyNum[strlen(wantedFN)] = '\0';
}

void Student::setGrades(Grades* wantedGrades)
{
    for (int i = 0; i < 5; ++i)
    {
        size_t size = strlen(wantedGrades[i].subject);
        this->grades[i].subject = new(std::nothrow) char[size + 1];
        if (!this->grades[i].subject)
        {
            std::cout << "Memory problem!" << std::endl;
            return;
        }
        strcpy(this->grades[i].subject, wantedGrades[i].subject);
        this->grades[i].subject[size] = '\0';
        
        this->grades[i].grade = wantedGrades[i].grade;
    }
}
void Student::copyStudent(Student& student)
{
    student.setName(this->name);
    student.setEGN(this->EGN);
    student.setFacultyNumber(this->facultyNum);
    student.setGrades(this->grades);
}