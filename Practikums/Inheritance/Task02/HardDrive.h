#ifndef HARD_DRIVE_H
#define HARD_DRIVE_H
#include "Details.h"

class HardDrive : public Details
{
private:
    std::string desciption;

public:
    HardDrive(const std::string desc);
    std::string getDesc();
};
#endif