#include "Person.h"
#include "Utils.h"

Person::Person(char *name, short age, bool driversLicense)
{
    m_name = copyDynStr(name);
    m_age = age;
    m_driversLicense = driversLicense;
}

Person::~Person()
{
    delete[] m_name;
}

void Person::setName(char *name)
{
    delete[] m_name;
    m_name = copyDynStr(name);
}

char *Person::getName()
{
    return m_name;
}

void Person::setAge(short age)
{
    m_age = age;
}

short Person::getAge()
{
    return m_age;
}

void Person::setDriversLicense(bool driversDricense)
{
    m_driversLicense = driversDricense;
}

bool Person::getDriversLicense()
{
    return m_driversLicense;
}

void Person::printPerson()
{
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Age: " << m_age << std::endl;
    std::cout << "Has drivers license: " << m_driversLicense << std::endl;
}