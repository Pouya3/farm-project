#ifndef LIVESTOCK_H
#define LIVESTOCK_H

#include "habitat.h"
#include "store.h"

class Livestock :public Habitat {
public:
    Store* store; // this -> store

    Livestock();
    int Build();
    int Upgrade();
    int Feed();
    int Collect();
    bool Add(int type, int amount);//
    bool Delete(int type, int amount);//


};

#endif // LIVESTOCK_H
