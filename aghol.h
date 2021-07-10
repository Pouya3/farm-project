#ifndef AGHOL_H
#define AGHOL_H

#include "habitat.h"
#include "store.h"

class Aghol :public Habitat {

public:
    Store* store; // this -> store

    Aghol();
    int Build();
    int Upgrade();
    int Feed();
    int Collect();
	bool Add(int type, int amount);//
    bool Delete(int type, int amount);//

};

#endif // AGHOL_H
