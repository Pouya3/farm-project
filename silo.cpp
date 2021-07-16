#include "silo.h"
#include "store.h"
#include <math.h>
#include <thread>

Silo::Silo() : wheat_land(NULL) , aviculture(NULL)
{

}

int Silo::Upgrade(){
    // return values :
    // 1 == not enough nails
    // 2 == not enough shovels
    // 3 == not enough coins
    // 4 == limit for upgrading duo to user's level
    // 5 == timer set for upgrade (successful upgrade)

    if(store->Get_object(2) < this->level*2){ // not enough nails
        return 1;
    }
    else if (store->Get_object(1) < level - 2){
        return 2;
    }
    else if(user->Get_coin() < pow(this->level*2, 2)*100){ // not enough coins
        return 3;
    }
    else{ // enough resources for upgrading
        if(user->Get_level() <= this->level+1){ // user's level will be lower than store's level after upgarde store
            return 4;
        }
        else{ // no problem for upgrading
            store->Delete(2, this->level*2);
            if(level != 1){
                store->Delete(1, level - 2);
            }
            user->Set_coin(user->Get_coin()-pow(this->level*2, 2)*100);

            upgrade_timer = 4;


            return 5;
        }
    }
}

bool Silo::Add(int alaki, int number){
    if(this->total_storage - used_storage < number){ // not enough space
        return false;
    }
    else{ // enough space
        used_storage+=number;
        return true;
    }
}

bool Silo::Delete(int alaki , int number){
    if(number>used_storage){ // not enogh wheat
        return false;
    }
    else{ // enogh wheat
        used_storage-=number;
        return true;
    }
}

int Silo::Get_wheat(){ return used_storage; }
