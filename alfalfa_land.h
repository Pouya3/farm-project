#ifndef ALFALFA_LAND_H
#define ALFALFA_LAND_H
#include "land.h"

// status: 0 zamin bikar(shokm nazade) ... 1 zamin darhale shokm ... 2 shokm be payan reside
// ... 3 zamin dar hale kesht mahsole asli ... 4 kesht zamin tamam shode va montazere jamavari
class Alfalfa_land :public Land
{
public:
    Alfalfa_land(User* _user, Store* _store);
    void Upgrade();
    void Plow(int);
};

#endif // ALFALFA_LAND_H
