#include "Queue.h"
const int INITIAL_CAPACITY = 2;

void Queue::copy(const Queue &other)
{
    this->size = other.size;
    this->quantity = other.quantity;

    try
    {
        this->tickets = new Ticket[other.size];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < this->quantity; i++)
    {
        this->tickets[i] = other.tickets[i];
    }
}

void Queue::deallocate()
{
    if (this->tickets)
    {
        delete[] this->tickets;
    }
    this->quantity = 0;
    this->size = 0;
}
Queue::Queue()
{
    this->quantity = 0;
    this->size = INITIAL_CAPACITY;
    try
    {
        this->tickets = new Ticket[this->size];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
Queue::Queue(const Queue &other)
{
    this->copy(other);
}
Queue::Queue(const size_t size)
{
    this->quantity = 0;
    this->size = size;
    try
    {
        this->tickets = new Ticket[this->size];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
Queue::~Queue()
{
    this->deallocate();
}
int Queue::getTicket(const char *_name, const char *_phone, const int _uniqueNum)
{
    try
    {
        if (this->quantity == this->getSize())
        {
            throw std::overflow_error("Full queue");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Ticket ticket(_name, _phone, _uniqueNum);
    this->tickets[this->quantity++] = ticket;

    return this->quantity - 1;
}
Ticket Queue::next()
{
    try
    {
        if (this->quantity == 0)
        {
            throw std::out_of_range("queue is empty");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Ticket result;
    result = this->tickets[0];

    for(int i=0; i< this->quantity - 1;i++)
    {
        this->tickets[i]  =this->tickets[i+1];
    }
    --this->quantity;

    return result;
}
bool Queue::isEmpty() const
{
    return this->quantity == 0;
}
size_t Queue::getSize() const
{
    return this->size;
}
Queue &Queue::operator=(const Queue &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }
    return *this;
}

Ticket &Queue::operator[](size_t position)
{
    try
    {
        if (position >= this->getSize())
        {
            throw std::invalid_argument("Invalid position");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return this->tickets[position];
}