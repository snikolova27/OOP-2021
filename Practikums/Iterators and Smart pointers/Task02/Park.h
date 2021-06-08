#ifndef PARK_H
#define PARK_H
#include <string>

class Park
{
private:
    std::string name;

public:
    Park(const std::string &name);

    std::string getName() const;

  };
#endif