#include "Utility.h"

bool Utility::isGoodForGaming(const Computer computer)
{
    return ((computer.getProcessor() == "i5" || computer.getProcessor() == "i7") && (computer.getVideo() == "3060" || computer.getVideo() == "3070" || computer.getVideo() == "3080" || computer.getVideo() == "3090") && (computer.getHardDrive() >= 512));
}
bool Utility::isGoodForTravel(const Computer computer)
{
    return (computer.getWeight() < 2.5 && computer.getBatteryLife() > 6);
}