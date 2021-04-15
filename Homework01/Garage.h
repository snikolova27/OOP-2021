#ifndef GARAGE_H
#define GARAGE_H
#include "Vehicle.h"

class Garage
{
private:
    std::size_t capacity; // max spaces for vehicles to occupy
    std::size_t used;
    int cntOfVehicles;
    Vehicle **vehicles;

    //------------ private methods ------------
    void deallocate();
    void copy(const Garage &other);

public:
    //------------ constructors ------------
    Garage(std::size_t size);
    Garage(const Garage &other);

    //------------ getters ------------
    std::size_t getSize() const;  //return count of vehicles in the garage

    //------------ class functions ------------
    void insert(Vehicle &v); //strong exception guarantee
    void erase(const char *_licensePlate);
    const Vehicle &at(std::size_t pos) const;
    bool empty() const;
    void clear();
    void print();
    const Vehicle *find(const char *_licensePlate) const;

    //----------- operator overloading ------------
    Garage &operator=(const Garage &other);
    const Vehicle &operator[](std::size_t pos) const; //assert pos
    
    //------------ destructor ------------
    ~Garage();
};
#endif