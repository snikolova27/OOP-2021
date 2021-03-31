#include <iostream>
#include <cstring>
#include "Grades.hpp"

void Grades::input()
{
    char buffer[100];
    size_t len;

    std::cout << "Enter name of subject: ";
    std::cin.getline(buffer, 100);
    len = strlen(buffer);
    subject = new (std::nothrow) char[len + 1];
    if (!subject)
    {
        std::cout << "Memory problem";
        return;
    }
    strcpy(subject, buffer);
    subject[len] = '\0';

    std::cout << "Enter grade: ";
    std::cin >> grade;
    std::cin.ignore();

    if (grade < 2 || grade>6)
    {
        std::cout << "Grade should be greater than or equal to 2 and not greater than 6";
        return;
    }
}
