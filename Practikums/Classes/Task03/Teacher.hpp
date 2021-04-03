#ifndef TEACHER_H
#define TEACHER_H

class Teacher
{
    private:
    char* name;
    char* teachingClass;

public:
    Teacher();
    Teacher(const char* _name, const char* _teachingClass);

    void setName(const char* _name);
    void setTeachingClass(const char* _teachingClass);

    char* getName() const;
    char* getTeachingClass() const;

    void input();
    void deallocate();
    void print();
    void copyTeacher(Teacher& teacher);

    ~Teacher();


};

#endif