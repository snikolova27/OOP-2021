#include "FamilyCar.h"

const double FamilyCar:: MAX_AC_SPEED_FC = 50;
const double FamilyCar::STANDART_CURRENT_SPEED_FC = 60;

FamilyCar::FamilyCar(double maxSpeed, double price) : Car(maxSpeed, price)
{
}

void FamilyCar::accelerate(double speed)
{
    if (this->currentSpeed + speed > this->maxSpeed || speed > MAX_AC_SPEED_FC)
    {
        std::cout << "Can't go that fast" << std::endl;
        return;
    }
    this->currentSpeed += speed;
}

void FamilyCar::startMovement()
{
    this->startEngine();
    this->currentSpeed = STANDART_CURRENT_SPEED_FC;
}