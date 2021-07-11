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
class MainPage;

class User
{
    QString name;
    QString username;
    QString password;
    QString email;
    int level;
    int experience;
    int max_experience;
    Time time;
    long long int coin;

public:
    Aghol* aghol; // aghol -> user
    Alfalfa_land* alfalfa_land; // alfalfa_land -> this
    Aviculture* aviculture; // aviculture -> this
    Livestock* livestock; // livestock -> this
    Silo* silo; // silo -> this
    Store* store; // store -> this
    Wheat_land* wheat_land; // wheat_land -> this
    MainPage* mainPage;// mainPage-> this

    User();
    void Set_name(QString);//
    QString Get_name(); //
    void set_username(QString);//
    QString Get_username(); //
    void Set_password(QString);//
    QString Get_password();//
    void Set_email(QString);//
    QString Get_email();//
    void Set_level(int);
    int Get_level();
    void Set_experience(int);
    int Get_experience();
    void Set_max_experience(int);//
    int Get_max_experience(); //
    void Set_time(Time);
    Time Get_time();
    void Set_coin(long long int);
    long long int Get_coin();
    void Check_experience();
};

#endif // USER_H
