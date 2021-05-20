#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <iostream>

const int MIN_REG_LEN = 7;
const int MAX_REG_LEN = 8;

class Registration
{
private:
    char registration[9]; // terminating null at the end

    bool isValid(const char* reg); 

    //helper functions
    bool isLetter(char c);
    bool isDigit(char c);

public:
    Registration(const char *registration);

    bool operator==(const Registration &other);

    const char *getRegistration() const;
};
#endif