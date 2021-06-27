#ifndef LIVESTOCK_H
#define LIVESTOCK_H

#include "habitat.h"

class Livestock :public Habitat {
public:
	void Upgrade();
	void Feed();
	void Collect();
};

#endif // LIVESTOCK_H
