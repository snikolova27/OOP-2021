#include "Task.h"
#include "Utils.h"
#include <cstring>
#include <iostream>

Task::Task()
{
    m_title = nullptr;
    m_description = nullptr;
}

char *Task::getTitle() const
{
    return m_title;
}
char *Task::getDescription() const
{
    return m_description;
}

void Task::setTitle(const char *title)
{
    delete[] m_title;
    m_title = copyDynStr(title);
}

void Task::setDescription(const char* desc)
{
    delete[] m_description;
    m_description = copyDynStr(desc);
}
Task::Task(const char *title, const char *desc)
{
    m_title = new (std::nothrow) char[strlen(title) + 1];
    if (m_title)
    {
        strcpy(m_title, title);
    }

    m_description = new (std::nothrow) char[strlen(desc) + 1];
    if(m_description)
    {
        strcpy(m_description, desc);
    }
}
 void Task::deallocate()
{
    delete[] m_title;
    delete[] m_description;
}
Task::~Task()
{
    deallocate();
}