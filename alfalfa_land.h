#ifndef ALFALFA_LAND_H
#define ALFALFA_LAND_H
#include "land.h"
#include "store.h"

class Alfalfa_land :public Land
{
private:
    // building_status :
    // 0 == locked
    // 1 == locked but not built
    // 2 == built

    int plowed_area;
    int building_status;
    int building_timer;
    int plowing_timer;

public:
    Store* store; // this -> store

    Alfalfa_land();
    int Upgrade();
    int Cultivate(int);
    int Harvest();
    int Plow();
    int Build();

    void Set_plowed_area(int);
    int Get_plowed_area();
    void Set_building_status(int);
    int Get_building_status();
    void Set_building_timer(int);
    int Get_building_timer();
    void Set_plowing_timer(int);
    int Get_plowing_timer();
};

#endif // ALFALFA_LAND_H
