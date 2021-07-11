#ifndef AVICULTURE_H
#define AVICULTURE_H

#include "habitat.h"
#include "silo.h"
#include "store.h"

class Aviculture :public Habitat {
public:
    Silo* silo; // this -> silo
    Store* store; // this -> store

    Aviculture();
    int Build();
    int Upgrade();
    int Feed();
    int Collect();
    bool Add(int type, int amount);
    bool Delete(int type, int amount);


};

#endif // AVICULTURE_H
