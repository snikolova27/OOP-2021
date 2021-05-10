#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Customer.h"

class Library
{
private:
    Customer *customers;
    Book *books;
    int capacityBooks;
    int capacityCustomers;
    int sizeBooks;
    int sizeCustomers;

public:
    void addCustomer(const std::string _name, const int _age);
    void addBook(const std::string _title, const int _year);
};

#endif