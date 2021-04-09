#ifndef CAR_H
#define CAR_H
#include "Person.h"
#include "Enums.h"

class Car
{
    private:
    Person m_owner;
    char* m_brand;
    Color m_color;
    char* m_licensePlate;
    
    void erase();
    void copy(const Car& other);

    public:
    Car();
    Car(const Person owner, const char* brand, const Color color, const char* licensePlate);
    Car(const Car& other);

    Car& operator = (const Car& other);

    Person getOwner() const;
    char* getBrand() const;
    char* getLicensePlate() const;
    Color getColor() const;

    void setOwner(const Person& owner);
    void setBrand(const char* brand);
    void setLicensePlate(const char* licensePlate);
    void setColor(const Color& color);

    void print();

    ~Car();

};

#endif