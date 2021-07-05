#include <iostream>
#include <fstream>
#include "Configuration.h"
#include "Utils.h"

Configuration *createConfiguration()
{
    Configuration *result = nullptr;

    try
    {
        result = new Configuration();
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory problem" << '\n';
        return nullptr;
    }

    std::size_t cntOfComponents;
    std::cout << "How many components do you wish to put into the configuration? \n";
    std::cin >> cntOfComponents;
    std::cin.ignore();

    for (std::size_t i = 0; i < cntOfComponents; i++)
    {
        Component *component = nullptr;
        component = Utils::createComponent();
        if (component)
        {
            try
            {
                result->insert(component);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }

    return result;
}

int main()
{
    Configuration *myConfig = nullptr;
    try
    {
        myConfig = createConfiguration();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    std::cout << *myConfig << std::endl;

    std::string file;

    std::cout << "Please enter the name of the file you want to save the configuration in: \n";
    std::cin >> file;

    std::ofstream output(file.c_str());

    if (!output.is_open())
    {
        std::cout << "File couldn't be opened. \n";
        return -2;
    }
    else
    {
        output << *myConfig << std::endl;
    }

    return 0;
}