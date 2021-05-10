#include "Book.h"

int Book::cnt = 1000;

Book::Book()
{
    this->title = nullptr;
    this->year = 0;
}
Book::Book(const std::string _title, const int _year)
{
    this->id = ++cnt;
    this->title = _title;
    this->year = _year;
    
}
Book::Book(const std::string _title, const int _year, const Customer &_customer)
{
    this->id = ++cnt;
    this->title = _title;
    this->year = _year;
    this->idC = _customer;
}
bool Book::operator==(const Book &other) const
{
    return (this->title == other.title && this->year == other.year && this->idC == other.idC && this->id == other.id);
}
bool Book::operator<(const Book &other) const
{
    return (this->year < other.year);
}
bool Book::operator>(const Book &other) const
{
    return (this->year > other.year);
}
void Book::print()
{
    std::cout << "Id of book: " << this->id << std::endl;
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Year of book: " << this->year << std::endl;
    std::cout << "Id of customer who has rented the book: " << this->idC.getId() << std::endl;
}