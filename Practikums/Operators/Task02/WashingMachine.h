#ifndef WASHING_MACHINE_H
#define WASHING_MACHINE_H

class WashingMachine
{
private:
    char *manufacturer;
    char *model;
    int capacity;
    double elConsumption;
    int waterConsumption;

    void copy(const WashingMachine &other);
    void erase();

public:
    WashingMachine();
    WashingMachine(const char *_manufacturer, const char *_model,
                   const int _capacity, const double _elConsumption, const int _waterConsumption);
    WashingMachine(const WashingMachine &other);

    void setManufacturer(const char *_manufacturer);
    void setModel(const char *_model);
    void setCapacity(const int _capacity);
    void setElConsumption(const double _elConsumption);
    void setWaterConsumption(const int _waterConsumption);

    char *getManufacturer() const;
    char *getModel() const;
    int getCapacity() const;
    double getElConsumption() const;
    int getWaterConsumption() const;

    WashingMachine &getOptimalWM(const WashingMachine *array);
    bool operator>(const WashingMachine &other);
    void print();
    void inputWashingMachine();


    ~WashingMachine();
};

#endif