#ifndef HABITAT_H
#define HABITAT_H
#include "building.h"
class Habitat: public Building {
protected:
	int status;
	int time;
	//bool _feed;//
public:
    Habitat();
	virtual bool Feed();
	virtual bool Collect();
	bool Is_full();
	//bool Add(int type, int amount);//
	//bool Delete(int type, int amount);//
	int Get_time();
	void Set_time(int _time);
};
#endif // HABITAT_H
