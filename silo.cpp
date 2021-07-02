#include "silo.h"
#include "store.h"

Silo::Silo(User* _user, Store* _store)
{
    store = _store;
    user = _user;
}

void Silo::Upgrade(){
    if(
            store->Get_object(2) >= this->level*2
            &&user->Get_coin() >= pow(this->level*2, 2)*100
      ) // enough resources for upgrading
    {
        if(user->Get_level() <= this->level+1){ // user's level will be lower than store's level after upgarde store

        }
        else{ // no problem for upgrading
            store->Delete(2, this->level*2);
            user->Set_coin(user->Get_coin()-pow(this->level*2, 2)*100);
            // Qtimer

            // after Qtimer finished :
            this->level++;
            this->total_storage = this->total_storage*2;
            user->Set_experience(user->Get_experience()+this->level*2);
        }
    }
    else{ // not enough resources for upgrading

    }
}

void Silo::Add(int alaki, int number){
    if(this->total_storage - used_storage < number){ // not enough space

    }
    else{ // enough space
        used_storage+=number;
    }
}

void Silo::Delete(int alaki , int number){
    if(number>used_storage){ // not enogh wheat

    }
    else{ // enogh wheat
        used_storage-=number;
    }
}

int Silo::Get_wheat(){ return used_storage; }
