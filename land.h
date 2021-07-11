#pragma once
#ifndef LAND_H
#define LAND_H
#include "user.h"
#include "store.h"

class Land {
protected:
    // cultivation_status (for wheat_land) :
    // 0 == not cultivated
    // 1 == cultivated but not ripe
    // 2 == ripe

    // cultivation_status (for alfalfa_land) :
    // 0 == not cultivated
    // 1 == plowed but not cultivated
    // 2 == cultivated but not ripe
    // 3 == ripe

    int level;
    int total_area;
    int cultivated_area;
    int cultivation_status;
    int ripening_timer;

public:
    Land();

    virtual int Upgrade()=0;
    virtual int Cultivate(int)=0;
    virtual int Harvest()=0;

    void Set_level(int);
    int Get_level();
    int Get_total_area();
    int Get_cultivated_area();
    int Get_cultivation_status();
    void Set_ripe_timer(int);
    int Get_ripe_timer();

    User* user;
    Store* store;
};

#endif // LAND_H
