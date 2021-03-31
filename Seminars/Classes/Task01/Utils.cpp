#include "Utils.h"

char *inputName()
{
    char buffer[100];
    std::cout << "Enter name: ";
    std::cin.getline(buffer, 100);
    size_t len = strlen(buffer);
    char *name = new (std::nothrow) char[len + 1];
    strcpy(name, buffer);
    return name;
}
void clearDynamic(char* str)
{
    delete[] str;
}
char* copyDynStr(char* str)
{
    char* res = new (std::nothrow) char [strlen(str) + 1];
    strcpy(res, str);
    return res;
}