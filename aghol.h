#ifndef AGHOL_H
#define AGHOL_H

#include "habitat.h"
#include "store.h"

class Aghol :public Habitat {

public:
    Store* store; // this -> store

    Aghol();
<<<<<<< HEAD
    int Build();
    int Upgrade();
    int Feed();
    int Collect();
	bool Add(int type, int amount);//
=======
    bool Build();
    void Upgrade();
    bool Feed();
    bool Collect();
    int Wool_shaving();
    bool Add(int type, int amount);//
>>>>>>> 41fcbf6bddd172197c98eaefbab9cdea23e7bb0a
    bool Delete(int type, int amount);//

};

#endif // AGHOL_H
