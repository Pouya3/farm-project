#ifndef AVICULTURE_H
#define AVICULTURE_H

#include "habitat.h"
#include "silo.h"
#include "store.h"

class Aviculture :public Habitat {
    Silo* silo_ptr;
    Store* store_ptr;
public:
    Aviculture(Silo* _silo_ptr,Store* _store_ptr);
    void Upgrade();
    bool Feed();
    bool Collect();
    bool Add(int type, int amount);//
    bool Delete(int type, int amount);//
};

#endif // AVICULTURE_H
