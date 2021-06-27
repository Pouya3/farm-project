#ifndef AVICULTURE_H
#define AVICULTURE_H

#include "habitat.h"

class Aviculture :public Habitat {
public:
    Aviculture();
	void Upgrade();
	void Feed();
	void Collect();
};

#endif // AVICULTURE_H
