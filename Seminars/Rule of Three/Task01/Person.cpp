#include "Person.h"
#include "Utils.h"

Person::Person()
{
    m_name = nullptr;
    m_age = 0;
    m_driversLicense = 0;
}
Person::Person(const char *name, const short age, const bool driversLicense)
{
    m_name = copyDynStr(name);
    m_age = age;
    m_driversLicense = driversLicense;
}

void Person::setName(const char *name)
{
    delete[] m_name;
    m_name = copyDynStr(name);
}

char *Person::getName() const
{
    return m_name;
}

void Person::setAge(const short age)
{
    m_age = age;
}

short Person::getAge() const
{
    return m_age;
}

void Person::setDriversLicense(const bool driversDricense)
{
    m_driversLicense = driversDricense;
}

bool Person::getDriversLicense() const
{
    return m_driversLicense;
}

void Person::printPerson()
{
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Age: " << m_age << std::endl;
    std::cout << "Has drivers license: " << m_driversLicense << std::endl;
}

void Person::erase()
{
    delete[] m_name;
}
void Person::copy(const Person &A)
{
  setAge(A.m_age);
  setDriversLicense(A.m_driversLicense);
   

    if (A.m_name != nullptr)
    {
        size_t len = strlen(A.m_name) + 1;
        m_name = new (std::nothrow) char[len];
        if (m_name)
        {
            strcpy(m_name, A.m_name);
        }
    }
}

Person::~Person()
{
    erase();
}
Person::Person(const Person &other)
{
    copy(other);
}
Person& Person::operator = (const Person &other)
{
    if (&other != this)
    {
        erase();
        copy(other);
    }
    return *this;
}