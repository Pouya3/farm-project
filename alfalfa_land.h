#ifndef ALFALFA_LAND_H
#define ALFALFA_LAND_H
#include "land.h"
#include "store.h"

// status: 0 zamin bikar(shokm nazade) ... 1 zamin darhale shokm ... 2 shokm be payan reside
// ... 3 zamin dar hale kesht mahsole asli ... 4 kesht zamin tamam shode va montazere jamavari
class Alfalfa_land :public Land
{
private:
    int plowable;

public:
    Store* store; // this -> store

    Alfalfa_land();
    void Upgrade();
    void Plow(int);
    void Cultivation(int);
    void Harvesting(int);
    void Making();
};

#endif // ALFALFA_LAND_H
