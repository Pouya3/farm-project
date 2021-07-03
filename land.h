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
    bool is_active;
    User* user;
    Store* store;

public:
    Land();

    virtual void Upgrade()=0;
    void Cultivation();
    int Get_time();
    void Set_time(int);
};

#endif // LAND_H