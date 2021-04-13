#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString
{
private:
    char *string;
    std::size_t len;

    //------------ helper functions ------------
    void deallocateMemory();
    char *copyDynStr(const char *str);
    void copy(const MyString &other);

public:
    //------------ constructors ------------
    MyString();
    MyString(const char *str);
    MyString(const MyString &other);

    //------------ setters ------------
    void setString(const char *str);

    //------------ getters ------------
    const char *c_str() const;
    std::size_t size() const;

    //------------ class functions ------------
    char &at(std::size_t pos);
    const char &at(std::size_t pos) const;
    char &front();
    const char &front() const;
    char &back();
    const char &back() const;
    bool empty() const;
    void clear();
    void push_back(char c);
    void pop_back();

    //----------- operator overloading ------------
    char &operator[](std::size_t pos);
    const char &operator[](std::size_t pos) const;
    MyString &operator=(const MyString &other);
    MyString &operator+=(char c);
    MyString &operator+=(const MyString &rhs);
    MyString operator+(char c) const;
    MyString operator+(const MyString &rhs) const;
    bool operator==(const MyString &rhs) const;
    bool operator<(const MyString &rhs) const;

    //------------ destructor ------------
    ~MyString();
};
#endif