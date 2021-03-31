#include "Utils.h"
#include "Person.h"

int main()
{
    short age;
    bool driversLicense;
    char *name = inputName();
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Drivers license? [0/1]:";
    std::cin >> driversLicense;

    Person A(name, age, driversLicense);
    A.printPerson();
    
    clearDynamic(name);
}