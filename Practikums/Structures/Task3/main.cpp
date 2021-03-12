#include <iostream>
#include "functions.h"

int main()
{
    ListofStudents Students;
    int option;

    do
    {
        printMenu();
        std::cin >> option;
        std::cin.ignore();

        switch (option)
        {
        case 1:
            Students.addStudent();
            break;
        case 2:
            Students.printMarchStudents();
            break;
        case 3:
            Students.highestAvgStudent();
            break;
        }

    } while (option);

    Students.clearMemory();
    return 0;
}