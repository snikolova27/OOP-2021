/**
 * \ Structure working with a list of students and their graades
 * \ author S. Nikolova
  */

#ifndef FUNC_H
#define FUNC_H

const int MAX_NUMBER_STUDENTS = 1000;  //!< stores the maximum number of students in the list

struct Grade
{
    char* Subject;  //!< stores the name of the subject
    short grade;    //!< stores the grade for the subject entered

//! Function to get the grade for said subject
    void getGrade();    
};

struct Student
{
    char* name;     //!< stores the 3 names of the student
    char EGN [10];  //! stores the EGN of the student
    char facultyNum [5];    //!< stores the faculty number of the student
    Grade grades[5];        //!< stores the grades of the student

//! Function to get the details about a student fro the console
    void readStudent();

//! Function to capitalise all first letters of the 3 names of the student
    void formatname();

//! Function to calculate the average grade of a student
    double avgGrade();

//! Function to get the first and last name of a student
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