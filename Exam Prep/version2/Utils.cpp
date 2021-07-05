#include "Utils.h"
#include <iostream>

Component *Utils::createComponent()
{
    char choice;
    Component *result = nullptr;

    std::cout << "What component are you creating? (c - cpu, m - memory) \n";
    std::cin >> choice;
    std::cin.ignore();

    std::string label;
    unsigned short cores, clockSpeed, capacity;
    switch (choice)
    {
    case 'c':
        std::cout << "Please enter label, cores and clock speed \n";
        std::cin >> label >> cores >> clockSpeed;
        std::cin.ignore();

        try
        {
            result = new CPU(label, cores, clockSpeed);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << "Memory problem" << '\n';
        }
        break;

    case 'm':
        std::cout << "Please enter label and capacity \n";
        std::cin >> label >> capacity;
        std::cin.ignore();

        try
        {
            result = new Memory(label, capacity);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << "Memory problem" << '\n';
        }

        break;
    default:
        std::cout << "Invalid choice "
                  << "\n";
        break;
    }

    return result;
}
