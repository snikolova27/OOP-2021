#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Student.hpp"
#include "Teacher.hpp"

const int MAX_NUM_STUDENTS = 100;

enum Field
{
    name,
    fn,
    avgScore
};

enum Order
{
    asc,
    desc
};

template <typename T>
using sortingFunction = bool (*) (T, T, Order);

template <typename T>
bool nameSort(T first, T second, Order order)
{
    int comparison = strcmp(first.getName(), second.getName());
    return (order == asc) ? (comparison > 0) : (comparison < 0);
}

template <typename T>
bool fnSort(T first, T second, Order order)
{
    int comparison = strcmp(first.getFN(), second.getFN());
    return (order == asc) ? (comparison > 0) : (comparison < 0);
}

template <typename T>
bool averageGradeSort(T first, T second, Order order)
{
    return (order == asc) ? (first.getAverageGrade() > second.getAverageGrade()) : (first.getAverageGrade() < second.getAverageGrade());
}

template <typename T>
class University
{
    private:
        T* people;
        size_t numberPeople = 0;

        sortingFunction<T> getComparison(Field field)
        {
            switch (field)
            {
                case name:
                    return nameSort<T>;
                case fn:
                    return fnSort<T>;
                case avgScore:
                    return averageGradeSort<T>;
                default:
                    return nameSort<T>;
            }
        }

    public:
        void createPeople(T* people, size_t size)
        {
            this->people = new(std::nothrow) T[size];
            if (!this->people)
            {
                std::cout << "Memory problem!" << std::endl;
                return;
            }

            for (int i = 0; i < size; ++i)
            {
                this->people[i] = people[i];
            }

            this->numberPeople = size;
        }

        void sort(Field field, Order order)
        {
            for (int i = 0; i < numberPeople; ++i)
            {
                for (int j = i+1; j < numberPeople; ++j)
                {
                    if (getComparison(field)(people[i], people[j], order))
                    {
                        std::swap(people[i], people[j]);
                    }
                }
            }
        }

        void printPeople()
        {
            for (int i = 0; i < this->numberPeople; ++i)
            {
                this->people[i].print();
            }
        }
};
#endif