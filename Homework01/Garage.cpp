#include "Garage.h"
#include <cstring>
#include <cassert>

//------------ private methods ------------
// Functions used for executing the class and costructor/destructor functions easier
void Garage::deallocate()
{
    if (this->vehicles)
    {
        for (size_t i = 0; i < this->capacity; i++)
        {
            this->vehicles[i] = nullptr;
        }
        delete[] this->vehicles;
    }
}
void Garage::copy(const Garage &other)
{
    if (other.vehicles == nullptr)
    {
        this->vehicles == nullptr;
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

    for (int i = 0; i < other.capacity; i++)
    {
        this->vehicles[i] = other.vehicles[i];
    }
    this->used = other.used;
    this->capacity = other.capacity;
    this->cntOfVehicles = other.cntOfVehicles;
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

        for (size_t i = 0; i < this->capacity; i++)
        {
            vehicles[i] = nullptr;
        }
    }
    std::cout << "Garage with a capacity of " << size << "has been created." << std::endl;
}

//------------ constructors ------------
Garage::Garage(const Garage &other)
{
    this->copy(other);
}
std::size_t Garage::getSize() const
{
    return this->cntOfVehicles;
}
//------------ destructor ------------
Garage::~Garage()
{
    this->deallocate();
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

    std::cout << "Vehicle has been added to the garage" << std::endl;
}
void Garage::erase(const char *_licensePlate)
{
    if (this->empty())
    {
        std::cout << "Garage is already empty." << std::endl;
        return;
    }

    int searchIdx = -1;
    for (size_t i = 0; i < this->cntOfVehicles; i++)
    {
        if (strcmp(_licensePlate, this->vehicles[i]->registration()) == 0)
        {
            searchIdx = i;
            break;
        }
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

    std::cout << "The vehicle with " << _licensePlate << " licesence plate has been taken out of the garage" << std::endl;
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
    for (size_t i = 0; i < this->capacity; i++)
    {
        this->vehicles[i] = nullptr;
    }
    this->used = 0;
    this->cntOfVehicles = 0;

    std::cout << "Garage has been cleared" << std::endl;
}
const Vehicle *Garage::find(const char *_licensePlate) const
{
    int searchIdx = -1;

    for (size_t i = 0; i < this->cntOfVehicles; i++)
    {
        if (strcmp(_licensePlate, this->vehicles[i]->registration()) == 0)
        {
            searchIdx = i;
            break;
        }
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
std::ostream &operator<<(std::ostream &out, const Garage &garage) //used for easier printing of the contentes of the garage
{
    std::cout << "Capacity of garage: " << garage.capacity << std::endl;
    std::cout << "Current count of vehicles inside the garage: " << garage.cntOfVehicles << std::endl;
    std::cout << "Current ocupied space: " << garage.used << std::endl;

    if (!garage.empty())
    {
        std::cout << std::endl;

        if (garage.capacity - garage.used > 0)
        {
            std::cout << "There are " << garage.capacity - garage.used << " free parking space(s) in the garage" << std::endl;
        }

        std::cout << "=============" << "Vehichles parked in the garage" << "=============" << std::endl;

        for (size_t i = 0; i < garage.cntOfVehicles; i++)
        {
            std::cout << "Vehicle " << i + 1 << std::endl;
            std::cout << *(garage.vehicles[i]);
        }
    }
    return out;
}