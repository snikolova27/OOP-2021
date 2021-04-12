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
void MyString::copy(const MyString &other)
{
    this->string = new (std::nothrow) char[other.len + 1];
    if (this->string)
    {
        strcpy(this->string, other.string);
        this->len = other.len;
    }
    else
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
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
    this->copy(other);
}

//------------ destructor ------------
// Destructor for the class
MyString::~MyString()
{
    this->deallocateMemory();
}

//------------ setters ------------
// Setter functions for the members of the class
void MyString::setString(const char *str)
{
    //this->deallocateMemory();
    this->string = copyDynStr(str);
    this->len = strlen(str);
}

//------------ getters ------------
// Getter functions for the members of the class
const char *MyString::c_str() const
{
    return this->string;
}
size_t MyString::size() const
{
    return this->len;
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
    return this->string[pos];
}
const char &MyString::operator[](size_t pos) const
{
    assert(pos < this->len);
    return this->string[pos];
}
char &MyString::front()
{
    assert(!this->empty());
    return this->string[0];
}
const char &MyString::front() const
{
    assert(!this->empty());
    return this->string[0];
}
char &MyString::back()
{
    assert(!this->empty());
    return this->string[(this->len - 1)];
}
const char &MyString::back() const
{
    assert(!this->empty());
    return this->string[(this->len - 1)];
}
bool MyString::empty() const
{
    return this->string == 0;
}
void MyString::clear()
{
    this->deallocateMemory();
    this->len = 0;
}
void MyString::push_back(char c)
{
    if (!this->string)
    {
        this->string = new (std::nothrow) char[2];
        if (this->string)
        {
            this->string[0] = c;
            this->string[1] = '\0';
            this->len = 2;
        }
        else
        {
            std::cout << "Problem allocating memory" << std::endl;
        }
        return;
    }
    char *temp = new (std::nothrow) char[this->len + 2];
    if (!temp)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    for (int i = 0; i < this->len; i++)
    {
        temp[i] = this->string[i];
    }
    temp[this->len] = c;
    temp[this->len + 1] = '\0';
    this->deallocateMemory();
    this->setString(temp);
    delete[] temp;
}

void MyString::pop_back()
{
    assert(!this->empty());
    if (this->len == 1)
    {
        this->clear();
        return;
    }
    char *temp = new (std::nothrow) char[this->len];
    if (!temp)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    for (int i = 0; i < this->len - 1; i++)
    {
        temp[i] = this->string[i];
    }
    temp[len - 1] = '\0';
    this->setString(temp);
    delete[] temp;
}
MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        this->deallocateMemory();
        this->copy(other);
    }
    return *this;
}
MyString &MyString::operator+=(char c)
{
    this->push_back(c);
    return *this;
}
MyString &MyString::operator+=(const MyString &rhs)
{
    if (!this->string)
    {
        *this = rhs;
        return *this;
    }

    if (!rhs.string)
    {
        return *this;
    }

    size_t oldLen = this->len;
    char *temp = new (std::nothrow) char[this->len];
    if (!temp)
    {
        std::cout << "Problem allocating memory" << std::endl;
    }
    strcpy(temp, this->string);
    this->len += rhs.len;
    delete[] this->string;
    this->string = new (std::nothrow) char[this->len];
    if (this->string)
    {
        for (int i = 0; i < oldLen; i++)
        {
            this->string[i] = temp[i];
        }
        for (int j = 0; j < rhs.len; j++)
        {
            this->string[oldLen + j] = rhs[j];
        }
    }
    delete[] temp;
    return *this;
}
MyString MyString::operator+(char c) const
{
    MyString res = *this;
    res += c;

    return res;
}
MyString MyString::operator+(const MyString &rhs) const
{
    MyString res = *this;
    res += rhs;

    return res;
}

bool MyString::operator==(const MyString &rhs) const
{
    if (this->len != rhs.len)
    {
        return 0;
    }
    if (this->len == 0)
    {
        return 1;
    }
    return (strcmp(this->string, rhs.string) == 0);
}
bool MyString::operator<(const MyString &rhs) const
{
    if(this->string == nullptr)
    {
        return  1;
    }
    if(rhs.string == nullptr)

    {
        return 0;
    }
    return strcmp(this->string, rhs.string) < 0;
}