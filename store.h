#ifndef STORE_H
#define STORE_H
#include "building.h"
#include "user.h"
#include <vector>
using namespace std;

class Store : public Building
{
    int shovel;
    int nail;
    int alfalfa;
    int egg;
    int milk;
    int wool;
    User* user;
    vector <pair<int, int>> milk_info;

public:
    Store(User*);
    void Upgrade();
    bool Add(int ,int );
    bool Delete(int ,int);
    int Get_object(int );
};

#endif // STORE_H
