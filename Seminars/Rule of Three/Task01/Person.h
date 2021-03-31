#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
    char *m_name;
    short m_age;
    bool m_driversLicense;

    void erase();
    void copy(const Person& A);

public:
    Person();
    Person(const char *name, const short age, const bool driversLicense);
    Person(const Person& other);

    Person& operator = (const Person& other);
    ~Person();

    char *getName() const;
    void setName(const char *name);

    short getAge() const;
    void setAge(const short age);

    bool getDriversLicense() const;
    void setDriversLicense(const bool driversLicense);

    void printPerson();
};
#endif