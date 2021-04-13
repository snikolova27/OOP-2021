#ifndef GARAGE_H
#define GARAGE_H
#include "Vehicle.h"

const int INITIAL_CAPACITY = 2;
const int RESIZE_STEP = 2;

class Garage
{
private:
    std::size_t capacity;
    std::size_t size;
    Vehicle *cars;

    void resize();
    void deallocate();
    void copy(const Garage &other);

public:
    //------------ constructors ------------
    Garage(std::size_t size);
    Garage(const Garage &other);

    //------------ getters ------------
    std::size_t getSize() const;
    
    //------------ class functions ------------
    void insert(Vehicle &v); //strong exception guarantee
    void erase(const char *_licensePlate);
    const Vehicle &at(std::size_t pos) const;
    bool empty() const;
    void clear();
    const Vehicle *find(const char *_licensePlate) const;

  
    Garage &operator=(const Garage &other);
    const Vehicle &operator[](std::size_t pos) const; //assert pos

    //------------ destructor ------------
    ~Garage();
};
#endif