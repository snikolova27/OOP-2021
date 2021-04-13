#include "Garage.h"

//------------ private methods ------------
void Garage::deallocate()
{
    if (this->cars)
    {
        delete[] this->cars;
        this->cars = nullptr;
    }
}
void Garage::resize()
{
    Vehicle *old = this->cars;

    this->capacity *= RESIZE_STEP;
    this->cars = new (std::nothrow) Vehicle[this->capacity];

    if (!this->cars)
    {
        std::cout << "Problem allocating mmemory for more cars" << std::endl;
        return;
    }
    for (int i = 0; i < this->size; i++)
    {
        this->cars[i] = old[i];
    }
    delete[] old;
}
void Garage::copy(const Garage &other)
{
    if (other.cars == nullptr)
    {
        this->cars == nullptr;
        this->size = 0;
        this->capacity = 0;
        return;
    }
    this->cars = new (std::nothrow) Vehicle[other.size];
    if (this->cars)
    {
        for (int i = 0; i < other.size; i++)
        {
            this->cars[i] = other.cars[i];
            this->size = other.size;
            this->capacity = other.capacity;
        }
    }
    else
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
}
Garage::Garage(std::size_t size)
{
    if (size)
    {
        this->cars = new (std::nothrow) Vehicle[size];
        if (this->cars)
        {
            this->capacity = size;
            this->size = size;
        }
        else
        {
            std::cout << "Problem allocating memory" << std::endl;
            return;
        }
    }
}

//------------ constructors ------------
Garage::Garage(const Garage &other)
{
    this->copy(other);
}
std::size_t Garage::getSize() const
{
    return this->size;
}
//------------ destructor ------------
Garage::~Garage()
{
    this->deallocate();
}
//------------ class functions ------------

//----------- operator overloading ------------
