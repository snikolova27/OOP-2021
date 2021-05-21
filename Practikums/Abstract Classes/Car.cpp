#include "Car.h"

Car::Car(double maxSpeed, double price) 
{
    this->maxSpeed = maxSpeed;
    this->price = price;
}
void Car::startEngine()
{
    std::cout << "Engine has been started" << std::endl;
    this->engine.start();
}
void Car::stopEngine()
{
    std::cout << "Engine has been stopped" << std::endl;
    this->engine.stop();
}
void Car::stopMovement()
{
    this->currentSpeed = 0;
    
}