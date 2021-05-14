#ifndef LIST_H
#define LIST_H
#include <vector>
#include <iostream>
#include <fstream>

template <class T>
class List
{
protected:
    std::vector<T> list;

public:
    List();
    void add(T element);
    void removeAt(int position);
    int getSize() const;
    bool isEmpty() const;

    void read(std::string file);
    void write(std::string file);

    T operator[](int position);
};

template <class T>
List<T>::List() {}

template <class T>
void List<T>::add(T element)
{
    for (int i = 0; i < this->list.size(); i++)
    {
        if (element == this->list[i])
        {
            std::cout << "Element is already in the list" << std::endl;
            return;
        }
    }
    this->list.push_back(element);
}

template <class T>
void List<T>::removeAt(int position)
{
    if (position >= this->list.size())
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }

    this->list.erase(this->list.begin() + position);
}

template <class T>
int List<T>::getSize() const
{
    return this->list.size();
}

template <class T>
bool List<T>::isEmpty() const
{
    return this->list.size() == 0;
}

template <class T>
T List<T>::operator[](int position)
{
    if (position >= this->list.size())
    {
        std::cout << "Invalid position" << std::endl;
        return -1;
    }

    return this->list.at(position);
}

template <class T>
void List<T>::read(std::string file)
{
    std::ifstream input(file.c_str());

    if (input.is_open())
    {
        T temp;
        while (input >> temp)
        {
            this->add(temp);
        }

        input.close();
    }
}

template <class T>
void List<T>::write(std::string file)
{
    std::ofstream output(file.c_str());

    if (!this->isEmpty())
    {
        if (output.is_open())
        {

            for (int i = 0; i < this->getSize(); i++)
            {
                output << this->list[i] << std::endl;
            }

            output.close();
        }
    }
}
#endif