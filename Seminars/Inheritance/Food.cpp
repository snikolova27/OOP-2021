#include "Food.h"
#include <iostream>
int Food::cnt = 0;

Food::Food(const double weight, const unsigned int parts, const double price)
{
    this->weight = weight;
    this->parts = parts;
    this->partWeight = this->weight / this->parts;
    this->price = price;
    this->id = ++this->cnt;
}

void Food::consume()
{
    if (this->parts == 0)
    {
        std::cout << "No food left" << std::endl;
        return;
    }
    this->parts--;
    this->weight -= this->partWeight;
}
void Food::print()
{
    std::cout << "Id: " << this->id << std::endl;
    std::cout << "Weight: " << this->weight << std::endl;
    std::cout << "Parts: " << this->parts << std::endl;
    std::cout << "Weight per piece: " << this->partWeight << std::endl;
    std::cout << "Price: " << this->price << std::endl;
}
unsigned int Food ::getId() const
{
    return this->id;
}
double Food::getPrice() const
{
    return this->price;
}