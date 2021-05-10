#include "Student.h"
#include <iostream>

int main()
{
    Student s1("Sonya", "Nikolova", 19, "CS");
    Student s2("Kosyo" ,"Nikolov", 22, "SE");
    s1.print();
    std::cout << std::endl;
    s2.print();
}