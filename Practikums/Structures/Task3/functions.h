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
    double grade;    //!< stores the grade for the subject entered

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
    Student List [MAX_NUMBER_STUDENTS]; //!< stores the details about each student
    int cntOfStudents = 0;              //!< keeps track of the count of students in the list

//! Function to add a new student to the list
    void addStudent();

//! Function to print the names and average grades of students born in March
    void printMarchStudents();

//! Function to print the names and the average grade of the student with the highest average grade
    void highestAvgStudent();

//! Function to clear the allocated memory for the list of students
    void clearMemory();
};

//! Function to capitalise the first letters of each name of the student
char toUpper(char ch);

//! Function to print the menu at the start of the program
void printMenu();

#endif