#ifndef FUNC_H
#define FUNC_H

const int MAX_NUMBER_STUDENTS = 1000;

struct Grade
{
    char* Subject;
    short grade;

    void getGrade();
};

struct Student
{
    char* name;
    char EGN [10];
    char facultyNum [5];
    Grade grades[5];

    void readStudent();
    void formatname();
    double avgGrade();
    char* firstLastName();
};

struct ListofStudents
{
    Student List [MAX_NUMBER_STUDENTS];
    int cntOfStudents = 0;

    void addStudent();
    void printMarchStudents();
    void highestAvgStudent();
    void clearMemory();
};

char toUpper(char ch);

void printMenu();

#endif