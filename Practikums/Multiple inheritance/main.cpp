#include "facultyMember.h"
#include <iostream>
#include <fstream>

int main()
{
    FacultyMember fm("Sam", 214, 4521.2);
    fm.print();

    // write
    std::string fileName;
    std::cout << "Enter output file name: ";
    getline(std::cin, fileName);
    std::ofstream fileTo(fileName);
    fm.saveInFile(fileTo);
    fileTo.close();

    // read
    std::string fileName2;
    std::cout << "Enter input file name: ";
    getline(std::cin, fileName2);
    std::ifstream fileFrom(fileName2);
    FacultyMember fm2;
    fm2.readFromFile(fileFrom);
    fileFrom.close();

    fm.print();
    fm2.print();

    return 0;
}