#ifndef PROCCESOR_H
#define PROCCESOR_H
#include "Details.h"

class Processor : public Details
{
    private:
    std::string description;
   public:
    Processor(const std::string _desc);
    std::string getProcessor();
};
#endif