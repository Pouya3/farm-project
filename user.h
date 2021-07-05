#ifndef USER_H
#define USER_H
#include <QString>
class Aghol;
class Alfalfa_land;
class Aviculture;
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
    Aghol* aghol; // aghol -> user
    Alfalfa_land* alfalfa_land; // alfalfa_land -> this
    Aviculture* aviculture; // aviculture -> this
    Livestock* livestock; // livestock -> this
    Silo* silo; // silo -> this
    Store* store; // store -> this
    Wheat_land* wheat_land; // wheat_land -> this

    User();
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
