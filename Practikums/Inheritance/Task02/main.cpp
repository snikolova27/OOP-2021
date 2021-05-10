#include "Computer.h"
#include <iostream>

int main()
{
    Computer c1("345", "16","NVIDIA", "4785HZ");
    Computer c2 ("105", "8","NVIDIA10", "425HZ");

    c1.print();
    std::cout << std::endl;
    c2.print();

    return 0;
}