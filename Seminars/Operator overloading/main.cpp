#include "University.h"
#include <iostream>

int main()
{
    University uni1, uni2;

    uni1.addStudent("Sonya", "82213", true);
    uni1.addStudent("Peter", "82214", true);

    uni2.addStudent("Maria", "82208", true);
    uni2.addStudent("Anton", "82000", false);

    University uni;
    uni = uni1 + uni2;

    for (std::size_t i = 0; i < uni.getSize(); i++)
    {
        std::cout << uni[i] << std::endl;
    }
    return 0;
}