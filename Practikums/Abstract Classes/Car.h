// #ifndef CAR_H
// #define CAR_H
#pragma once
#include "Vehicle.h"
#include "Engine.h"
#include <iostream>

class Car : public Vehicle
{
private:
    double price;

protected:
    double currentSpeed;
    double maxSpeed;
    Engine engine;

public:
    Car(double maxSpeed, double price);
    void startEngine();
    void stopEngine();
    void stopMovement();
    virtual void accelerate(double speed) = 0;
};
//#endif