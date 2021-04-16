#include "MyString.h"
#include "Vehicle.h"
#include "Garage.h"
#include "VehicleAllocator.h"
#include <iostream>
#include <cstring>
const int MAX_LICENSE_PLATE = 100;
const int MAX_DESCRIPTION = 150;

int main()
{
  size_t cnt;
  std::cout << "Enter the  capacity (max amount of parking spaces) of your garage" << std::endl;
  std::cin >> cnt;
  std::cin.ignore();

  if (cnt)
  {
    Garage garage(cnt);
    VehicleAllocator vehicles;

    std::cout << "Please create " << cnt << "or less vehicles" << std::endl;
    for (int i = 0; i < cnt; i++)
    {
      char licensePlate[MAX_LICENSE_PLATE];
      char desc[MAX_DESCRIPTION];
      size_t space;
      std::cout << "Vehicle#" << i + 1 << std::endl;
      std::cout << "Enter license plate: ";
      std::cin.getline(licensePlate, MAX_LICENSE_PLATE);
      std::cout << "Enter desciption: ";
      std::cin.getline(desc, MAX_DESCRIPTION);
      std::cout << "Enter needed parking space: ";
      std::cin >> space;
      std::cin.ignore();

      vehicles.createVehicle(licensePlate, desc, space);
    }
    char answer;
    std::cout << "Do you want to put one of the vehicles in the garage? (y/n) " << std::endl;
    std::cin >> answer;
    std::cin.ignore();
    if (answer == 'y')
    {
      int cntGarage;
      std::cout << "How many vehicles do you want to put in the garage?" << std::endl;
      std::cin >> cntGarage;
      std::cin.ignore();

      for (int i = 0; i < cntGarage; i++)
      {
        int vnum;
        std::cout << "Which vehichle do you want to put in the garage? Enter its number: ";
        std::cin >> vnum;
        std::cin.ignore();
        garage.insert(vehicles.at(vnum - 1));
      }
      if (!garage.empty())
      {
        std::cout << "Current state of the garage" << std::endl;
        garage.print();
        char answer2;
        std::cout << "Do you want to take any vehicles out of the garage? (y/n) ";
        std::cin >> answer2;
        std::cin.ignore();
        if (answer2 == 'y')
        {
          int cntGarageOut;
          std::cout << "How many vehicles do you want to take out of the garage?" << std::endl;
          std::cin >> cntGarageOut;
          std::cin.ignore();
          for (int i = 0; i < cntGarageOut; i++)
          {
            char licensePlateOut[MAX_LICENSE_PLATE];
            std::cout << "Which vehichle do you want to take out of the garage? Enter its license plate: ";
            std::cin.getline(licensePlateOut, MAX_LICENSE_PLATE);
            std::cin.ignore();
            garage.erase(vehicles.findVehicle(licensePlateOut)->registration());
          }
          std::cout << "Current state of the garage" << std::endl;
          garage.print();
        }
        char answer3;
        std::cout << "Do you want to delete any vehicles? THey will be automatically taken out of the garage.(y/n) ";
        std::cin >> answer3;
        std::cin.ignore();
        if (answer3 == 'y')
        {
          int deletenum;
          std::cout << "How many vehicles do you want to delete? ";
          std::cin >> deletenum;
          std::cin.ignore();
          for (int i = 0; i < deletenum; i++)
          {
            char licensePlateDelete[MAX_LICENSE_PLATE];
            std::cout << "Which vehichle do you want delete? Enter its license plate: ";
            std::cin.getline(licensePlateDelete, MAX_LICENSE_PLATE);
            std::cin.ignore();
            vehicles.deleteVehicle(licensePlateDelete);
            garage.erase(vehicles.findVehicle(licensePlateDelete)->registration());
          }
          std::cout << "Current state of the garage" << std::endl;
          garage.print();
        }
      }
    }
    else
    {
      vehicles.deleteAll();
      garage.clear();
    }
  }
  else
  {
    std::cout << "Capacity should be > 0";
  }

  return 0;
}
