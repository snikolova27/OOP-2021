#ifndef TODOLIST_H
#define TODOLIST_H
#include "Task.h"
#include <iostream>

class ToDoList
{
private:
    Task* m_tasks;
    size_t m_capacity;
    size_t m_size = 0;

    void resize();

public:
    ToDoList();
    ToDoList(const size_t capacity);

    void pushTask(Task task);
    Task popTask();
    void printSize();

    bool isEmpty();

    ~ToDoList();
};

#endif
