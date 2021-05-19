#ifndef MENU_H
#define MENU_H
#include "Food.h"
#include <vector>
#include <iostream>


class Menu
{
    private:
    std::vector <Food*> menu;

    public:
    Menu();
    Menu(const Menu* other) = delete;
    Menu& operator = (const Menu& other) = delete;
    ~Menu();
    void addFood(const double weight, const  unsigned int parts, const double price);
    void removeFood(const unsigned int id);
    void printFood();
    Food* cheapestFood();    
    int getSize() const;   

};
#endif