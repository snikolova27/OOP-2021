#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>

class Student
{
private:
    std::string name;
    std::string fn;
    bool signedUp;

    void copy(const Student &other);

public:
    Student(const Student &other);
    Student(std::string _name, std::string _fn, bool _signedUp);

    std::string getName() const;
    std::string getFn() const;
    bool getSignedUp() const;

    Student &operator=(const Student &other);

    friend std::ostream &operator<<(std::ostream &out, Student &student);
};
#endif