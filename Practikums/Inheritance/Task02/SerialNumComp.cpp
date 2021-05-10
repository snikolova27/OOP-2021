#include "SerialNumComp.h"

int ComputerSerialNumberGenerator::generatedNumber = 100;

int ComputerSerialNumberGenerator::generateSerialNumber()
{
    return generatedNumber++;
}