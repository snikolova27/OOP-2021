#include "Horo.h"
#include <cstring> 

Horo::Horo(const char* name, const char* region, const char* razmer)
{
    strcpy(m_name, name);
    strcpy(m_region, region);
    strcpy(m_razmer, razmer);
}
char* Horo::getName()
{
    return m_name;
}
char* Horo::getRegion()
{
    return m_region;
}
char* Horo::getRazmer()
{
    return m_razmer;
}