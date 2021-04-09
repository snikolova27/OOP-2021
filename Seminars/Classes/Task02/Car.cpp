#include <iostream>
#include <cstring>
#include "Car.h"

void Car::setOwner(const Person& owner)
{
    m_owner = owner;
}

void Car::setBrand(const char* brand)
{
    if (m_brand)
    {
        delete[] m_brand;
    }
    m_brand = new (std::nothrow) char[strlen(brand) + 1];
    strcpy(m_brand, brand);
}

void Car::setLicensePlate(const char* licensePlate)
{
    if (m_licensePlate)
    {
        delete[] m_licensePlate;
    }
    m_licensePlate = new (std::nothrow) char[strlen(licensePlate) + 1];
    strcpy(m_licensePlate, licensePlate);
}

void Car::setColor(const Color& color)
{
    m_color = color;
}

void Car::copy(const Car& other)
{
    setOwner(other.m_owner);
    setBrand(other.m_brand);
    setLicensePlate(other.m_licensePlate);
    setColor(other.m_color);
}
void Car::erase()
{
    if (m_brand)
    {
        delete[] m_brand;
    }
    if (m_licensePlate)
    {
        delete[] m_licensePlate;
    }
}

Car::Car() :m_owner()
{
    m_brand = nullptr;
    m_licensePlate = nullptr;
    m_color = UNKNOWN;
}

Car::Car(const Person owner, const char *brand, const Color color, const char *licensePlate)
{
    setOwner(owner);
    setBrand(brand);
    setColor(color);
    setLicensePlate(licensePlate);
}

Car::Car(const Car &other)
{
    copy(other);
}

Car::~Car()
{
    erase();
}

Car &Car::operator=(const Car &other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }

    return *this;
}

Person Car::getOwner() const
{
    return m_owner;
}

char *Car::getBrand() const
{
    return m_brand;
}

char *Car::getLicensePlate() const
{
    return m_licensePlate;
}

Color Car::getColor() const
{
    return m_color;
}

void Car::print()
{
    std::cout << "Owner: " << std::endl;
    m_owner.printPerson();
    std::cout << "Brand: " << m_brand << std::endl;
    std::cout << "License plate: " << m_licensePlate << std::endl;
    std::cout << "Color: ";
    switch (m_color)
    {
    case RED:
        std::cout << "red";
        break;
    case BLUE:
        std::cout << "blue";
        break;
    case BLACK:
        std::cout << "black";
        break;
    case WHITE:
        std::cout << "white";
        break;
    case GRAY:
        std::cout << "gray";
        break;
    case PURPLE:
        std::cout << "purple";
        break;
    case YELLOW:
        std::cout << "yellow";
        break;
    default:
        std::cout << "unknown";
        break;
    }
    std::cout << std::endl;
}
