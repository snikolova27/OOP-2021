#ifndef FUNC_H
#define FUNC_H

struct Runner
{
    char name[100]; //!< stores the name of the runner
    double times [12]; //!< stores the times for each 42km race

//! Function to get the details about a runner from the console
    void getRunner();

//! Function to calculate the average speed for a runner across the 12 months
    double avgSpeed();

//! Function to capitalise the intial letters of each name of the runner
    void formatName();

//! Function to calculate how many times runner A has beaten runner B in a race
    int beatRunner(Runner B); 
};

//! Function to capitalise a letter
char toUpper(char ch);

#endif