#include "WashingMachine.h"
#include "utils.h"
#include <iostream>

int main()
{
    int cntOfWashuingMachines;
    
    std::cin >> cntOfWashuingMachines;
    std::cin.ignore();

    WashingMachine* machines = new (std::nothrow) WashingMachine [cntOfWashuingMachines];
    if(!machines)
    {
        std::cout << "memory allocation problem" << std::endl;
        return -1;
    }
    machines[0].inputWashingMachine();
    WashingMachine best = machines [0];

    for(int i=1; i<cntOfWashuingMachines;i++)
    {
        machines[i].inputWashingMachine();
        if(machines[i] > best)
        {
            best = machines[i];
        }
    }

    best.print();

    if(machines)
    {
    delete[] machines;
    }


}