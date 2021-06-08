#include "Park.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<Park> parks;

    int cnt;
    std::cout << "How many parks will you enter? \n";
    std::cin >> cnt;
    std::cin.ignore();

    for (int i = 0; i < cnt; i++)
    {
        std::cout << "Enter name: ";
        std::string buffer;
        std::getline(std::cin, buffer);

        parks.push_back(Park(buffer));
    }

    std::string toRemove;
    std::cout << "Enter name of the park you wish to remove from the collection: ";
    std::getline(std::cin, toRemove);

    for (std::vector<Park>::iterator i = parks.begin(); i != parks.end(); i++)
    {
        if ((*i).getName() == toRemove)
        {
            parks.erase(i);
        }
    }

    for (std::vector<Park>::const_iterator i = parks.begin(); i != parks.end(); i++)
    {
        std::cout << i->getName() << std::endl;
    }
    return 0;
}