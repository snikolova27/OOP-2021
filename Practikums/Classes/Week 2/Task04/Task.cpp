#include "Task.h"
#include <cstring>

Task::Task()
{
    m_title = "none";
    m_description = "none";
}

Task::Task(char *title, char *desc)
{
    strcpy(m_title, title);
    strcpy(m_description, desc);
}
char* Task::getTitle()
{
    return m_title;
}
char* Task::getDescription()
{
    return m_description;
}