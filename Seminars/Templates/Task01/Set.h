#ifndef SET_H
#define SET_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

template <class T>
class Set
{
private:
    std::vector<T> data;

public:
    Set();
    std::size_t getSize();
    bool add(T element);
    bool contains(T element);
    bool isEmpty();
    void remove(T element);
    void write(std::ofstream &file);
    void read(std::ifstream &file);
    bool operator==(const Set<T> &other) const;
    Set<T> operator+(Set<T> &other);
    Set<T> operator*(Set<T> &other);
    Set<T> operator-(Set<T> &other);

    template <class t>
    friend std::ostream &operator<<(std::ostream &out, Set<t> &set);
};

template <class T>
Set<T>::Set() {}

template <class T>
bool Set<T>::add(T element)
{
    if (this->contains(element))
    {
        return false;
    }
    else
    {
        data.push_back(element);
        return true;
    }
}
template <class T>
bool Set<T>::contains(T element)
{
    std::size_t size = this->getSize();
    for (std::size_t i = 0; i < size; i++)
    {
        if (element == this->data[i])
        {
            return true;
        }
    }
    return false;
}
template <class T>
bool Set<T>::isEmpty()
{
    return this->getSize() == 0;
}
template <class T>
void Set<T>::remove(T element)
{
    if (this->contains(element))
    {
        int searchIdx = -1;
        std::size_t size = this->getSize();
        for (std::size_t i = 0; i < size; i++)
        {
            if (element == this->data[i])
            {
                searchIdx = i;
                break;
            }
        }

        this->data.erase(this->data.begin() + searchIdx);
    }
}

template <class T>
std::size_t Set<T>::getSize()
{
    return this->data.size();
}
template <class T>
bool Set<T>::operator==(const Set &other) const
{
    return this->data == other.data;
}
template <class T>
Set<T> Set<T>::operator+(Set<T> &other)
{
    Set<T> result = *this;

    std::size_t otherSize = other.getSize();
    for (std::size_t i = 0; i < otherSize; i++)
    {
        result.add(other.data[i]);
    }

    return result;
}
template <class T>
Set<T> Set<T>::operator*(Set<T> &other)
{
    Set<T> result;

    std::size_t otherSize = other.getSize();
    for (std::size_t i = 0; i < otherSize; i++)
    {
        if (!this->contains(other.data[i]))
        {
            result.add(data[i]);
        }
    }
    return result;
}
template <class T>
Set<T> Set<T>::operator-(Set<T> &other)
{
    Set<T> result = *this;

    std::size_t otherSize = other.getSize();
    for (std::size_t i = 0; i < otherSize; i++)
    {
        if (this->contains(other.data[i]))
        {
            result.remove(other.data[i]);
        }
    }
    return result;
}

template <class t>
std::ostream &operator<<(std::ostream &out, Set<t> &set)
{
    std::cout << "Set: ";
    for (std::size_t i = 0; i < set.getSize(); i++)
    {
        out << set.data[i] << " ";
    }
    return out;
}
template <class T>
void Set<T>::write(std::ofstream &file)
{
    if (file.is_open())
    {
        file << "Set: ";
        for (std::size_t i = 0; i < this->getSize(); i++)
        {
            file << this->data[i] << " ";
        }
        file.close();
    }
}
template <class T>
void Set<T>::read(std::ifstream &file)
{
    if (file.is_open())
    {
       
        for (std::size_t i = 0; i < 100; i++)
        {
            file >> this->data[i];
            if(file.eof())
            {
                break;
            }
        }
        file.close();
    }
}
#endif