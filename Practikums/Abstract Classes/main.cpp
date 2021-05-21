#include "Car.h"
#include "SportsCar.h"
#include "FamilyCar.h"

int main()
{
    SportsCar sp(300,47852);
    sp.startEngine();
    sp.accelerate(10);
    sp.stopEngine();
    
    return 0;
}