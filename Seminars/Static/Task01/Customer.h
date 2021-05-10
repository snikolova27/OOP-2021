#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>

class Customer
{
private:
    static int counter;
    int id;
    std::string name;
    int age;

    void copy(const Customer &other);

public:
    int getId() const;
    Customer();
    Customer(const std::string _name, const int _age);
    Customer &operator=(const Customer &other);
    bool operator==(const Customer &other) const;
    bool operator<(const Customer &other) const;
    bool operator>(const Customer &ohter) const;
    void print();
};
#endif