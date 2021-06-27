#ifndef AGHOL_H
#define AGHOL_H

#include "Habitat.h"

class Aghol :public Habitat {
public:
	Aghol();
	void Upgrade();
	void Feed();
	void Collect();
	void Wool_shaving();
};

#endif // AGHOL_H
