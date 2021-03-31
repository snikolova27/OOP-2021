#ifndef PERSON_H
#define PERSON_H

class Person
{
    private:
    char* m_name;
    short m_age;
    bool m_driversLicense;

    public:

    Person();
    Person(char* name, short age, bool driversLicense);
    ~Person();

    char* getName();
    void setName(char* name);

    short getAge();
    void setAge(short age);

    bool getDriversLicense();
    void setDriversLicense(bool driversLicense);

    void printPerson();

};
#endif