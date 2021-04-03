#include "Time.h"

int main()
{
    Time t1, t2;
    t1.setHour(12);
    t1.setMinute(25);
    t2.setHour(10);
    t2.setMinute(34);
    Time t3;
    t3+=t1;
    Time t4 = t1 + 5;
    Time t5=t4;

    t3.print();
    t4.print();
    t5.print();
}