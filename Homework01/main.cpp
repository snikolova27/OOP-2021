#include "MyString.h"
#include <iostream>
#include <cstring>

int main()
{
    MyString str;
    str.setString("hey, soni");
    std::cout << str.size() << std::endl;
    std::cout << str.at(2) << std::endl;
    // std::cout<< str[3] << std::endl;
    std::cout << str.back() << std::endl;
    std::cout << str.front() << std::endl;
    str.push_back('c');
    std::cout << str.back() << std::endl;

    std::cout << str.size() << std::endl;
    str.pop_back();
    std::cout << str.size() << std::endl;
    std::cout << str.back() << std::endl;
    MyString str2;
    str2.setString("hello there");
    str = str2;
    std::cout << str2.size() << std::endl;
    std::cout << str.size() << std::endl;
    std::cout << str.back() << std::endl;
    str2 += 's';
    std::cout << str2.size() << std::endl;
    std::cout << str2.back() << std::endl;
    MyString str3("proba");
    str3 += str2;
    std::cout << str3.size() << std::endl;
    std::cout << str3.back() << std::endl;
    MyString str4;
    str4 = str2.c_str();
    std::cout << str4.size() << std::endl;
    std::cout << str4.back() << std::endl;
    std::cout << (str2 == str) << std::endl;
    MyString str5;
    str5.setString("adef");
    MyString str6;
    str6.setString("acdef");
    std::cout << (str5 < str6) << std::endl;
    MyString str7;
    MyString str8("");
    std::cout <<(str7 == str8) << std::endl;
}