#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

class Computer
{
private:
    static int cnt;
    int serialNumber;
    std::string brand;
    std::string processor;
    std::string video;
    int hardDrive;
    double weight;
    int batteryLife;
    int price;

    void deallocate();
    void copy(const Computer &other);

public:
    int quantity;
    //-------- constructors --------
    Computer();
    Computer(std::string _brand, std::string _processor, std::string _video,
             int _hardDrive, double _weight, int _batteryLife, int _price, int _quintity);
    Computer(const Computer &other);

    //--------setters--------
    void setBrand(const std::string _brand);
    void setProcessor(const std::string _processor);
    void setVideo(const std::string _video);
    void setHardDrive(const int _hardDrive);
    void setWeight(const double _weight);
    void setBatteryLife(const int _batteryLife);
    void setPrice(const int _price);
    void setQuantity(const int _quantity);

    //--------getters--------
    int getSerialNumber() const;
    std::string getBrand() const;
    std::string getProcessor() const;
    std::string getVideo() const;
    int getHardDrive() const;
    double getWeight() const;
    int getBatteryLife() const;
    int getPrice() const;
    int getQuantity() const;

    Computer &operator=(const Computer &other);
    //--------destructor--------
    ~Computer();
};

#endif
