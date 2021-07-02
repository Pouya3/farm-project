#ifndef FARM_H
#define FARM_H
#include "wheat_land.h"
#include "alfalfa_land.h"
#include "store.h"
#include "silo.h"
#include "aviculture.h"
#include "aghol.h"
#include "livestock.h"

class Farm {
private:
    Wheat_land wheat_land;
    Alfalfa_land alfalfa_land;
    Store store;
    Silo silo;
    Aviculture aviculture;
    Aghol aghol;
    Livestock livestock;

public:
    Farm();
};

#endif // FARM_H
