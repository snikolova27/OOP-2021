#include "Book.h"
#include <iostream>
#include <cstring>

void Book::intialize()
{
    char buffer[000];
    size_t size;

    std::cout << "Enter title of book: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    title = new (std::nothrow) char[size + 1];
    if (!title)
    {
        std::cout << "Memory problem";
    }
    strcpy(title, buffer);
    title[size] = '\0';

    std::cout << "Enter author of book: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    author = new (std::nothrow) char[size + 1];
    if (!author)
    {
        std::cout << "Memory problem";
    }
    strcpy(author, buffer);
    author[size] = '\0';

    std::cout << "Enter genre of book: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    genre = new (std::nothrow) char[size + 1];
    if (!genre)
    {
        std::cout << "Memory problem";
        return;
    }
    strcpy(genre, buffer);
    genre[size] = '\0';

    std::cout << "Enter price of book: ";
    std::cin >> price;
    std::cin.ignore();

    std::cout << "Enter number of copies of book sold: ";
    std::cin >> sells;
    std::cin.ignore();

    std::cout << "Enter ISBN of book: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    ISBN = new (std::nothrow) char[size + 1];
    if (!ISBN)
    {
        std::cout << "Memory problem";
        return;
    }
    strcpy(ISBN, buffer);
    ISBN[size] = '\0';
}

void Book::print()
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Copies sold: " << sells << std::endl;
    std::cout << "ISBN: " << ISBN << std::endl;
}
void Book::clearMemory()
{
    delete[] title;
    delete[] author;
    delete[] genre;
    delete[] ISBN;
}
