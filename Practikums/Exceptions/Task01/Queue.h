#ifndef QUEUE_H
#define QUEUE_H
#include "Ticket.h"

class Queue
{
private:
    size_t size;
    size_t quantity;
    Ticket *tickets;

    void copy(const Queue &other);
    void deallocate();

public:
    Queue();
    Queue(const Queue &other);
    Queue(const size_t size);

    int getTicket(const char *_name, const char *_phone, const int _uniqueNum);
    Ticket next();
    bool isEmpty() const;
    size_t getSize() const;

    Ticket &operator[](size_t position);
    Queue &operator=(const Queue &other);

    ~Queue();
};
#endif