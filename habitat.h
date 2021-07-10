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
    int upgrade_timer;

public:
    Store* store;

	Habitat();
    virtual int Feed() = 0;
    virtual int Collect() = 0;
    virtual int Build() = 0;
    bool Add(int type, int amount);
    bool Delete(int type, int amount);
};
#endif // HABITAT_H
