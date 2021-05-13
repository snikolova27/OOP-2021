#include "Item.h"

void Item::copy(const Item &other)
{
    try
    {
        this->name = new char[strlen(other.name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->name, other.name);

    this->weight = other.weight;
    this->volume = other.volume;
}
void Item::deallocate()
{
    if (this->name)
    {
        delete[] this->name;
    }
}

Item::Item()
{
    this->name = nullptr;
    this->volume = 0;
    this->weight = 0;
}
Item::Item(const char *label, double weight, double volume)
{
    try
    {
        this->name = new char[strlen(label) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    strcpy(this->name, label);

    this->weight = weight;
    this->volume = volume;
}
Item::Item(const Item &other)
{
    this->copy(other);
}
Item::~Item()
{
    this->deallocate();
}

char *Item::getName() const
{
    return this->name;
}

double Item::getWeight() const
{
    return this->weight;
}

double Item::getVolume() const
{
    return this->volume;
}

bool Item::operator==(const Item &other)
{
    return (strcmp(this->name, other.name) && other.volume == this->volume && this->weight == other.weight);
}
Item &Item::operator=(const Item &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }
}
bool Item::operator>(const Item &other)
{
    return this->weight > other.weight && this->volume > other.volume;
}