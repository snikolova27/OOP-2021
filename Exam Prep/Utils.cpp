#include "Utils.h"

Component *Utils ::createComponent()
{
    int choice;
    std::cout << "What component do you want to create? ( 0 - CPU, 1 - MEMORY) \n";
    std::cin >> choice;

    Component *result = nullptr;
    switch ((ComponentType)choice)
    {
    case ComponentType::CPU:
        unsigned short cores, clockSpeed;

        std::cout << "Enter cores and clock speed for the cpu in this order \n";
        std::cin >> cores >> clockSpeed;

        try
        {
            result = new Cpu(cores, clockSpeed);
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << e.what() << '\n';
            delete result;
            return nullptr;
        }
        break;

    case ComponentType::MEMORY:
        unsigned short capacity;

        std::cout << "Enter capacity of the memory \n";
        std::cin >> capacity;

        try
        {
            result = new Memory(capacity);
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << e.what() << '\n';
            delete result;
            return nullptr;
        }

        break;

    default:
        std::cout << "Invalid command \n";
        return nullptr;
        break;
    }

    return result;
}

void Utils::printMenu()
{
    std::cout << "a - Add new configuiration \n" 
            << "s - Save your configuration \n"
            << "p - Print your configuration \n" 
            << "h - Help \n"
            << "e - Exit \n";
}