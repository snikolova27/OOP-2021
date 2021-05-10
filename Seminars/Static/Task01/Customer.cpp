#include "Customer.h"

int Customer::counter = 0;

void Customer::copy(const Customer &other)
{
    this->id = other.id;
    this->name = other.name;
    this->age = other.age;
}
int Customer::getId() const
{
    return this->id;
}
Customer::Customer()
{
    this->name = nullptr;
    this->age = 0;
}
Customer::Customer(const std::string _name, const int _age)
{
    this->id = ++counter;
    this->name = _name;
    this->age = _age;
}
Customer &Customer::operator=(const Customer &other)
{
    this->copy(other);
    return *this;
}
bool Customer::operator==(const Customer &other) const
{
    return (this->id == other.id && this->name == other.name && this->age == other.age);
}
bool Customer::operator<(const Customer &other) const
{
    return (this->age < other.age);
}
bool Customer::operator>(const Customer &other) const
{
    return (this->age > other.age);
}
void Customer::print()
{
    std::cout << "Id of customer: " << this->id << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Age: " << this->age << std::endl;
}