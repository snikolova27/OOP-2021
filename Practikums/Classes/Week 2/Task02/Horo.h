#ifndef HORO_H
#define HORO_H

class Horo
{
    private:
    char* m_name;
    char* m_region;
    char m_razmer [10] = {};

    public:
    Horo(const char* name, const char* region, const char* razmer);
    char* getName();
    char* getRegion();
    char* getRazmer();

};

#endif