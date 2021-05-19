#include "Menu.h"

Menu::Menu() {}

Menu::~Menu()
{
    int size = this->menu.size();
    for (int i = 0; i < size; i++)
    {
        delete this->menu[i];
        this->menu[i] = nullptr;
    }
}
void Menu::addFood(const double weight, const unsigned int parts, const double price)
{
    try
    {
        this->menu.push_back(new Food(weight, parts, price));
    }
    catch (const std::bad_alloc &ba)
    {
        std::cerr << ba.what() << '\n';
        throw std::bad_alloc();
    }
}
void Menu::removeFood(const unsigned int id)
{
    int size = this->menu.size();
    for (int i = 0; i < size; i++)
    {
        if (this->menu[i]->getId() == id)
        {
            delete this->menu[i];
            this->menu[i] = nullptr;
            this->menu.erase(this->menu.begin() + i);
            return;
        }
    }
}
void Menu::printFood()
{
    int size = this->menu.size();
    std::cout << "Size of menu: " << size << std::endl;
    for (int i = 0; i < size; i++)
    {
        this->menu[i]->print();
    }
}
Food *Menu::cheapestFood()
{
    if (this->menu.size() == 0)
    {
        std::cout << "No food in menu" << std::endl;
        return nullptr;
    }
    int minIdx = 0;
    int size = this->menu.size();
    for (int i = 1; i < size; i++)
    {
        if (this->menu[i]->getPrice() < this->menu[minIdx]->getPrice())
        {
            minIdx = i;
        }
    }

    return this->menu[minIdx];
}

int Menu::getSize() const
{
    return this->menu.size();
}