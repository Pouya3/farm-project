#ifndef HABITAT_H
#define HABITAT_H
#include "building.h"
#include "store.h"

class Habitat: public Building {
protected:
	int status;
	int time;
	//bool _feed;//
public:
    Store* store;
	Habitat();
    virtual bool Feed() = 0;
    virtual bool Collect() = 0;
	bool Is_full();
    //bool Add(int type, int amount);//
    //bool Delete(int type, int amount);//
	int Get_time();
	void Set_time(int _time);
};
#endif // HABITAT_H
