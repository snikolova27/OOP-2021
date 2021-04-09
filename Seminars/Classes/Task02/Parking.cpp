#include "Parking.h"
#include <cstring>
#include <iostream>

void Parking::setFirmName(const char *_firmName)
{
    if (this->firmName)
    {
        delete[] this->firmName;
    }
    firmName = new (std::nothrow) char[strlen(_firmName) + 1];
    if (this->firmName)
    {
        strcpy(this->firmName, _firmName);
    }
}
void Parking::setOwnerOfParking(const Person &_owner)
{
    this->ownerOfParking = _owner;
}

void Parking::setArrayOfCars(const Car *_cars, const size_t _size)
{
    if (this->cars)
    {
        delete[] this->cars;
    }
    this->cars = (_size > this->capacity) ? (new Car[_size]) : (new Car[this->capacity]);
    for (int i = 0; i < _size; i++)
    {
        this->cars[i] = _cars[i];
    }
}

void Parking::setCapacity(const size_t _capacity)
{
    this->capacity = _capacity;
}

char *Parking::getFirmmName() const
{
    return this->firmName;
}
Person Parking::getOwner() const
{
    return this->ownerOfParking;
}
Car *Parking::getCars() const
{
    return this->cars;
}
size_t Parking::getSize() const
{
    return this->size;
}
size_t Parking ::getCapacity() const
{
    return this->capacity;
}

void Parking::deallocate()
{
    if (this->firmName)
    {
        delete[] this->firmName;
    }

    if (this->cars)
    {
        delete[] this->cars;
    }
}
void Parking::copy(const Parking &other)
{
    this->firmName = new (std::nothrow) char[strlen(other.firmName) + 1];
    strcpy(this->firmName, other.firmName);

    this->ownerOfParking = other.ownerOfParking;
    this->capacity = other.capacity;

    this->cars = (other.size > this->capacity) ? (new (std::nothrow) Car[other.size]) : (new (std::nothrow) Car[this->capacity]);
    for (int i = 0; i < other.size; i++)
    {
        this->cars[i] = other.cars[i];
    }
}
void Parking::resize()
{
    this->capacity *= INCREASE_STEP;

    Car *newCars = new (std::nothrow) Car[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        newCars[i] = this->cars[i];
    }
    delete[] this->cars;

    this->cars = newCars;
}

Parking::Parking() : ownerOfParking()
{
    this->firmName = nullptr;
    this->capacity = INITAL_CAPACITY;
    this->cars = new (std::nothrow) Car[this->capacity];
    this->size = 0;
}
Parking::Parking(const char *_firmName, const Person &_owner, const Car *_cars, const size_t _size, const size_t _capacity)
{
    this->firmName = new char[strlen(firmName) + 1];
    strcpy(this->firmName, firmName);

    this->ownerOfParking = _owner;
    this->capacity = _capacity;

    this->cars = (_size > this->capacity) ? (new Car[_size]) : (new Car[this->capacity]);
    for (int i = 0; i < _size; ++i)
    {
        this->cars[i] = _cars[i];
    }
}
Parking::Parking(const Parking &other)
{
    copy(other);
}

Parking &Parking ::operator=(const Parking &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

Parking::~Parking()
{
    deallocate();
}

void Parking::addCar(const Car &car)
{
    if (this->size == this->capacity)
    {
        resize();
    }

    for (int i = 0; i < this->size; i++)
    {
        if (strcmp(cars[i].getLicensePlate(), car.getLicensePlate()) == 0)
        {
            std::cout << "This car is already in the parking" << std::endl;
        }
        this->cars[this->size++] = car;
    }
}

void Parking ::removeCar(const int index)
{
    if (index >= this->size)
    {
        std::cout << "There is no car with such index" << std::endl;
        return;
    }

    for (int i = index; i < this->size - 1; i++)
    {
        this->cars[i] = this->cars[i + 1];
    }

    --this->size;
}

void Parking::printParking()
{
    std::cout << "Size: " << this->size << std::endl;
    std::cout << "Capacity: " << this->capacity << std::endl;
    std::cout << ((double)this->size / (double)this->capacity) * 100 << "% full" << std::endl;
    for (int i = 0; i < this->size; ++i)
    {
        std::cout << "Car #" << i + 1 << ":" << std::endl;
        cars[i].print();
    }
}
Person Parking::printOwnerOfCar(const char *licensePlate)
{
    Person result;
    for (int i = 0; i < this->size; ++i)
    {
        if (strcmp(licensePlate, cars[i].getLicensePlate()) == 0)
        {
            result = cars[i].getOwner();
        }
    }

    return result;
}
Car *Parking::CarsOfOwner(const Person &owner, size_t &count)
{
    count = 0;
    for (int i = 0; i < this->size; ++i)
    {
        if (cars[i].getOwner() == owner)
        {
            ++count;
        }
    }

    if (count == 0)
    {
        std::cout << "No cars found" << std::endl;
        return nullptr;
    }

    Car *result = new Car[count];
    int index = 0;
    for (int i = 0; i < this->size; ++i)
    {
        if (cars[i].getOwner() == owner)
        {
            result[index++] = cars[i];
        }
    }

    return result;
}
