#ifndef WHEAT_LAND_H
#define WHEAT_LAND_H
#include "land.h"
#include "user.h"
#include "store.h"

class Wheat_land : public Land {

private:
    User* user;
    Store* store;

public:
    Wheat_land(User* _user, Store* _store);
    void Upgrade();
};

#endif // WHEAT_LAND_H
