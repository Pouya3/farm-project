#ifndef SILO_H
#define SILO_H
#include "building.h"
#include "user.h"
#include "store.h"

class Silo : public Building {
private:
    User* user;
    Store* store;

public:
    Silo(User* _user, Store* _store);
    void Upgrade();
    bool Add(int, int);
    bool Delete(int, int);
    int Get_wheat();
};

#endif // SILO_H
