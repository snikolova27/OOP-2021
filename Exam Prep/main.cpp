#include <iostream>
#include <vector>
#include <fstream>
#include "Utils.h"
#include "Configuration.h"

Configuration *createConfiguration()
{

    Configuration *config = new Configuration();

    int cntOfComponents;

    std::cout << "How many components will you create? \n";
    std::cin >> cntOfComponents;

    if (cntOfComponents > (int)ComponentType::COMPONENT_CNT)
    {
        throw std::invalid_argument("Too many different components");
        delete config;
        return nullptr;
    }
    else
    {
        for (int i = 0; i < cntOfComponents; i++)
        {
            Utils utils;
            Component *newComponent;
            newComponent = utils.createComponent();
            if (newComponent != nullptr)
            {

                try
                {
                    config->insert(newComponent);
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
        return config;
    }
}
int main()
{
    std::vector<Configuration *> configs;
    Configuration *myConfig = nullptr;

    char choice = 'a';

    std::ofstream output;
    std::string fileName;

    Utils utils;
    utils.printMenu();

    while (choice != 'e')
    {
        std::cout << "Enter command \n";
        std::cin >> choice;

        switch (choice)
        {
        case 'a':
            try
            {
                myConfig = createConfiguration();
                configs.push_back(myConfig);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
            break;

        case 'h':
            utils.printMenu();
            break;

        case 'e':
            break;

        case 's':
            std::cout << "Enter name of file to save the configurations in: ";
            std::cin >> fileName;
            std::cin.ignore();

            output.open(fileName);
            if (!output.is_open())
            {
                std::cerr << "Couldn't open file " << fileName;
            }
            else
            {
                for (std::size_t i = 0; i < configs.size(); i++)
                {
                    output << "Config #" << i + 1 << std::endl;
                    output << "------------" << std::endl;
                    output << *configs[i] << std::endl;
                    output << configs[i]->price() << std::endl;
                    output << "============ \n" << std::endl;
                }
            }
            output.close();
            break;

        case 'p':

            for (std::size_t i = 0; i < configs.size(); i++)
            {
                std::cout << "Config #" << i + 1 << std::endl;
                std::cout << "------------" << std::endl;
                std::cout << *configs[i] << std::endl;
                std::cout << "============ \n" << std::endl;
            }
            break;
        default:
            std::cout << "Unknown command \n";
            utils.printMenu();
            break;
        }
    }

    for (std::size_t i = 0; i < configs.size(); i++)
    {
        delete configs[i];
    }

    return 0;
}