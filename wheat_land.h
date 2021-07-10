#ifndef WHEAT_LAND_H
#define WHEAT_LAND_H
#include "land.h"
#include "store.h"
#include "silo.h"

class Wheat_land : public Land 
{

public:
    Silo* silo; // this -> silo
    Store* store; // this -> store

    Wheat_land();
    int Upgrade();
    int Cultivate(int);
    int Harvest();
};

#endif // WHEAT_LAND_H
