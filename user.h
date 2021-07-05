#ifndef USER_H
#define USER_H
#include <QString>
//#include "farm.h"
class Aghol;
class Alfaalfa_land;
class Aviculture;
class Building;
class Farm;
class Habitat;
class Land;
class Livestock;
class Silo;
class Store;
class Wheat_land;

class User
{
    QString name;
    QString username;
    QString password;
    QString email;
    int level;
    int experience;
    int max_experience;
    int time;
    long long int coin;
    //Farm farm;

public:
    User();
    Aghol* aghol;
    Alfaalfa_land* alfaalfa_land;
    Aviculture* aviculture;
    Building* building;
    Farm* farm;
    Habitat* habitat;
    Land* land;
    Livestock* livestock;
    Silo* silo;
    Store* store;
    User* user;
    Wheat_land* wheat_land;

    int Get_level();
    int Get_experience();
    long long int Get_coin();
    int Get_time();
    void Set_level(int);
    void Set_experience(int);
    void Set_coin(long long int);
    void Set_time(int);
    void Check_experience();
};

#endif // USER_H
