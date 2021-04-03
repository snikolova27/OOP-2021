#include "Time.h"
#include <iostream>

Time::Time()
{
    m_hour = 0;
    m_minute = 0;
}

Time::Time(const int hour, const int minute)
{
    if (hour >= 0 && hour <= 23)
    {
        m_hour = hour;
    }
    else
    {
        std::cout << "Hours should be between 0 and 23" << std::endl;
        m_hour = 0;
    }

    if (minute >= 0 && minute <= 59)
    {
        m_minute = minute;
    }
    else
    {
        std::cout << "Minutes should be between 0 and 59" << std::endl;
        m_minute = 0;
    }
}

Time::Time(const Time &other)
{
    copy(other);
}

void Time::setHour(const int hour)
{
    if (hour < 24)
    {
        m_hour = hour;
    }
    else
    {
        m_hour = 0;
        std::cout << "Hours should be between 0 and 23" << std::endl;
    }
}

int Time::getHour() const
{
    return m_hour;
}

void Time::setMinute(const int minute)
{
    if (minute < 60)
    {
        m_minute = minute;
    }
    else
    {
    m_minute = 0;
    std::cout << "Minutes should be between 0 and 59" << std::endl;
    }
}
int Time::getMinute() const
{
    return m_minute;
}

void Time::copy(const Time &other)
{
    setHour(other.m_hour);
    setMinute(other.m_minute);
}

Time &Time::operator+=(const Time &other)
{
    int thisMin = 60 * this->m_hour + this->m_minute;
    int otherMin = 60 * other.m_hour + other.m_minute;

    thisMin += otherMin;
    if (thisMin > 24 * 60)
    {

        thisMin -= 24 * 60;
    }

    this->m_hour = thisMin / 60;
    this->m_minute = thisMin % 60;

    return *this;
}

Time &Time ::operator=(const Time &other)
{
    if (this != &other)
    {
        copy(other);
    }
    return *this;
}

Time Time::operator+(const Time &other)
{

    *this += other;
    return *this;
}

Time Time::operator+(const int hour)
{
    Time other(hour, 0);

    return *this + other;
}

Time operator+(const int hour, Time &other)
{
    return other + hour;
}
bool Time::operator>(const Time &other)
{
    int thisMin = m_minute + 60 * m_hour;
    int otherMin = other.m_minute + 60 * other.m_hour;

    return thisMin > otherMin;
}

void Time::print()
{
    std::cout << ((m_hour < 10) ? "0" : "") << m_hour << ":"
              << ((m_minute < 10) ? "0" : "") << m_minute << std::endl;
}
