#ifndef PACE_H
#define PACE_H

class Pace
{
private:
    double m_kmPerHour;
    int m_minutes;
    int m_seconds;

public:
    Pace();
    Pace(int mins, int seconds);
    Pace(double kmPerHour);

    double getSpeedInKmPerH();
    double getPace();
};


#endif