#include "WashingMachine.h"
#include "utils.h"
#include <iostream>

//-------------------- helper functions--------------------
// --------------------------------------------------------

void WashingMachine::copy(const WashingMachine &other)
{
    this->manufacturer = copyDynStr(other.manufacturer);
    this->model = copyDynStr(other.model);
    this->capacity = other.capacity;
    this->elConsumption = other.elConsumption;
    this->waterConsumption = other.waterConsumption;
}

void WashingMachine ::erase()
{
    delete[] manufacturer;
    delete[] model;
}

//--------------------- constructors ----------------------
// --------------------------------------------------------

WashingMachine::WashingMachine()
{
    this->manufacturer = nullptr;
    this->model = nullptr;
    this->capacity = 0;
    this->elConsumption = 0;
    this->waterConsumption = 0;
}

WashingMachine ::WashingMachine(const char *_manufacturer, const char *_model,
                                const int _capacity, const double _elConsumption, const int _waterConsumption)
{
    this->manufacturer = copyDynStr(_manufacturer);
    this->model = copyDynStr(_model);
    this->capacity = _capacity;
    this->elConsumption = _elConsumption;
    this->waterConsumption = _waterConsumption;
}

WashingMachine::WashingMachine(const WashingMachine &other)
{
    copy(other);
}

WashingMachine::~WashingMachine()
{
    erase();
}

//------------------------ setters ------------------------
// --------------------------------------------------------

void WashingMachine::setManufacturer(const char *_manufacturer)
{
    this->manufacturer = copyDynStr(_manufacturer);
    if (!this->manufacturer)
    {
        std::cout << "memory allocation problem";
        this->manufacturer = nullptr;
    }
}

void WashingMachine::setModel(const char *_model)
{
    this->model = copyDynStr(_model);
    if (!this->model)
    {
        std::cout << "memory allocation problem";
        this->model = nullptr;
    }
}

void WashingMachine::setCapacity(const int _capacity)
{
    this->capacity = _capacity;
}

void WashingMachine::setElConsumption(const double _elConsumption)
{
    this->elConsumption - _elConsumption;
}

void WashingMachine::setWaterConsumption(const int _waterConsumption)
{
    this->waterConsumption = _waterConsumption;
}

//------------------------ getters ------------------------
// --------------------------------------------------------

char *WashingMachine::getManufacturer() const
{
    return this->manufacturer;
}

char *WashingMachine::getModel() const
{
    return this->model;
}
int WashingMachine::getCapacity() const
{
    return this->capacity;
}
double WashingMachine::getElConsumption() const
{
    return this->elConsumption;
}
int WashingMachine::getWaterConsumption() const
{
    return this->waterConsumption;
}

//-------------------- class functions --------------------
// --------------------------------------------------------

void WashingMachine::print()
{
    std::cout << "Manufacturer: " << manufacturer << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Capacity in kg: " << capacity << std::endl;
    std::cout << "Electro consumption: " << elConsumption << std::endl;
    std::cout << "Water consumption: " << waterConsumption << std::endl;
}

bool WashingMachine::operator>(const WashingMachine &other)
{
    return (this->capacity > other.capacity) ||
           (this->capacity == other.capacity && this->elConsumption < other.elConsumption) ||
           (this->capacity == other.capacity && this->elConsumption == other.elConsumption && this->waterConsumption < other.waterConsumption);
}
void WashingMachine::inputWashingMachine()
{
       
    std::cout << "Enter name of manufacturer: ";
    this->setManufacturer(inputStr());
    std::cout << "Enter model of washing machine: ";
    this->setModel(inputStr());
    std::cout << "Enter capacity in kg: ";
    std::cin >> this->capacity;
    std::cout << "Enter electro consumption: ";
    std::cin >> this->elConsumption;
    std::cout << "Enter water consumption: ";
    std::cin >> this->waterConsumption;
    std::cin.ignore();
}