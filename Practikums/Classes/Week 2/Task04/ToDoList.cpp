#include "ToDoList.h"
#include <iostream>
#include <cmath>

ToDoList::ToDoList()
{
    m_capacity = 2;
    m_tasks = new (std::nothrow) Task[m_capacity];
}

ToDoList::ToDoList(const size_t capacity)
{
    m_tasks = new Task[capacity];
    m_capacity = capacity;
}

ToDoList::~ToDoList()
{
    delete[] m_tasks;
}

void ToDoList::resize()
{
    m_capacity *= 2;

    Task *newTasks = new (std::nothrow) Task[m_capacity];
    for (int i = 0; i < m_size; i++)
    {
        newTasks[i] = m_tasks[i];
    }

    delete[] m_tasks;
    m_tasks = newTasks;
}

void ToDoList::pushTask(const Task task)
{
    if (m_size == m_capacity)
    {
        resize();
    }

    m_tasks[m_size] = task;
    m_size++;
}

Task ToDoList::popTask()
{
    Task result = m_tasks[0];

    for (int i = 0; i < m_size - 1; i++)
    {
        result = m_tasks[i + 1];
    }
    if (!isEmpty())
    {
        --m_size;
    }
    return result;
}
void ToDoList::printSize()
{
    std::cout << "Number of tasks; " << m_size << std::endl;
    std::cout << "Capacity of the list: " << m_capacity << std::endl;
    std::cout << "The list is: " << ((double)m_size) / ((double)m_capacity) * 100 << "% full" << std::endl;
}
bool ToDoList::isEmpty()
{
    return m_size == 0;
}