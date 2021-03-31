#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Student.hpp"

const int MAX_NUM_STUDENTS = 100;

class University
{
    private:
    Student listOfStudets [MAX_NUM_STUDENTS];

    public:
    void CreateStudents(Student* listOfStudents);
    void clearDynamic();
    void printAll();
    void 
};

#endif