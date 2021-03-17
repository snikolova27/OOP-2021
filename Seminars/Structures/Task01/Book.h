#ifndef BOOK_H
#define BOOK_H

struct  Book
{
    char* title;
    char* author ;
    char* genre;
    int price;
    long sells;
    char* ISBN;

    void intialize();
    void print();
    void clearMemory();
};

#endif