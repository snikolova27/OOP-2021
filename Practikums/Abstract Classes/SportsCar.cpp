#include "SportsCar.h"

const double SportsCar::MAX_AC_SPEED_SC = 100;
const double SportsCar::STANDART_CURRENT_SPEED_SC = 115;

SportsCar::SportsCar(double maxSpeed, double price) : Car(maxSpeed, price)
{
}

void SportsCar::accelerate(double speed)
{
    if (this->currentSpeed + speed > this->maxSpeed || speed > MAX_AC_SPEED_SC)
    {
        std::cout << "Can't go that fast" << std::endl;
        return;
    }
    this->currentSpeed += speed;
}

void SportsCar::startMovement()
{
    this->startEngine();
    this->currentSpeed = STANDART_CURRENT_SPEED_SC;
}