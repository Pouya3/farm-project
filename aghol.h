#ifndef AGHOL_H
#define AGHOL_H

#include "habitat.h"
#include "store.h"

class Aghol :public Habitat {

public:
    Store* store; // this -> store

    Aghol();
    bool Build();
    void Upgrade();
	bool Feed();
    //bool Collect();
	int Wool_shaving();
	bool Add(int type, int amount);//
    bool Delete(int type, int amount);//

};

#endif // AGHOL_H
