#ifndef BACKPACK_H
#define BACKPACK_H
#include "Item.h"
#include "Exceptions.h"

class Backpack
{
private:
    Item *items;
    double volume;
    double maxWeight;
    int size;

    void deallocate();
    void copy(const Backpack &other);

public:
    Backpack(const Backpack &other);
    Backpack(double volume, double maxWeight);
    ~Backpack();

    void add(const Item &item);
    int getSize();
    double leftVolume();
    double leftWeight();

    Item &operator[](int position);
    Backpack &operator=(const Backpack &other);
};

#endif