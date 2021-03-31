#include "Pace.h"

Pace::Pace()
{
    m_kmPerHour = 0;
    m_minutes = 0;
    m_seconds = 0;
};

Pace::Pace(int mins, int seconds)
{
    m_minutes = mins;
    m_seconds = seconds;
}
Pace::Pace(double kmPerH)
{
    m_kmPerHour = kmPerH;
};

double Pace::getPace()
{
    if (m_minutes == 0 && m_seconds == 0 && m_kmPerHour != 0)
    {
        int secondsPerKm = 3600 / m_kmPerHour;
        m_minutes = secondsPerKm / 60;
        m_seconds = secondsPerKm % 60;
    }
    return 100*m_minutes + m_seconds;
}
double Pace::getSpeedInKmPerH()
{
    if((m_minutes!=0 || m_seconds!=0) && (m_kmPerHour==0))
    {
        int secondsPerKm = 60* m_minutes + m_seconds;
        m_kmPerHour = 3600/secondsPerKm;
    }
    return m_kmPerHour;
}