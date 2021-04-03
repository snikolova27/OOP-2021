#ifndef STUDENT_H
#define STUDENT_H

#include "Grades.h"
#include <iostream>

class Student
{
private:
    char* name;
    char EGN[11];
    char facultyNumber[7];
    Grades grades[5];

    void deallocateMemory();
    void copy(const Student& other);

public:
    Student();
    Student(const char* name, const char* EGN, const char* FN, 
            double grade1, double grade2, double grade3, double grade4, double grade5);
    Student(const Student& other);

    Student& operator = (const Student& other);
    bool operator == (const Student& other);
    bool operator != (const Student& other);

    void input();
    double getAverageGrade();
    void print();
    void printFNAndGrades();

    void copyStudent(Student& student);

    char* getName();
    char* getFN();

    void setName(const char* wantedName);
    void setEGN(const char* wantedEGN);
    void setFacultyNumber(const char* wantedFN);
    void setGrades(Grades* wantedGrades);

    friend std::ostream& operator << (std::ostream& out, Student& student);

    ~Student();
};

#endif