#ifndef HABITAT_H
#define HABITAT_H
#include "building.h"
#include "store.h"

class Habitat: public Building {
protected:
    // building_status :
    // 0 == locked
    // 1 == unlocked but not built
    // 2 == built

    // feeding_status :
    // 0 == not fed and no product to collect
    // 1 == fed but no product to collect
    // 2 == product ready to collect

    int building_status;
    int feeding_status;
    int feeding_timer;
    int building_timer;

public:
    Store* store;

	Habitat();
    virtual int Feed() = 0;
    virtual int Collect() = 0;
    virtual int Build() = 0;
    bool Add(int type, int amount);
    bool Delete(int type, int amount);

    void Set_building_status(int);
    int Get_building_status();
    void Set_feeding_status(int);
    int Get_feeding_status();
    void Set_feeding_timer(int);
    int Get_feeding_timer();
    void Set_building_timer(int);
    int Get_building_timer();
    void Set_upgrade_timer(int);
    int Get_upgrade_timer();

};
#endif // HABITAT_H
