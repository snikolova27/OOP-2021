#ifndef VEHICLE_ALLOCATOR_H
#define VEHICLE_ALLOCATOR_H
#include "Vehicle.h"

const int STARTING_CAPACITY = 2;
const int RESIZE_STEP = 2;

class VehicleAllocator
{
private:
    Vehicle **vehicles;
    std::size_t capacity;
    std::size_t used;

    //------------ private methods ------------
    void resize();
    void deallcolate();
    void copy(const VehicleAllocator &other);

public:
    //------------ constructors ------------
    VehicleAllocator();
    VehicleAllocator(const VehicleAllocator &other);

    //------------ getters ------------
    std::size_t getCapacity() const;
    std::size_t getUsed() const;

    //------------ class functions ------------
    void createVehicle(const char *_licensePlate, const char *_desciption, std::size_t _space);
    void deleteVehicle(const char *_licensePlate);
    Vehicle *findVehicle(const char *_licensePlate);
    Vehicle& at(std::size_t pos) const;

    void deleteAll();
    bool isEmpty() const;
    void print();
    //----------- operator overloading ------------
    VehicleAllocator &operator=(const VehicleAllocator &other);
   
    //------------ destructor ------------
    ~VehicleAllocator();
};
#endif