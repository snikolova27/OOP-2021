#include "MyString.h"
#include <cstring>

//------------ helper functions ------------
void MyString::deallocateMemory()
{
    if (this->string)
    {
        delete[] this->string;
    }
}
char* MyString::copyDynStr(const char* str)
{
    char* res = new (std::nothrow) char [strlen(str) + 1];
    if(!res)
    {
        std::cout << "Problem allocating memory";
    }
    strcpy(res, str);
    return res;
}

//------------ constructors ------------
MyString::MyString()
{
    this->string = nullptr;
    this->len = 0;
}
MyString::MyString(const char *str)
{
    this->string = copyDynStr(str);
    this->len = strlen(string);
}
MyString::MyString(const MyString &other)
{

}
