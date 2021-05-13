#ifndef TICKET_H
#define TICKET_H
#include <iostream>

class Ticket
{
private:
    char *name;
    char *phoneNum;
    int uniqueNum;

    void copy(const Ticket &other);
    void deallocate();

    bool validateName(const char* _name);
    bool validatePhone(const char* _validate);

public:
    void setName(const char *_name);
    void setPhoneNum(const char *_phone);
    void setUniqueNum(const int _num);

    const char *getName() const;
    const char *getPhone() const;
    const int getUniqueNum() const;

    Ticket();
    Ticket(const char *_name, const char *_phoneNum, const int _uniqueNum);
    Ticket(const Ticket &other);

     Ticket& operator = (const Ticket& other);
     
    friend std::istream &operator>>(std::istream &in, Ticket &ticket);
    friend std::ostream &operator<<(std::ostream &out, const Ticket &ticket);

    ~Ticket();
};
#endif