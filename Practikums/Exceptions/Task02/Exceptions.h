#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class VolumeOverflow : public std::exception
{
    const char* what() const throw()
    {
        return "Volume overeflow";
    }
};

class WeightOverflow : public std::exception
{
    const char* what() const throw()
    {
        return "Weight overflow";
    }
};

#endif