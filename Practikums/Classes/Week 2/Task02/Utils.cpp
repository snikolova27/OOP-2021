#include "Utils.h"
#include <iostream>
#include <cstring>

char* inputName()
{
    char buffer [100];
    std::cout << "Enter name of horo: ";
    std::cin.getline(buffer,100);
    size_t len = strlen(buffer);
    char* name = new (std::nothrow) char [len+1];
    strcpy(name, buffer);

    return name;
}
char* inputRegion()
{
    char buffer [100];
    std::cout << "Enter region of horo:";
    std::cin.getline(buffer,100);
    size_t len = strlen(buffer);
    char* region = new (std::nothrow ) char [len+1];
    strcpy(region, buffer);

    return region;
}
char* inputRazmer()
{
    char buffer [100];
    std::cout << "Enter razmer of horo:";
    std::cin.getline(buffer,100);
    size_t len = strlen(buffer);
    char* razmer = new (std::nothrow ) char [len+1];
    strcpy(razmer, buffer);

    return razmer;
}

void clearDynamic(char* field)
{
    delete[] field;
}