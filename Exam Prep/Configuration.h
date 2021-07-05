#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "Utils.h"
#include <vector>

class Configuration
{
private:
    std::vector<const Component *> components;

    Configuration() = default;
    Configuration(const Configuration &other) = delete;
    Configuration &operator=(const Configuration &other) = delete;

    void insert(const Component *component);

public:
    friend Configuration *createConfiguration();

    double price() const;
    std::size_t size() const;
    
    const Component &operator[](std::size_t index) const;
    friend std::ostream &operator<<(std::ostream &out, const Configuration &config);

    ~Configuration();
};
#endif