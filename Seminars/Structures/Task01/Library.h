#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "helperFn.h"

struct Library
{
    size_t sizeLibrary;
    size_t capacityLibrary;
    Book* library;

    void create(size_t capacity);
    void resize();
    void addBook();
    void printBooks();
    void printBooksByPrice(priceFilter fn);
    void clearMemory();
    Book& getBestBook();
    
};

#endif