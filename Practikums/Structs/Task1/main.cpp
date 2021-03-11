#include <iostream>
#include "functions.h"

int main()
{
    int optionNumber;
    Library library;

    do
    {
        printMenu();

        std::cout << "Choose an option: ";
        std::cin >> optionNumber;
        std::cin.ignore();

        switch (optionNumber)
        {
        case 1:
            library.addBook();
            break;
        case 2:
            library.removeBook();
            break;
        case 3:
            library.printCntOfBooks();
            break;
        }
    } while (optionNumber > 0);
    
    library.clearMemory();

    return 0;
}