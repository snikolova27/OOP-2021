#ifndef STUDENT_H
#define STUDENT_H
#include "Grades.hpp"

const int EGN_SIZE = 10;
const int FACULTY_NUM_SIZE = 6;
class Student
{
private:
    char *name;
    char EGN[EGN_SIZE];
    char facultyNum [FACULTY_NUM_SIZE];
    Grades grades[5];

    public:
    void input();
    void printStudent();
    void printFacNumAndGrades();
    double avgGrade();
    void clearMemory();

    void copyStudent(Student& student);

    char* getName();
    char* getFN();

    void setName(const char* wantedName);
    void setEGN(const char* wantedEGN);
    void setFacultyNumber(const char* wantedFN);
    void setGrades(Grades* wantedGrades);

    ~Student();
    
};
#endif