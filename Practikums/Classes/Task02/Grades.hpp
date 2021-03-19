#ifndef GRADES_H
#define GRADES_H

struct Grades
{
    char *subject;
    double grade;

    void input();
    void clearDynamic();
};

#endif