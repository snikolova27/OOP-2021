#include "Person.h"
#include "Utils.h"

Person::Person()
{
    m_name = nullptr;
    m_age = 0;
    m_driversLicense = 0;
}
Person::Person(const char *m_name, const short m_age, const bool driversLicense)
{
    m_name = copyDynStr(m_name);
    m_age = m_age;
    m_driversLicense = driversLicense;
}

void Person::setName(const char *m_name)
{
    delete[] m_name;
    m_name = copyDynStr(m_name);
}

char *Person::getName() const
{
    return m_name;
}

void Person::setAge(const short m_age)
{
    m_age = m_age;
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

bool Person::operator == (const Person& other) const
{
    if (!this->m_name || !other.m_name)
    {
        return this->m_name == other.m_name;
    }

    return strcmp(this->m_name, other.m_name) == 0 && this->m_age == other.m_age && 
           this->m_driversLicense == other.m_driversLicense;
}