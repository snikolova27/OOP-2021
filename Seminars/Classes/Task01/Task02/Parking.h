#ifndef PARKING_H
#define PARKING_H

#include "Car.h"
#include "Person.h"

const int INITAL_CAPACITY = 2;
const int INCREASE_STEP = 2;

class Parking
{
    private:
    char* firmName;
    Person ownerOfParking;
    Car* cars;
    size_t size;
    size_t capacity;

    void deallocate();
    void copy(const Parking& other);
    void resize();

    public:

    void setFirmName(const char* _firmName);
    void setOwnerOfParking(const  Person& _owner);
    void setArrayOfCars(const Car* _cars, const size_t size);
    void setCapacity(const size_t _capacity);

    char* getFirmmName() const;
    Person getOwner() const;
    Car* getCars() const;
    size_t getSize() const;
    size_t getCapacity() const;

    Parking();
    Parking(const char* _firmName, const Person& _owner, const Car* _cars, const size_t _size, const size_t _capacity);
    Parking(const Parking& other);
    Parking& operator=(const Parking& other);

    void addCar(const Car& _car);
    void removeCar(const int index);
    void printParking();
    Person printOwnerOfCar( const char* licensePlate);
    Car* CarsOfOwner(const Person& owner, size_t& count);

    ~Parking();
};
#endif