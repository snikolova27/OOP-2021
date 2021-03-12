/**
 * \ Structure working with books and a library
 * \ author S. Nikolova
  */

#ifndef FUNC_H
#define FUNC_H

const int MAX_BOOKS = 1000;  //!< stores the maximum amount of books in the library

struct Book
{
    char *title; //!< stores the title of the book
    char *author; //!< stores the name of the author of the book
    char *ISBN;  //!< stores the ISBN of the book

//! Function to get the details about the book from the console
    void readBook();
};

struct Library
{
    Book library[MAX_BOOKS]; //!< stores the books that are entered
    int cntOfBooks = 0;      //!< stores the count of books in the library

//! Function to add a book to the library
    void addBook();

//! Function to remove a book with a specific ISBN from the library
    void removeBook();

//! Function to print the count of books in the library
    void printCntOfBooks();

//! Function to clear the allocated dynamic memory used for the library
    void clearMemory();
};

//! Function to print the menu at the start of the program
void printMenu();

#endif