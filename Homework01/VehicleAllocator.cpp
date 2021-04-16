#include "VehicleAllocator.h"
#include <cstring>

//------------ private methods ------------
void VehicleAllocator::resize()
{
    Vehicle **resizedVehicles = nullptr;

    try
    {
        resizedVehicles = new Vehicle *[this->capacity * RESIZE_STEP];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    std::size_t i = 0;
    while (i < this->capacity * RESIZE_STEP)
    {
        if (i < this->used)
        {
            try
            {
                resizedVehicles[i] = new Vehicle(*(this->vehicles[i]));
            }
            catch (std::bad_alloc &e)
            {
                std::cout << "Problem allocating memory" << std::endl;
                std::size_t k = 0;
                while (k < i)
                {
                    delete resizedVehicles[k];
                    k++;
                }
                delete[] resizedVehicles;
                return;
            }
        }
        else
        {
            resizedVehicles[i] = nullptr;
        }
        i++;
    }

    this->deallcolate();
    this->capacity *= RESIZE_STEP;
    this->vehicles = resizedVehicles;
}
void VehicleAllocator::deallcolate()
{
    if (this->vehicles)
    {
        std::size_t i = 0;
        while (i < this->capacity)
        {
            if (this->vehicles[i])
            {
                delete this->vehicles[i];
            }
            i++;
        }
        delete[] this->vehicles;
    }
}
void VehicleAllocator::copy(const VehicleAllocator &other)
{
    if (this == &other)
    {
        return;
    }

    Vehicle **temp = nullptr;
    try
    {
        temp = new Vehicle *[other.capacity];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    std::size_t i = 0;
    while (i < other.capacity)
    {
        if (i < other.used)
        {
            try
            {
                temp[i] = new Vehicle(*(other.vehicles[i]));
            }
            catch (std::bad_alloc &e)
            {
                std::cout << "Problem allocating memory" << std::endl;
                std::size_t k = 0;
                while (k < i)
                {
                    delete temp[k];
                    k++;
                }
                delete[] temp;
                return;
            }
        }
        else
        {
            temp[i] = nullptr;
        }
        i++;
    }
    this->deallcolate();
    this->vehicles = temp;
    this->used = other.used;
    this->capacity = other.capacity;
}
//------------ constructors ------------
VehicleAllocator::VehicleAllocator()
{
    this->capacity = STARTING_CAPACITY;
    this->used = 0;

    try
    {
        this->vehicles = new Vehicle *[STARTING_CAPACITY];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    std::size_t i = 0;
    while (i < STARTING_CAPACITY)
    {
        this->vehicles[i] = nullptr;
        i++;
    }
}
VehicleAllocator::VehicleAllocator(const VehicleAllocator &other)
{
    this->copy(other);
}

//------------ getters ------------
std::size_t VehicleAllocator::getCapacity() const
{
    return this->capacity;
}
std::size_t VehicleAllocator::getUsed() const
{
    return this->used;
}

//------------ class functions ------------
void VehicleAllocator::createVehicle(const char *_licensePlate, const char *_description, std::size_t _space)
{
    if (this->used >= this->capacity)
    {
        this->resize();
    }
    if (this->findVehicle(_licensePlate))
    {
        std::cout << "Cannot have two vehicles with equal license plates - " << _licensePlate << std::endl;
        return;
    }

    try
    {
        this->vehicles[this->used] = new Vehicle(_licensePlate, _description, _space);
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    this->used += 1;
    std::cout << "You have created a vehicle with a license plate " << _licensePlate << std::endl;
}
void VehicleAllocator::deleteVehicle(const char *_licensePlate)
{
    std::size_t i = 0;
    while (i < this->used)
    {
        if (strcmp(_licensePlate, this->vehicles[i]->registration()) == 0)
        {
            delete this->vehicles[i];
            this->vehicles[i] = this->vehicles[this->used - 1];
            this->vehicles[this->used - 1] = nullptr;
            this->used -= 1;

            std::cout << "Vehicle with license plate " << _licensePlate << " has been deleted" << std::endl;
            return;
        }
        i++;
    }
    std::cout << "No such vehicle" << std::endl;
}
Vehicle *VehicleAllocator::findVehicle(const char *_licensePlate)
{
    std::size_t i = 0;
    while (i < this->used)
    {
        if (strcmp(this->vehicles[i]->registration(), _licensePlate) == 0)
        {
            return this->vehicles[i];
        }
        i++;
    }
    return nullptr;
}
Vehicle &VehicleAllocator::at(std::size_t pos) const
{
    if (pos >= this->used)
    {
        throw std::out_of_range("No such position");
    }
    return *(this->vehicles[pos]);
}
void VehicleAllocator::deleteAll()
{
    std::size_t i = 0;
    while (i < this->capacity)
    {
        if (this->vehicles[i])
        {
            delete this->vehicles[i];
        }
        i++;
    }
    this->used = 0;
    std::cout << "Created vehicles have been deleted" << std::endl;
}
bool VehicleAllocator::isEmpty() const
{
    return this->used == 0;
}
//----------- operator overloading ------------
VehicleAllocator &VehicleAllocator::operator=(const VehicleAllocator &other)
{
    this->deallcolate();
    this->copy(other);
    return *this;
}
void VehicleAllocator::print()
{
    std::cout << "============="
              << "Allocated vehicles "
              << "=============" << std::endl;
    std::cout << "Count of allocated vehicles is " << this->getUsed() << std::endl;
    if (!this->isEmpty())
    {
        std::size_t i = 0;
        while (i < this->used)
        {
            std::cout<< "Vehicle " << i + 1 << " license plate: "<< this->vehicles[i]->registration() << std::endl;
            i++;
        }
    }
}

//------------ destructor ------------
VehicleAllocator::~VehicleAllocator()
{
    this->deallcolate();
}