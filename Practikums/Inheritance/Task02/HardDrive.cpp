#include "HardDrive.h"

HardDrive::HardDrive(const std::string _desc) : Details()
{
    this->desciption = _desc;
}
std::string HardDrive::getDesc()
{
    return this->desciption;
}