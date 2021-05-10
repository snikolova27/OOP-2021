#ifndef RAM_H
#define RAM_H
#include "Details.h"

class RAM : public Details
{
    private:
    std::string description;
    public:
    RAM(const std::string _desc);
    std::string getRam();
};
#endif