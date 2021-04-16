#ifndef COMPUTER_SHOP_H
#define COMPUTER_SHOP_H
#include "Computer.h"

const int INITIAL_CAPACITY = 2;
const int RESIZE_STEP = 2;

class ComputerShop
{
private:
    int size;
    int capacity;
    std::string name;
    Computer *list;

    void deallocate();
    void resize();

public:
    ComputerShop(const std::string _name, const int _capacity);

    const int getSize() const;

    void addComputer( Computer computer);
    void printList();
    void buyComputer(const std::string _brand, int _money);
    void filteredComputers();
    bool findComputer(std::string _brand);

    ~ComputerShop();
};
#endif