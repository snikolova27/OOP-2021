#pragma once
#include "Car.h"

class SportsCar : public Car
{
private:
    static const double MAX_AC_SPEED_SC;
    static const double STANDART_CURRENT_SPEED_SC;

public:
    SportsCar(double maxSpeed, double price);
    void accelerate(double speed);
    void startMovement();
};
