#ifndef AGHOL_H
#define AGHOL_H

#include "habitat.h"
#include "store.h"

class Aghol :public Habitat {

public:
    Store* store; // this -> store

    Aghol();
<<<<<<< HEAD
    bool Build();
    void Upgrade();
	bool Feed();
    bool Collect();
	int Wool_shaving();
=======
    int Build();
    int Upgrade();
    int Feed();
    int Collect();
>>>>>>> e8398d7db82411fb385f592bb28ff6b7cdd73f27
	bool Add(int type, int amount);//
    bool Delete(int type, int amount);//

};

#endif // AGHOL_H
