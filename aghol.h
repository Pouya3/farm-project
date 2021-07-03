#ifndef AGHOL_H
#define AGHOL_H

#include "habitat.h"
#include "store.h"

class Aghol :public Habitat {
    Store* store_ptr;
public:
    Aghol(Store* _store_ptr);
    void Upgrade();
	bool Feed();
	//bool Collect();
	int Wool_shaving();
};

#endif // AGHOL_H