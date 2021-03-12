#include <iostream>
#include <cstring>
#include "functions.h"

void Book::readBook()
{
    char buffer[1000];
    size_t len;

    std::cout << "Enter the title of a book: ";
    std::cin.getline(buffer, 1000);
    len = strlen(buffer);
    title = new (std::nothrow) char[len];
    strcpy(title, buffer);

    std::cout << "Enter the author of the book: ";
    std::cin.getline(buffer, 1000);
    len = strlen(buffer);
    author = new (std::nothrow) char[len];
    strcpy(author, buffer);

    std::cout << "Enter ISBN of the book: ";
    std::cin >> buffer;
    std::cin.ignore();
    len = strlen(buffer);
    ISBN = new (std::nothrow) char[len];
    strcpy(ISBN, buffer);
}

void Library::addBook()
{
    Book newBook;
    newBook.readBook();

    library[cntOfBooks++] = newBook;
    std::cout << "The book has been added to the library \n";
    std::cout << std::endl;
}

void Library::removeBook()
{
    char searchISBN[13];

    std::cout << "Enter the ISBN of the book you want to remove: ";
    std::cin >> searchISBN;
    std::cin.ignore();

    int idx = -1;

    for (int i = 0; i < cntOfBooks; i++)
    {
        if (strcmp(searchISBN, library[i].ISBN) == 0)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        std::cout << "There isn't a book in the library with this ISBN \n";
        std::cout << std::endl;
    }
    else
    {
        for (int i = idx; i < cntOfBooks - 1; i++)
        {
            library[i] = library[i + 1];
        }
        --cntOfBooks;

        std::cout << "The book with this ISBN was deleted \n";
        std::cout << std::endl;
    }
}

void Library::printCntOfBooks()
{
    std::cout << "Current number of books is: " << cntOfBooks << std::endl;
}

void Library::clearMemory()
{
    for (int i = 0; i < cntOfBooks; i++)
    {
        delete[] library[i].title;
        delete[] library[i].author;
        delete[] library[i].ISBN;
    }
}

void printMenu()
{
    std::cout << '\t' << "Menu" << std::endl;
    std::cout << "1. Add book to the library" << std::endl;
    std::cout << "2. Remove a book from the library" << std::endl;
    std::cout << "3. Print the count of books in the library" << std::endl;
    std::cout << "0. Exit" << std::endl;
}