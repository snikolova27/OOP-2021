#include "Backpack.h"

void Backpack::deallocate()
{
    if (this->items)
    {
        delete[] this->items;
    }
    this->maxWeight = 0;
    this->size = 0;
    this->volume = 0;
    this->items = nullptr;
}

void Backpack::copy(const Backpack &other)
{
    this->size = other.size;
    try
    {
        this->items = new Item[this->size];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < this->size; i++)
    {
        this->items[i] = other.items[i];
    }

    this->maxWeight = other.maxWeight;
    this->volume = other.volume;
}

Backpack::Backpack(const Backpack &other)
{
    this->copy(other);
}

Backpack::Backpack(double volume, double maxWeight)
{
    this->volume = volume;
    this->maxWeight = maxWeight;
    this->size = 0;
    this->items = nullptr;
}

Backpack::~Backpack()
{
    this->deallocate();
}

void Backpack::add(const Item &item)
{
    try
    {
        if (item.getVolume() > this->volume)
        {
            throw VolumeOverflow();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        if (item.getWeight() > this->maxWeight)
        {
            throw WeightOverflow();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Item *newItems = nullptr;
    try
    {
        newItems = new Item[this->size + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < this->size; i++)
    {
        newItems[i] = this->items[i];
    }

    if (this > items)
    {
        delete[] this->items;
    }

    this->items = newItems;
    this->items[this->size++] = item;
    this->volume -= item.getVolume();
    this->maxWeight -= item.getWeight();
}

int Backpack::getSize()
{
    return this->size;
}

double Backpack::leftVolume()
{
    return this->volume;
}

double Backpack::leftWeight()
{
    return this->maxWeight;
}

Backpack &Backpack::operator=(const Backpack &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }
    return *this;
}
Item &Backpack::operator[](int position)
{
    try
    {
        if (position >= this->getSize())
        {
            throw std::invalid_argument("Invalid index");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return this->items[position];
}