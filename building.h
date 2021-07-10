#ifndef BUILDING_H
#define BUILDING_H
#include "user.h"

class Building {
protected:
    int level;
    int total_storage;
    int used_storage;
    int upgrade_timer;

public:
    User* user; // this -> user

    Building();
    virtual int Upgrade() = 0;
    virtual bool Add(int , int ) = 0;
    virtual bool Delete(int ,int ) = 0;
    void Set_level(int);
    int Get_level();
    void Set_total_storage(int);
    int Get_total_storage();
    void Set_used_storage(int);
    int Get_used_storage();
    void Set_upgrade_timer(int);
    int Get_upgrade_timer();
};

#endif // BUILDING_H
