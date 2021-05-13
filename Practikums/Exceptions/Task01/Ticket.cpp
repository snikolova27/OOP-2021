#include "Ticket.h"
#include <cstring>
#include <iostream>

void Ticket::copy(const Ticket &other)
{
    try
    {
        validateName(other.name);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        this->name = new char[strlen(other.name) + 1];
    }

    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->name, other.name);

    try
    {
        validatePhone(other.phoneNum);
    }

    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        this->phoneNum = new char[strlen(other.phoneNum) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->phoneNum, other.phoneNum);

    this->uniqueNum = other.uniqueNum;
}
void Ticket::deallocate()
{
    if (this->name)
    {
        delete[] this->name;
    }
    if (this->phoneNum)
    {
        delete[] this->phoneNum;
    }
    this->name = nullptr;
    this->phoneNum = nullptr;
    this->uniqueNum = 0;
}

bool Ticket::validateName(const char *_name)
{
    for (int i = 0; i < strlen(_name); i++)
    {
        if (!(_name[i] == ' ') || (_name[i] >= 'a' && _name[i] <= 'z') || (_name[i] >= 'A' && _name[i] <= 'Z'))
        {
            return false;
        }
    }
    return true;
}

bool Ticket::validatePhone(const char *_phone)
{
    if (strlen(_phone) != 10)
    {
        return false;
    }
    return true;
}

void Ticket::setName(const char *_name)
{
    delete[] this->name;
    if (!validateName(_name))
    {
        throw std::invalid_argument("Invalid name input");
    }

    this->name = new (std::nothrow) char[strlen(_name)];
    if (this->name)
    {
        strcpy(this->name, _name);
    }
}

void Ticket::setPhoneNum(const char *_phone)
{
    delete[] this->phoneNum;
    if (!validatePhone(_phone))
    {
        throw std::length_error("Invalid phone input");
    }
    this->phoneNum = new (std::nothrow) char[strlen(_phone)];
    if (this->phoneNum)
    {
        strcpy(this->phoneNum, _phone);
    }
}

void Ticket::setUniqueNum(const int _num)
{
    this->uniqueNum = _num;
}

const char *Ticket::getName() const
{
    return this->name;
}

const char *Ticket::getPhone() const
{
    return this->phoneNum;
}

const int Ticket::getUniqueNum() const
{
    return this->uniqueNum;
}

Ticket::Ticket()
{
    this->name = nullptr;
    this->phoneNum = nullptr;
    this->uniqueNum = 0;
}

Ticket::Ticket(const char *_name, const char *_phone, const int _uniqueNum)
{
    setName(_name);
    setPhoneNum(_phone);
    setUniqueNum(_uniqueNum);
}

Ticket::Ticket(const Ticket &other)
{
    copy(other);
}

Ticket::~Ticket()
{
    deallocate();
}

Ticket &Ticket ::operator=(const Ticket &other)
{
    if (this != &other)
    {
        this->deallocate();
        copy(other);
    }
    return *this;
}
std::istream &operator>>(std::istream &in, Ticket &ticket)
{
    ticket.deallocate();

    std::cout << "\t"
              << "Input ticket information" << std::endl;

    std::cout << "Enter name of passenger: ";
    char buffer[100];
    std::cin.getline(buffer, 100);
    char *temp = new (std::nothrow) char[strlen(buffer) + 1];
    if (!temp)
    {
        throw std::bad_alloc();
    }
    strcpy(temp, buffer);
    ticket.setName(temp);
    delete[] temp;

    std::cout << "Enter phone number: ";
    std::cin.getline(buffer, 100);
    char *temp = new (std::nothrow) char[strlen(buffer) + 1];
    if (!temp)
    {
        throw std::bad_alloc();
    }
    strcpy(temp, buffer);
    ticket.setPhoneNum(temp);
    delete[] temp;

    int tempN;
    std::cout << "Enter unique number:";
    std::cin >> tempN;
    ticket.setUniqueNum(tempN);
    std::cin.ignore();

    return in;
}
std::ostream &operator<<(std::ostream &out, Ticket &ticket)
{
    out << "\t"
        << "Ticket information" << std::endl;
    out << "Name: " << ticket.getName() << std::endl;
    out << "Phone number: " << ticket.getPhone() << std::endl;
    out << "Unique number: " << ticket.getUniqueNum() << std::endl;

    return out;
}