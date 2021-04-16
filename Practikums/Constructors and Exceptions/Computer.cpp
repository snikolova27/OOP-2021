#include "Computer.h"

int Computer::cnt = 0;
Computer::Computer()
{
    this->serialNumber = ++cnt;;
    this->brand = nullptr;
    this->processor = nullptr;
    this->video = nullptr;
    this->hardDrive = 0;
    this->weight = 0;
    this->batteryLife = 0;
    this->price = 0;
    this->quantity = 0;
}
Computer::Computer(std::string _brand, std::string _processor, std::string _video,
                   int _hardDrive, double _weight, int _batteryLife, int _price, int _quantity)
{
    this->serialNumber = ++cnt;
    this->brand = _brand;
    this->processor = _processor;
    this->video = _video;
    this->hardDrive = _hardDrive;
    this->weight = _weight;
    this->batteryLife = _batteryLife;
    this->price = _price;
    this->quantity = _quantity;
}
Computer::Computer(const Computer &other)
{
    this->copy(other);
}
void Computer::copy(const Computer &other)
{
    if (this == &other)
    {
        return;
    }
    this->serialNumber = other.serialNumber;
    this->brand = other.brand;
    this->processor = other.processor;
    this->video = other.video;
    this->hardDrive = other.hardDrive;
    this->weight = other.weight;
    this->batteryLife = other.batteryLife;
    this->price = other.price;
    this->quantity = other.quantity;
}
//--------setters--------
void Computer::setBrand(const std::string _brand)
{
    this->brand = _brand;
}
void Computer::setProcessor(const std::string _processor)
{
    this->processor = _processor;
}
void Computer::setVideo(const std::string _video)
{
    this->video = _video;
}
void Computer::setHardDrive(const int _hardDrive)
{
    this->hardDrive = _hardDrive;
}
void Computer::setWeight(const double _weight)
{
    this->weight = _weight;
}
void Computer::setBatteryLife(const int _batteryLife)
{
    this->batteryLife = _batteryLife;
}
void Computer::setPrice(const int _price)
{
    this->price = _price;
}
void Computer::setQuantity(const int _quantity)
{
    this->quantity = _quantity;
}
//--------getters--------
int Computer::getSerialNumber() const
{
    return this->serialNumber;
}
std::string Computer::getBrand() const
{
    return this->brand;
}
std::string Computer::getProcessor() const
{
    return this->processor;
}
std::string Computer::getVideo() const
{
    return this->video;
}
int Computer::getHardDrive() const
{
    return this->hardDrive;
}
double Computer::getWeight() const
{
    return this->weight;
}
int Computer::getBatteryLife() const
{
    return this->batteryLife;
}
int Computer::getPrice() const
{
    return this->price;
}
int Computer::getQuantity() const
{
    return this->quantity;
}
Computer &Computer::operator=(const Computer &other)
{
    if (this == &other)
    {
        return *this;
    }
    copy(other);
}