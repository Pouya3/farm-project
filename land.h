#pragma once
#ifndef LAND_H
#define LAND_H
#include "user.h"
#include "store.h"

class Land {
protected:
    int time;
    int level;
    int space;
    int status;
    int cultivable; //tedad zamin haii ke chiz dar anha kashtim
    bool is_active;

public:
    Land();

    virtual void Upgrade()=0;
    virtual void Cultivation(int)=0;
    virtual void Harvesting(int)=0;
    int Get_time();
    void Set_time(int);
    void Set_level(int);
    int get_level();
    User* user;
    Store* store;
};

#endif // LAND_H
