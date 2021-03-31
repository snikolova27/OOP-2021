#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int m_hour;
    int m_min;
    int m_TimeZone;

public:
    Time();
    Time(int hour, int minutes, int timeZone);
    void getRealTime();
};

#endif