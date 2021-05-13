#ifndef ITEM_H
#define ITEM_H
#include <cstring>
#include <iostream>

class Item
{
private:
    char *name;
    double weight;
    double volume;

    void copy(const Item &other);
    void deallocate();

public:
    Item();
    Item(const char *label, double weight, double volume);
    Item(const Item &other);
    ~Item();

    char *getName() const;
    double getWeight() const;
    double getVolume() const;

    bool operator==(const Item &other);
    Item &operator=(const Item &other);
    bool operator>(const Item &other);
};

#endif