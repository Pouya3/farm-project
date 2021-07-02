#ifndef ALFALFA_LAND_H
#define ALFALFA_LAND_H
#include "land.h"
#include "user.h"
#include "store.h"

class Alfalfa_land :public Land{
    
private:
    User* user;
    Store* store;

public:
    Alfalfa_land(User* _user, Store* _store);
    void Upgrade();

};

#endif // ALFALFA_LAND_H
