#ifndef STORE_H
#define STORE_H
#include "building.h"
#include "user.h"
#include <vector>
using namespace std;

class Aghol;
class Alfalfa_land;
class Aviculture;
class Livestock;
class Silo;
class Wheat_land;

class Store : public Building
{
    int shovel;
    int nail;
    int alfalfa;
    int egg;
    int milk;
    int wool;
    vector <pair<int, int>> milk_info;

public:
    User* user; // this -> user

    Aghol* aghol; // aghol -> this
    Alfalfa_land* alfalfa_land; // alfalfa_land -> this
    Aviculture* aviculture; // aviculture -> this
    Livestock* livestock; // livestock -> this
    Silo* silo; // silo -> this
    Wheat_land* wheat_land; // wheat_land -> this

    Store();
    int Upgrade();
    bool Add(int ,int );
    bool Delete(int ,int);
    int Get_object(int );
};

#endif // STORE_H
