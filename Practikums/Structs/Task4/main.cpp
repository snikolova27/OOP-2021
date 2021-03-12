#include <iostream>
#include "functions.h"

int main()
{
    int n;
    
    std::cout << "Enter the number of competitors: ";
    std::cin >>n;
    std::cin.ignore();

    Runner* competitors = new (std::nothrow) Runner [n];

    for(int i=0; i<n;i++)
    {
        std::cout << '\t' << "Competitor №" << i+1 << std::endl;
        competitors[i].getRunner();
        competitors[i].formatName();
    }

    double minSpeed = competitors[0].avgSpeed();
    int minIdx = 0;

    for(int i=1; i<12;i++)
    {
        if(competitors[i].avgSpeed() < minSpeed)
        {
            minSpeed = competitors[i].avgSpeed();
            minIdx = i;
        }
    }

    std::cout << "Runner with slowest average speed: " << competitors[minIdx].name << ", speed is " << minSpeed << std::endl;

    int runnerA, runnerB;
    std::cout << "Enter first runner's № for comparison of times: ";
    std::cin >> runnerA;
    std::cout << "Enter second runner's №: ";
    std::cin >> runnerB;

    std::cout << "Times runner №" << runnerA << "beat runner №" << runnerB <<" : " << competitors[runnerA-1].beatRunner(competitors[runnerB-1]) << std::endl;
    std::cout << "Times runner №" << runnerB << "beat runner №" << runnerA <<" : " << competitors[runnerB-1].beatRunner(competitors[runnerA-1]) << std::endl;

    delete[] competitors;

    return 0;
}