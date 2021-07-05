#include "aghol.h"
#include "alfalfa_land.h"
#include "aviculture.h"
#include "building.h"
#include "farm.h"
#include "habitat.h"
#include "land.h"
#include "livestock.h"
#include "silo.h"
#include "store.h"
#include "wheat_land.h"
#include "user.h"

User::User() : store(NULL) {
        store = new Store;
        store->parent_user = this;
        silo = new Silo;
        silo->parent_user = this;
        silo->store = this->store;
}

void User::Check_experience()
{
    if(experience==max_experience)
    {
        level++;
        max_experience=max_experience*2+10;
        //peygham bede be karbar ke level bala rafte va namayeshe emkanate jadid
    }
}

long long int User::Get_coin(){return coin;}
int User::Get_level(){return level;}
int User::Get_time(){return time;}
int User::Get_experience(){return experience;}
void User::Set_coin(long long int _coin){coin=_coin;}
void User::Set_experience(int _experience){experience=_experience;}
void User::Set_level(int _level){level=_level;}
void User::Set_time(int _time){time=_time;}

