#ifndef TIME_H
#define TIME_H

class Time
{
    private:
    int m_hour;
    int m_minute;

    void copy(const Time& other);

    public:
    Time();
    Time(const int hour, const int minute);
    Time(const Time& other);

    void setHour(const int hour);
    int getHour() const;

    void setMinute(const int minute);
    int getMinute() const;

    Time& operator += (const Time& other);
    Time& operator = (const Time& other);
    Time operator + (const Time& other);
    Time operator + (const int hour);
    friend Time operator + (const int hours, Time& other);
    bool operator > (const Time& other);

    void print();
};
#endif