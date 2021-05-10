#ifndef FACULTY_MEMBER_H
#define FACULTY_MEMBER_H
#include "Lecturer.h"
#include "Student.h"
#include "Person.h"

class FacultyMember : public Student, public Lecturer
{
public:
    FacultyMember();
    FacultyMember(std::string name, int number, double salary);
    void print();
    friend std::istream &operator>>(std::istream &in, FacultyMember &facultyMember);
    void saveInFile(std::ofstream &file);
    void readFromFile(std::ifstream &file);
};
#endif