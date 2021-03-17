#include <iostream>
#include "functions.h"

char toUpper(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        ch -= ('a' - 'A');
    }
    return ch;
}

void Runner::getRunner()
{
    std::cout << "Enter the names of the runner: ";
    std::cin.getline(name, 100);

    std::cout << '\t' << "Enter the times of the 12 races in seconds " << std::endl;
    for (int i = 0; i < 12; i++)
    {
        std::cout << "Race №" << i + 1 << ": ";
        std::cin >> times[i];
        if(times[i] < 0)
        {
            std::cout << "Number of seconds should be positive";
            return;
        }
    }
    std::cin.ignore();
}

void Runner::formatName()
{
    name[0] = toUpper(name[0]);
    int formattedNames = 1;
    int idx = 1;
    while (formattedNames < 2)
    {
        if (name[idx] == ' ')
        {
            name[idx + 1] = toUpper(name[idx + 1]);
            formattedNames++;
            idx++;
        }
        idx++;
    }
}

double Runner::avgSpeed()
{
    double sumTimes = 0;
    for (int i = 0; i < 12; i++)
    {
        sumTimes += times[i];
    }
    sumTimes /= 3600;

    double distance = 42 * 12;

    return distance / sumTimes;
}

int Runner::beatRunner(Runner B)
{
    int cnt = 0;
    for (int i = 0; i < 12; i++)
    {
        if (times[i] > B.times[i])
        {
            cnt++;
        }
    }
    return cnt;
}

