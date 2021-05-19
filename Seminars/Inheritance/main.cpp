#include "Menu.h"

int main()
{
    Menu menu;
  
    menu.addFood(150, 5, 24.5);
    menu.addFood(800, 20, 12.40);
    menu.addFood(480, 4, 10.80);

    menu.printFood();

    menu.removeFood(3);

    menu.printFood();

    std::cout << "Cheapest food:" << std::endl;
    menu.cheapestFood()->print();

    return 0;
}