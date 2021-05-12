#include "University.h"

const std::size_t INITIAL_CAPACITY = 2;
const std::size_t INCREASE_STEP = 2;

void University::resize()
{

    size_t newCapacity = this->capacity * INCREASE_STEP;

    Student **newStudents = nullptr;
    try
    {
        newStudents = new Student *[newCapacity];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (int i = 0; i < newCapacity; ++i)
    {
        if (i < this->size)
        {
            newStudents[i] = new Student(*this->students[i]);
        }
        else
        {
            newStudents[i] = nullptr;
        }
    }

    this->deallocate();
    this->students = newStudents;
    this->capacity = newCapacity;
}
void University::copy(const University &other)
{
    Student **buffer = nullptr;
    try
    {
        buffer = new Student *[other.capacity];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (int i = 0; i < other.capacity; ++i)
    {
        if (i < other.size)
        {
            buffer[i] = new Student(*other.students[i]);
        }
        else
        {
            buffer[i] = nullptr;
        }
    }

    this->students = buffer;
    this->size = other.size;
    this->capacity = other.capacity;
}
void University::deallocate()
{
    for (int i = 0; i < this->capacity; ++i)
    {
        if (this->students[i])
        {
            delete this->students[i];
        }
    }

    delete[] this->students;
}

University::University()
{
    try
    {
        this->students = new Student *[INITIAL_CAPACITY];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0); //???
    }

    for (int i = 0; i < INITIAL_CAPACITY; ++i)
    {
        this->students[i] = nullptr;
    }

    this->capacity = INITIAL_CAPACITY;
    this->size = 0;
}

University::University(const University &other)
{
    this->copy(other);
}
University &University::operator=(const University &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}
University::~University()
{
    this->deallocate();
}

void University::addStudent(std::string _name, std::string _fn, bool _signedUp)
{
    if (this->size >= this->capacity)
    {
        this->resize();
    }
    this->students[this->size++] = new Student(_name, _fn, _signedUp);
}

void University::addStudent(const Student &student)
{
    if (this->size >= this->capacity)
    {
        this->resize();
    }

    this->students[this->size++] = new Student(student);
}

std::size_t University:: getSize() const
{
    return this->size;
}
University University::operator+(const University &other)
{
    University result = *this;

    for (int i = 0; i < other.size; ++i)
    {
        result.addStudent(*other.students[i]);
    }

    return result;
}
Student &University::operator[](std::size_t position)
{
    if (position <= this->size)
    {
        return *(this->students[position]);
    }
    else
    {
        throw std::out_of_range("Invalid position");
    }
}