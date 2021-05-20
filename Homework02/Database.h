#ifndef  DATABASE_H
#define DATABASE_H
#include "Person.h"
#include "Registration.h"
#include "Vehicle.h"

class DataBase
{
    private:
    std::vector <Person> people;
    std::vector <Vehicle> vehicles;

    //validate Person id

    public:
    void addPeson(); //todo
    void addVehicle(); //todo
    void assignVehicleToPerson() //todo
    void removeVehicleToPerson() //todo
};
#endif