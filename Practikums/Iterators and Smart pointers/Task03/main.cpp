#include "Park.h"
#include <iostream>
#include <memory>

int main()
{
    std::string name;
    std::cout << "Enter name of park" <<std::endl;
    std::getline(std::cin, name);

    Park* park = new Park(name);
    
    std::cout << park->getName() << std::endl;

    delete park;

    std::unique_ptr <Park> uniquePark(new Park(name));

    std::cout << uniquePark->getName() << std::endl;

    std::shared_ptr <Park> shrdPark1(new Park(name));
    std::shared_ptr <Park> shrdPark2(shrdPark1);
    std::shared_ptr<Park> shrdPark3(shrdPark2);

    std::cout << shrdPark3->getName();
    return 0;
}