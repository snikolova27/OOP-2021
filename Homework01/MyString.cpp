#include "MyString.h"
#include <cstring>
#include <cassert>

//------------ helper functions ------------
// Functions used for executing the class and costructor/destructor functions easier
void MyString::deallocateMemory()
{
    if (this->string)
    {
        delete[] this->string;
    }
}

char *MyString::copyDynStr(const char *str)
{
    char *res = new (std::nothrow) char[strlen(str) + 1];
    if (!res)
    {
        std::cout << "Problem allocating memory";
        return nullptr;
    }
    strcpy(res, str);
    return res;
}

//------------ constructors ------------
// Default constructor, Constructor with parameters and Copy constructor for the class
MyString::MyString()
{
    this->string = nullptr;
    this->len = 0;
}

MyString::MyString(const char *str)
{
    this->string = copyDynStr(str);
    this->len = strlen(string);
}

MyString::MyString(const MyString &other)
{
    this->string = new (std::nothrow) char[strlen(other.string) + 1];
    if (this->string)
    {
        stpcpy(this->string, other.string);
    }
    this->len = other.len;
}

//------------ destructor ------------
// Destructor for the class
MyString::~MyString()
{
    deallocateMemory();
}

//------------ setters ------------
// Setter functions for the members of the class
void MyString::setString(const char *str)
{
    this->string = copyDynStr(str);
    this->len = strlen(str);
}

void MyString::setLen(const size_t len)
{
    this->len = len;
}

//------------ getters ------------
// Getter functions for the members of the class
char *MyString::getString() const
{
    return this->string;
}

size_t MyString::getLenght() const
{
    return this->len; //the last element = '\0'
}
//------------ class functions ------------

char &MyString::at(size_t pos)
{
    if (pos >= this->len)
    {
        throw std::out_of_range("No such position");
    }
    return this->string[pos];
}
const char &MyString::at(size_t pos) const
{
    if (pos >= this->len)
    {
        std::cout << "No such position" << std::endl;
    }
    return this->string[pos];
}
char &MyString::operator[](size_t pos)
{
    assert(pos < this->len);
    return at(pos);
}
const char &MyString::operator[](size_t pos) const
{
    return at(pos);
}
char &MyString::front()
{
    return this->string[0];
}
const char &MyString::front() const
{
    return this->string[0];
}
char &MyString::back()
{
    return this->string[(this->len - 1)];
}
const char &MyString::back() const
{
    return this->string[(this->len -1)];
}
// bool MyString::empty() const;
// size_t MyString::size() const;
// void MyString::clear();
// void MyString::push_back(char c);
// void MyString::pop_back();
// MyString& operator= (const MyString& other);
// MyString &MyString::operator+=(char c);
// MyString &MyString::operator+=(const MyString &rhs);
// MyString MyString::operator+(char c) const;
// MyString MyString::operator+(const MyString &rhs) const;
// const char *MyString::c_str() const;
// bool MyString::operator==(const MyString &rhs) const;
// bool MyString::operator<(const MyString &rhs) const;