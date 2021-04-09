#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString
{
private:
    char *string;
    size_t len;

 //------------ helper functions ------------
    void deallocateMemory();
    char* copyDynStr(const char* str);

public:
    //------------ constructors ------------
    MyString();
    MyString(const char *str);
    MyString(const MyString &other);

    //------------ setters ------------
    void setString(const char *str);
    void setLen(const size_t len);

    //------------ getters ------------
    char *getString() const;
    size_t getLenght() const;

    //------------ class functions ------------

    char& at(size_t pos);
    const char& at(size_t pos) const;
    char& operator [] (size_t pos);
    const char& operator[] (size_t pos) const;
    char& front();
    const char& front() const;
    char& back();
    const char& back() const;
    bool empty() const;
    size_t size() const;
    void clear() ;
    void push_back(char c);
    void pop_back();
    MyString& operator+=(char c);
    MyString& operator+=(const MyString& rhs);
    MyString operator+(char c) const;
    MyString operator+(const MyString& rhs) const;
    const char* c_str() const ;
    bool operator==(const MyString &rhs) const;
    bool operator<(const MyString &rhs) const;

    //------------ destructor ------------
    ~MyString();
};
#endif