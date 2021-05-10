#include "Computer.h"
#include <iostream>

static int cnt = 100;

Computer::Computer(const std::string _hard, const std::string _ram, const std::string _video, const std::string _processor)
    : hardDrive(_hard), ram(_ram), video(_video), processor(_processor)
{
     this->serialNumber = ComputerSerialNumberGenerator::generateSerialNumber();
}

void Computer::print()
{
    std::cout << "Serial number: " << this->serialNumber << std::endl;
    std::cout << "Hard drive: " << this->hardDrive.getDesc() << std::endl;
    std::cout << "RAM: " << this->ram.getRam() << std::endl;
    std::cout << "Video: " << this->video.getVideo() << std::endl;
    std::cout << "Processor: " << this->processor.getProcessor() << std::endl;
}