#include "MyString.h"
#include <cstring>
#include <cassert>

//------------ private methods ------------
// Functions used for executing the class and costructor/destructor functions easier
void MyString::deallocateMemory()
{
    if (this->string)
    {
        delete[] this->string;
        //this->string = nullptr;
    }
    
}

char *MyString::copyDynStr(const char *str)
{
    if (str == nullptr)
    {
        return nullptr;
    }
    char *res;
    try
    {
        res = new char[strlen(str) + 1];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory";
        return nullptr;
    }
    strcpy(res, str);
    return res;
}
void MyString::copy(const MyString &other)
{
    if (other.string == nullptr)
    {
        this->string = nullptr;
        this->len = 0;
        return;
    }
    try
    {
        this->string = new char[other.len + 1];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    strcpy(this->string, other.string);
    this->len = other.len;
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
    if (this->string == nullptr)
    {
        this->len = 0;
    }
    else
    {
        this->len = strlen(string);
    }
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
    if (this->string == nullptr)
    {
        this->len = 0;
        return;
    }
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
    return this->len == 0;
}
void MyString::clear()
{
    this->deallocateMemory();
    this->len = 0;
    this->string=nullptr;
}
void MyString::push_back(char c)
{
    if (!this->string)
    {
        try
        {
            this->string = new char[2];
        }
        catch (std::bad_alloc &e)
        {
            std::cout << "Problem allocating memory" << std::endl;
            return;
        }

        this->string[0] = c;
        this->string[1] = '\0';
        this->len = 1;
        return;
    }
    char *temp;
    try
    {
        temp = new char[this->len + 2];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    size_t i = 0;
    while ( i < this->len)
    {
        temp[i] = this->string[i];
        i++;
    }
    temp[this->len] = c;
    temp[this->len + 1] = '\0';
    this->deallocateMemory();
    this->setString(temp);
    delete[] temp;
}

void MyString::pop_back()
{
    //assert(!this->empty());
    if (this->len == 1 || this->len == 0)
    {
        this->clear();
        return;
    }
    char *temp;
    try
    {
        temp = new char[this->len];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    size_t i = 0;
    while(i < this->len - 1)
    {
        temp[i] = this->string[i];
        i++;
    }
    temp[len - 1] = '\0';
    this->setString(temp);
    delete[] temp;
}
//----------- operator overloading ------------
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
    if (!this->string || this->len == 0)
    {
        *this = rhs;
        return *this;
    }

    if (!rhs.string)
    {
        return *this;
    }

    size_t oldLen = this->len;
    char *temp;
    try
    {
        temp = new char[this->len];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return *this;
    }

    strcpy(temp, this->string);
    this->len += rhs.len;
    delete[] this->string;
    try
    {
        this->string = new char[this->len];
    }
    catch (std::bad_alloc &e)
    {
        this->string = new char[oldLen];
        stpcpy(this->string, temp);
        return *this;
    }
    size_t i = 0;
    while ( i < oldLen)
    {
        this->string[i] = temp[i];
        i++;
    }
    size_t j = 0;
    while (j < rhs.len)
    {
        this->string[oldLen + j] = rhs[j];
        j++;
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
    if (this->string == nullptr)
    {
        return 1;
    }
    if (rhs.string == nullptr)

    {
        return 0;
    }
    return strcmp(this->string, rhs.string) < 0;
}