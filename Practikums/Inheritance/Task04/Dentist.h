#ifndef DENTIST_H
#define DENTIST_H
#include "Doctor.h"

class Dentist : public Doctor
{
    public:
    Dentist(std::string _name);
    void performOperation();
};

#endif