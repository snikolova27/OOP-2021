#pragma once
#include "Car.h"


class FamilyCar : public Car
{
    private:
    static const double MAX_AC_SPEED_FC;
    static const double STANDART_CURRENT_SPEED_FC;

public:
    FamilyCar(double maxSpeed, double price);
    void accelerate(double speed);
    void startMovement();
};