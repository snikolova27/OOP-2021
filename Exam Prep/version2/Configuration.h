#pragma once
#include <vector>
#include "Utils.h"

class Configuration
{
private:
    std::vector<const Component *> components;

    Configuration() = default;
    Configuration& operator = (const Configuration& other)  = delete;
    Configuration(const Configuration& other) = delete;

    void insert(Component* component);


public:
    double price() const;
    std::size_t size() const;

    const Component &operator[](std::size_t index) const;
    friend std::ostream &operator<<(std::ostream &out, const Configuration &config);

    friend Configuration* createConfiguration();

    ~Configuration();
};