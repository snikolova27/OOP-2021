#include "Processor.h"

Processor::Processor(const std::string _desc) : Details()
{
    this->description = _desc;
}
std::string Processor::getProcessor()
{
    return this->description;
}