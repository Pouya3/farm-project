#ifndef WHEAT_LAND_H
#define WHEAT_LAND_H
#include "land.h"

// status: 0 zamin bikar ... 1 zamin dar hale kesht ... 2 kesht zamin tamam shode va montazere jamavari

class Wheat_land : public Land 
{
public:
    Wheat_land(User* _user, Store* _store);
    void Upgrade();
};

#endif // WHEAT_LAND_H
