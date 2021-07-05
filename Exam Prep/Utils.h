#ifndef UTILS_H
#define UTILS_H
#include "Cpu.h"
#include "Memory.h"

class Utils
{
public:
    static Component *createComponent();
    static void printMenu();
};

#endif