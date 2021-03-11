#ifndef FUNC_H
#define FUNC_H

const int MAX_BOOKS = 1000;

struct Book
{
    char *title;
    char *author;
    char *ISBN;

    void readBook();
};
struct Library
{
    Book library[MAX_BOOKS];
    int cntOfBooks = 0;

    void addBook();
    void removeBook();
    void printCntOfBooks();
    void clearMemory();
};

void printMenu();

#endif