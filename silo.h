#ifndef SILO_H
#define SILO_H
#include "building.h"
#include "store.h"

class Wheat_land;
class Aviculture;

class Silo : public Building {
public:
    Store* store; // this -> store;

    Wheat_land* wheat_land; // wheat_land -> this
    Aviculture* aviculture; // aviculture -> this

    Silo();
    void Upgrade();
    bool Add(int, int);
    bool Delete(int, int);
    int Get_wheat();
};

#endif // SILO_H
