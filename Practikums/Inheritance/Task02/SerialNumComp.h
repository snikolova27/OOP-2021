#ifndef SERIAL_NUM_COMPUTER
#define SERIAL_NUM_COMPUTER

class ComputerSerialNumberGenerator
{
private:
    static int generatedNumber;

public:
    static int generateSerialNumber();
};
#endif
