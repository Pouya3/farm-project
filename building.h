#ifndef BUILDING_H
#define BUILDING_H
#include "user.h"

class Building {
protected:
    int level;
    int total_storage;
    int used_storage;
    bool is_active;

public:
    Building();
    virtual void Upgrade() = 0;
    virtual void Add(int , int ) = 0;
    virtual void Delete(int ,int ) = 0;
};

#endif // BUILDING_H
