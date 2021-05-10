#include "ComputerShop.h"
#include <iostream>
#include <string>
//using std::string;

void ComputerShop::deallocate()
{
    if (this->list)
    {
        delete[] list;
    }
}

ComputerShop::ComputerShop(const std::string _name, const int _capacity)
{
    this->name = _name;
    try
    {
        list = new Computer[_capacity];
    }
    catch (const std::exception &e)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return;
    }
    this->capacity = _capacity;
    this->size = 0;
    for(int i=0; i<this->capacity;i++)
    {
        list[i] = Computer();
    }
  
}

ComputerShop::~ComputerShop()
{
    this->deallocate();
}

const int ComputerShop ::getSize() const
{
    return this->size;
}
void ComputerShop::addComputer( Computer& computer)
{
    if(findComputer(computer.getBrand()))
    {
        computer.quantity++;

    }
    else
    {
        for(int i=0; i<this->capacity;i++)
        {
            if(list[i].getBrand().compare(nullptr))
            {
                list[i] = computer;
                this->size++;
                break;
            }
        }
    }

}
void ComputerShop::printList()
{
    std::cout << "Computers in the list" << std::endl;
    for (int i = 0; i < this->size; i++)
    {
        std::cout << "Computer #" << i + 1 << std::endl;
        std::cout << "Brand: " << list[i].getBrand() << std::endl;
        std::cout << "Processor: " << list[i].getProcessor() << std::endl;
        std::cout << "Video: " << list[i].getVideo() << std::endl;
        std::cout << "Hard drive: " << list[i].getHardDrive() << std::endl;
        std::cout << "Weight: " << list[i].getWeight() << std::endl;
        std::cout << "Battery life: " << list[i].getBatteryLife() << std::endl;
        std::cout << "Price: " << list[i].getPrice() << std::endl;
        std::cout << "Quantity: " << list[i].getQuantity() << std::endl;
    }
}
void ComputerShop::buyComputer(const std::string _brand, int _money)
{
    for(int i=0; i<this->capacity;i++)
    {
        if(list[i].getBrand() == _brand)
        {
            if( list[i].getPrice() > _money)
            {
                throw std::invalid_argument("Not enough money");
            }
            else
            {
                if( list[i].getQuantity() !=0)
                {
                    std::cout << "You have successfully bought the computer" << std::endl;
                    list[i].quantity-=1;
                }
                else
                {
                    std::cout << "There are none of these computers left" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "There isn't such a computer in the shop" << std::endl;
        }
    }
}
void ComputerShop::filteredComputers()
{
}
bool ComputerShop ::findComputer(std::string _brand)
{
    for (int i = 0; i < this->getSize(); i++)
    {
        if (_brand.compare(list[i].getBrand()) == 0)
        {
            return true;
        }
    }
}