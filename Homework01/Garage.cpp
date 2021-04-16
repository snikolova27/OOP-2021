#include "Garage.h"
#include <cstring>
#include <cassert>

//------------ private methods ------------
// Functions used for executing the class and costructor/destructor functions easier
void Garage::deallocate()
{
    if (this->vehicles)
    {
        size_t i = 0;
        while (i < this->capacity)
        {
            this->vehicles[i] = nullptr;
            i++;
        }
        delete[] this->vehicles;
    }
}
void Garage::copy(const Garage &other)
{
    if (other.vehicles == nullptr)
    {
        this->vehicles = other.vehicles;
        this->used = 0;
        this->capacity = 0;
        this->cntOfVehicles = 0;
        return;
    }
    try
    {
        this->vehicles = new Vehicle *[other.capacity];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    size_t i = 0;
    while (i < other.capacity)
    {
        this->vehicles[i] = other.vehicles[i];
        i++;
    }
    this->used = other.used;
    this->capacity = other.capacity;
    this->cntOfVehicles = other.cntOfVehicles;
}
//------------ constructors ------------
Garage::Garage(const Garage &other)
{
    this->copy(other);
}
Garage::Garage(std::size_t size)
{
    if (size)
    {
        try
        {
            this->vehicles = new Vehicle *[size];
        }
        catch (std::bad_alloc &e)
        {
            std::cout << "Problem allocating memory" << std::endl;
            return;
        }

        this->capacity = size;
        this->used = 0;
        this->cntOfVehicles = 0;

        size_t i = 0;
        while (i < this->capacity)
        {
            vehicles[i] = nullptr;
            i++;
        }
        std::cout << "Garage with a capacity of " << size << " has been created." << std::endl;
    }
    else
    {
        this->vehicles = nullptr;
        this->capacity = 0;
        this->used = 0;
        this->cntOfVehicles = 0;
    }
}
//------------ getters ------------
std::size_t Garage::getSize() const
{
    return this->cntOfVehicles;
}

//------------ class functions ------------
void Garage ::insert(Vehicle &v) //strong exception guarantee
{
    try
    {
        if (this->find(v.registration()))
        {
            throw std::invalid_argument("There is already a vehicle in the garage with such license plate");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    try
    {
        if ((this->used + v.space()) > this->capacity)
        {
            throw std::overflow_error("There isn't enough space left in the garage for this vehicle");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    this->vehicles[this->cntOfVehicles++] = &v;
    this->used += v.space();

    std::cout << "Vehicle with license plate " << v.registration() << " has been added to the garage" << std::endl;
}
void Garage::erase(const char *_licensePlate)
{
    if (this->empty())
    {
        std::cout << "Garage is already empty." << std::endl;
        return;
    }

    int searchIdx = -1;
    size_t i = 0;
    while (i < this->cntOfVehicles)
    {
        if (strcmp(_licensePlate, this->vehicles[i]->registration()) == 0)
        {
            searchIdx = i;
            break;
        }
        i++;
    }
    if (searchIdx == -1)
    {
        std::cout << "There is no vehicle with such license plate" << std::endl;
        return;
    }

    this->used -= this->vehicles[searchIdx]->space();

    Vehicle *temp = this->vehicles[this->cntOfVehicles - 1];
    this->vehicles[this->cntOfVehicles - 1] = this->vehicles[searchIdx];
    this->vehicles[searchIdx] = temp;
    this->vehicles[this->cntOfVehicles - 1] = nullptr;
    this->cntOfVehicles -= 1;

    std::cout << "The vehicle with " << _licensePlate << " license plate has been taken out of the garage" << std::endl;
}
const Vehicle &Garage::at(std::size_t pos) const
{
    if (pos < this->cntOfVehicles)
    {
        return *(this->vehicles[pos]);
    }
    else
    {
        throw std::out_of_range("Such position doesn't exist in the garage");
    }
}
bool Garage::empty() const
{
    return this->cntOfVehicles == 0;
}
void Garage::clear()
{
    if (this->cntOfVehicles == 0)
    {
        return;
    }
    size_t i = 0;
    while (i < this->capacity)
    {
        this->vehicles[i] = nullptr;
        i++;
    }
    this->used = 0;
    this->cntOfVehicles = 0;

    std::cout << "Garage has been cleared" << std::endl;
}
const Vehicle *Garage::find(const char *_licensePlate) const
{
    if (_licensePlate == nullptr || strcmp(_licensePlate, "") == 0)
    {
        return nullptr;
    }
    int searchIdx = -1; //invalid index

    size_t i = 0;
    while (i < this->cntOfVehicles)
    {
        if (strcmp(_licensePlate, this->vehicles[i]->registration()) == 0)
        {
            searchIdx = i;
            break;
        }
        i++;
    }
    if (searchIdx == -1) //means there isn't a car with such license plate in the garage
    {
        return nullptr;
    }
    return this->vehicles[searchIdx];
}

//----------- operator overloading ------------
Garage &Garage::operator=(const Garage &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }
    return *this;
}
const Vehicle &Garage::operator[](std::size_t pos) const //assert pos
{
    assert(pos < this->cntOfVehicles);
    return *(this->vehicles[pos]);
}
void Garage::print()
{
    std::cout << "Garaga capacity: " << this->capacity << std::endl;
    std::cout << "Current count of vehicles inside the garage: " << this->cntOfVehicles << std::endl;
    std::cout << "Current ocupied space: " << this->used << std::endl;

    if (!this->empty())
    {
        std::cout << std::endl;

        if (this->capacity - this->used > 0)
        {
            std::cout << "There are " << this->capacity - this->used << " free parking space(s) in the garage" << std::endl;
        }

        std::cout << std::endl;
        std::cout << "============="
                  << "Vehichles parked in the garage"
                  << "=============" << std::endl;
        std::cout << std::endl;

        size_t i = 0;
        while (i < this->cntOfVehicles)
        {
            std::cout << "Vehicle " << i + 1 << " with license plate " << this->vehicles[i]->registration() << std::endl;
            i++;
        }
    }
}
//------------ destructor ------------
Garage::~Garage()
{
    this->deallocate();
}