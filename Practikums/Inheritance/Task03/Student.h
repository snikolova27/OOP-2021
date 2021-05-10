#ifndef STUDENT_H
#define STUDENT_H
#include "Human.h"

class Student : public Human
{
    private:
    int fn;
    static int cnt;
    std::string major;

    public:
    Student(std::string _firstName, std::string _lastName, int _age, std::string _major);\
    void print();

};
#endif