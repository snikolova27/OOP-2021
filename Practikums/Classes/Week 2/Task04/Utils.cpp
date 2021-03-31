#include "Utils.h"
#include <iostream>
#include <cstring>

const int MAX_TITLE_LEN = 32;
const int MAX_DESCRIPTION_LEN = 128;

char *inputTitle()
{
    char buffer[MAX_TITLE_LEN];
    std::cout << 'enter title of task: ';
    std::cin.getline(buffer, MAX_TITLE_LEN);
    size_t len = strlen(buffer);
    char* title = new(std::nothrow) char [len+1];
    strcpy(title, buffer);

}

char *inputDesc()
{
    char buffer[MAX_DESCRIPTION_LEN];
    std::cout << 'enter description of task: ';
    std::cin.getline(buffer, MAX_DESCRIPTION_LEN);
    size_t len = strlen(buffer);
    char* desc = new(std::nothrow) char [len+1];
    strcpy(desc, buffer);

}

void clearDynamic(char* string)
{
    delete[] string;
}
