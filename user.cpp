#include "user.h"
#include "aghol.h"
#include "alfalfa_land.h"
#include "aviculture.h"
#include "livestock.h"
#include "silo.h"
#include "store.h"
#include "wheat_land.h"

#include "levelup12.h"
#include "levelup23.h"
#include "levelup34.h"
#include "levelup45.h"
#include "levelup56.h"
#include "levelup67.h"
#include "levelupkoli.h"


User::User() : aghol(NULL), alfalfa_land(NULL), aviculture(NULL), livestock(NULL), silo(NULL), store(NULL), wheat_land(NULL) {

    store = new Store;
    store->user = this;

    silo = new Silo;
    silo->user = this;
    silo->store = this->store;

    aghol = new Aghol;
    aghol->user = this;
    aghol->store = this->store;

    alfalfa_land = new Alfalfa_land;
    alfalfa_land->user = this;
    alfalfa_land->store = this->store;

    livestock = new Livestock;
    livestock->user = this;
    livestock->store = this->store;

    wheat_land = new Wheat_land;
    wheat_land->user = this;
    wheat_land->store = this->store;
    wheat_land->silo = this->silo;
    

    aviculture = new Aviculture;
    aviculture->user = this;
    aviculture->store = this->store;
    aviculture->silo = this->silo;
}

void User::Set_name(QString _name) { name = _name; }
QString User::Get_name() { return name; }
void User::set_username(QString _username) { username = _username; }
QString User::Get_username() { return username; }
void User::Set_password(QString _password) { password = _password; }
QString User::Get_password() { return password; }
void User::Set_email(QString _email) { email = _email; }
QString User::Get_email() { return email; }
void User::Set_level(int _level){level=_level;}
int User::Get_level(){return level;}
void User::Set_coin(long long int _coin){coin=_coin;}
int User::Get_experience(){return experience;}
void User::Set_max_experience(int _max_experience) { max_experience = _max_experience; }
int User::Get_max_experience() { return max_experience; }
void User::Set_time(int _time){time=_time;}
int User::Get_time(){return time;}
long long int User::Get_coin(){return coin;}
void User::Set_experience(int _experience){
    experience = _experience;

    if(experience >= max_experience){
        level++;

        switch (level) {
        case 2:
            LevelUp12 * levelUp12;
            levelUp12 = new LevelUp12;
            levelUp12->show();

            aviculture->Set_building_status(1);

            break;

        case 3:
            LevelUp23 * levelUp23;
            levelUp23 = new LevelUp23;
            levelUp23->show();

            alfalfa_land->Set_building_status(1);

            break;

        case 4:
            LevelUp34 * levelUp34;
            levelUp34 = new LevelUp34;
            levelUp34->show();

            livestock->Set_building_status(1);

            break;

        case 5:
            LevelUp45 * levelUp45;
            levelUp45 = new LevelUp45;
            levelUp45->show();

            break;

        case 6:
            LevelUp56 * levelUp56;
            levelUp56 = new LevelUp56;
            levelUp56->show();

            aghol->Set_building_status(1);

            break;

        case 7:
            LevelUp67 * levelUp67;
            levelUp67 = new LevelUp67;
            levelUp67->show();

            break;

        default:
            LevelUpKoli* levelUpkoli;
            levelUpkoli = new LevelUpKoli;
            levelUpkoli->show();

            break;
        }

        max_experience = max_experience * 2 + 10;
    }
}








