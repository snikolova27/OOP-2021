#include "utils.h"

char* copyDynStr(const char* str)
{
    char* res = new (std::nothrow) char [strlen(str) + 1];
    if(!res)
    {
        std::cout << "Problem allocating memory";
    }
    strcpy(res, str);
    return res;
}

char*  inputStr()
{
    char buffer [32];
    std::cin.getline(buffer,32);
    size_t len = strlen(buffer) + 1;
    char* str = new (std::nothrow) char [len];
    if(!str)
    {
        std::cout << "Problem allocating memory";
    }
    strcpy(str, buffer);
    return str;
}