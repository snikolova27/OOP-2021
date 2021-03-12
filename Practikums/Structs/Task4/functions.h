#ifndef FUNC_H
#define FUNC_H

struct Runner
{
    char name[100];
    double times [12];

    void getRunner();
    double avgSpeed();
    void formatName();
    int beatRunner(Runner B); //how many times the first runenr has beat the second

};
char toUpper(char ch);

#endif