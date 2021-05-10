#include "RAM.h"

RAM::RAM(const std::string _desc) :Details()
{
    this->description = _desc;
}
 std::string RAM::getRam()
 {
     return this->description;
 }