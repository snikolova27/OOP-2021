#ifndef COMPUTER_H
#define COMPUTER_H
#include "HardDrive.h"
#include "RAM.h"
#include "Video.h"
#include "Processor.h"
#include "SerialNumComp.h"

class Computer
{
private:
    HardDrive hardDrive;
    RAM ram;
    Video video;
    Processor processor;
    int serialNumber;

public:
    Computer(const std::string _hard, const std::string _ram, const std::string _video, const std::string _processor);
    void print();
};
#endif