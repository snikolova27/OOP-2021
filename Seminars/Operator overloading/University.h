#ifndef UNI_H
#define UNI_H
#include "Student.h"

class University
{
private:
    Student **students;
    std::size_t capacity;
    std::size_t size;

    void resize();
    void deallocate();
    void copy(const University &other);

public:
    University();
    University(const University &other);
    ~University();

    void addStudent(std::string _name, std::string _fn, bool _signedUp);
    void addStudent(const Student &student);

    std::size_t getSize() const;
    
    University &operator=(const University &other);
    University operator+(const University &other);
    Student &operator[](std::size_t position);
};

#endif