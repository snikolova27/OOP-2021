#include "Time.h"
#include <iostream>

//New York (UTC -5), London (UTC +0), Sofia (UTC +2), Moscow (UTC +3)

const int NEY_YORK = -5;
const int LONDON = 0;
const int SOFIA = 2;
const int MOSCOW = 3;

Time::Time()
{
    m_hour = 0;
    m_min = 0;
    m_TimeZone = 0;
}
Time::Time(int hour, int minutes, int timeZone)
{
    m_hour = hour;
    m_min = minutes;
    m_TimeZone = timeZone;
}
void Time::getRealTime()
{
    switch (m_TimeZone)
    {
    case 0:
        std::cout << "In London Time:" << m_hour << ": " << m_min << std::endl;
        std::cout << "In Sofia Time:" << m_hour + 2 << ": " << m_min << std::endl;
        std::cout << "In Moscow Time: " << m_hour + 3 << ": " << m_min << std::endl;
        std::cout << "In New York Time: " << m_hour - 5 << ": " << m_min << std::endl;
        break;
    case 2:
        std::cout << "In London Time:" << m_hour - 2 << ": " << m_min << std::endl;
        std::cout << "In Sofia Time:" << m_hour << ": " << m_min << std::endl;
        std::cout << "In Moscow Time: " << m_hour + 1 << ": " << m_min << std::endl;
        std::cout << "In New York Time: " << m_hour - 3 << ": " << m_min << std::endl;
        break;
    case 3:
        std::cout << "In London Time:" << m_hour - 3 << ": " << m_min << std::endl;
        std::cout << "In Sofia Time:" << m_hour - 1 << ": " << m_min << std::endl;
        std::cout << "In Moscow Time: " << m_hour << ": " << m_min << std::endl;
        std::cout << "In New York Time: " << m_hour - 2 << ": " << m_min << std::endl;
        break;
    case (-5):
        std::cout << "In London Time:" << m_hour + 5 << ": " << m_min << std::endl;
        std::cout << "In Sofia Time:" << m_hour + 7 << ": " << m_min << std::endl;
        std::cout << "In Moscow Time: " << m_hour + 8 << ": " << m_min << std::endl;
        std::cout << "In New York Time: " << m_hour << ": " << m_min << std::endl;
        break;

    default:
        break;
    }
}
