#include <iostream>
#include <cstring>
#include "functions.h"

char toUpper(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        ch -= ('a' - 'A');
    }
    return ch;
}

void printMenu()
{
    std::cout << '\t' << "Menu" << std::endl;
    std::cout << "1. Add a student to the list" << std::endl;
    std::cout << "2. Print the students born in March" << std::endl;
    std::cout << "3. Print the student with the highest average grade" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void Grade::getGrade()
{
    char buffer[100];
    size_t len;

    std::cout << "Enter name of subject: ";
    std::cin.getline(buffer, 100);
    len = strlen(buffer);
    Subject = new (std::nothrow) char[len];
    stpcpy(Subject, buffer);

    std::cout << "Enter grade for this subject; ";
    std::cin >> grade;
    std::cin.ignore();
}

void Student::readStudent()
{
    char buffer[100];
    size_t len;

    std::cout << "Enter names of the student: ";
    std::cin.getline(buffer, 100);
    len = strlen(buffer);
    name = new (std::nothrow) char[len];
    if (!name)
    {
        std::cout << "Memory allocation problem " << std::endl;
        return;
    }
    strcpy(buffer, name);

    std::cout << "Enter EGN of student: ";
    std::cin >> EGN;
    std::cin.ignore();

    std::cout << "Enter the faculty number of the student; ";
    std::cin >> facultyNum;
    std::cin.ignore();

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Subject №" << i + 1 << std::endl;
        grades[i].getGrade();
    }
}

void Student::formatname()
{
    name[0] = toUpper(name[0]);
    int formattedNames = 1;
    int idx = 1;
    while (formattedNames < 3)
    {
        if (name[idx] == ' ')
        {
            name[idx + 1] = toUpper(name[idx + 1]);
            formattedNames++;
            idx++;
        }
        idx++;
    }
}

double Student::avgGrade()
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += grades[i].grade;
    }
    return sum / 5;
}

char *Student::firstLastName()
{
    char buffer[100];
    int idxBuffer = 0, i = 0;
    bool scndName = false;

    while (name[i])
    {
        if (!scndName)
        {
            buffer[idxBuffer] = name[i];
            idxBuffer++;
        }
        if (name[i] == ' ')
        {
            scndName = !scndName;
        }
        i++;
    }

    size_t len;
    len = strlen(buffer);

    char *result = new (std::nothrow) char[len];
    strcpy(result, buffer);

    return result;
}

void ListofStudents::addStudent()
{
    Student newStudent;
    newStudent.readStudent();
    newStudent.formatname();

    List[cntOfStudents++] = newStudent;
    std::cout << "Student has been added to the list" << std::endl;
}

void ListofStudents::printMarchStudents()
{
    if (cntOfStudents == 0)
    {
        std::cout << "There are no students in the list" << std::endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < cntOfStudents; i++)
    {
        if (List[i].EGN[3] == '3')
        {
            char *name = List[i].firstLastName();
            std::cout << name << ", average grade is " << List[i].avgGrade() << std::endl;
            found = true;
            delete[] name;
        }
    }

    if (!found)
    {
        std::cout << "There are no students born in March" << std::endl;
    }
}

void ListofStudents::highestAvgStudent()
{
    if (cntOfStudents == 0)
    {
        std::cout << "There are no students in the list" << std::endl;
        return;
    }

    double maxGrade = List[0].avgGrade();
    int maxIdx = 0;

    for (int i = 1; i < cntOfStudents; i++)
    {
        if (List[i].avgGrade() > maxGrade)
        {
            maxGrade = List[i].avgGrade();
            maxIdx = i;
        }
    }
    char *name = List[maxIdx].firstLastName();
    std::cout << name << ", grade: " << maxGrade << std::endl;
}

void ListofStudents::clearmemory()
{
    for (int i = 0; i < cntOfStudents; i++)
    {
        delete[] List[i].name;
        for (int j = 0; j < 5; j++)
        {
            delete[] List[i].grades[j].Subject;
        }
    }
}
