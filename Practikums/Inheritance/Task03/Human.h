#ifndef HUMAN_H
#define HUMAN_H
#include <string>

class Human
{
    private:
    std::string firstName;
    std::string lastName;
    int age;
    public:
    Human(std::string _firstName, std::string _lastName, int _age);
    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;
};
#endif