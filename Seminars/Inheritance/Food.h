#ifndef FOOD_H
#define FOOD_H

class Food
{
protected:
    double weight;
    unsigned int parts;
    double partWeight;
    double price;
    unsigned int id;
    static int cnt;

public:
    Food(const double weight, const  unsigned int parts, const double price);
    void consume();
    void print();
    unsigned int getId() const;
    double getPrice() const;
};
#endif