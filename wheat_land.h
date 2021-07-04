#ifndef WHEAT_LAND_H
#define WHEAT_LAND_H
#include "land.h"
#include "store.h"
#include "silo.h"

// status: 0 zamin bikar ... 1 zamin dar hale kesht ... 2 kesht zamin tamam shode va montazere jamavari

class Wheat_land : public Land 
{

public:
    Silo* silo; // this -> silo
    Store* store; // this -> store

    Wheat_land();
    void Upgrade();
    void Cultivation(int);
    void Harvesting(int);
};

#endif // WHEAT_LAND_H
