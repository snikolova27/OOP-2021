#ifndef TASK_H
#define TASK_H

class Task
{
private:
    char *m_title;
    char *m_description;

    void deallocate();

public:
    Task();
    Task(const char *title, const char *desc);

    void setTitle(const char *title);
    void setDescription(const char *desc);

    char *getTitle() const;
    char *getDescription() const;

    ~Task();
};

#endif