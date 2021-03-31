#ifndef TASK_H
#define TASK_H

class Task
{
    private:
    char* m_title;
    char* m_description;

    public:
    Task();
    Task(char* title, char* desc);
    char* getTitle();
    char* getDescription();
};

#endif