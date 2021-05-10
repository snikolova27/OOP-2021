#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>

class Doctor
{
    protected:
    std::string name;

    public:
    Doctor(std::string _name);
    void performOperation();
};
#endif