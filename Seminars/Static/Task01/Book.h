#ifndef BOOK_H
#define BOOK_H
#include "Customer.h"
class Book
{
private:
    static int cnt;
    int id;
    std::string title;
    int year;
    Customer idC;

public:
    Book();
    Book(const std::string _title, const int _year);
    Book(const std::string _title, const int _year, const Customer &_customer);
    bool operator==(const Book &other) const;
    bool operator<(const Book &other) const;
    bool operator>(const Book &other) const;
    void print();
};
#endif