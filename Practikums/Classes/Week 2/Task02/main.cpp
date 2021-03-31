#include "Horo.h"
#include "Utils.h"
#include <iostream>

int main()
{
    char *name = inputName();
    char *region = inputRegion();
    char *razmer = inputRazmer();
    Horo horo(name, region, razmer);

    clearDynamic(name);
    clearDynamic(region);
    clearDynamic(razmer);

    return 0;
}