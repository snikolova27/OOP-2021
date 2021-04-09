#include "MyString.h"
#include <iostream>

int main()
{
    MyString str;
    str.setString("hey, soni");
    std::cout << str.getLenght() << std::endl;
    std::cout << str.at(2) << std::endl;
   // std::cout<< str[3] << std::endl;
    std::cout << str.back() << std::endl;
    std::cout << str.front() << std::endl;
}