#ifndef HABITAT_H
#define HABITAT_H
#include "Building.h"
class Habitat {
protected:
	int status;
	int time;
	int level;//
public:
    Habitat();
	virtual void Feed();
	virtual void Collect();
	bool Is_full();
	bool Add(int type, int amount);//
	bool Delete(int type, int amount);//
	int Get_time();
	void Set_time(int _time);
};
#endif // HABITAT_H
