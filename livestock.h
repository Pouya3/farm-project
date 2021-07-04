#ifndef LIVESTOCK_H
#define LIVESTOCK_H

#include "habitat.h"
//#include "store.h"

class Livestock :public Habitat {
    //Store* store_ptr;
public:
    //Store* store_ptr;
    Livestock(Store* _store_ptr);
    bool Build();
    void Upgrade();
    bool Feed();
    bool Collect();
    bool Add(int type, int amount);//
    bool Delete(int type, int amount);//
};

#endif // LIVESTOCK_H
