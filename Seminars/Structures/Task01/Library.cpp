#include "Library.h"
#include "Book.h"
#include <iostream>

void Library::create(size_t capacity)
{
    library = new (std::nothrow) Book[capacity];
    if (!library)
    {
        std::cout << "Memory problem";
        return;
    }
    capacityLibrary = capacity;
    sizeLibrary = 0;

    std::cout << "Library created";
}

void Library::resize()
{
    Book *old = library;

    capacityLibrary *= 2;

    library = new (std::nothrow) Book[capacityLibrary];
    if (!library)
    {
        std::cout << "Memory problem";
        return;
    }

    for (int i = 0; i, sizeLibrary; i++)
    {
        library[i] = old[i];
    }

    delete[] old;
}

void Library::clearMemory()
{
    for (int i = 0; i < sizeLibrary; i++)
    {
        library[i].clearMemory();
    }
    delete[] library;
}

void Library::addBook()
{
    Book newBook;
    newBook.intialize();

    if(sizeLibrary == capacityLibrary)
    {
        resize();
    }

    library[sizeLibrary] = newBook;
    ++sizeLibrary;
}

void Library::printBooks()
{
    for(int i=0; i<sizeLibrary;i++)
    {
        std::cout << "Book #" << i+1 << std::endl;
        library[i].print();
    }
}

Book& Library::getBestBook()
{
    int bestBooksales = library[0].sells;
    int beestIdx = 0;

    for(int i=1; i<sizeLibrary;i++)
    {
        if(library[i].sells > bestBooksales)
        {
            beestIdx = i;
            bestBooksales = library[i].sells;
        }
    } 

    return library[beestIdx];
}

void Library::printBooksByPrice(priceFilter fn)
{
    double bestPrice = library[0]. price;
    int bestIdx = 0;

    for(int i=1; i<sizeLibrary;i++)
    {
        if(fn(library[i].price, bestPrice))
        {
            bestIdx = i;
            bestPrice = library[i].price;
        }
    } 
    library[bestIdx].print();
}