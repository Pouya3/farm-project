#include "silo.h"
#include "store.h"

Silo::Silo(User* _user, Store* _store)
{
    store = _store;
    user = _user;
}

void Silo::Upgrade(){
    if(store->Get_object(2) < this->level*2){ // not enough nails
        // QmessageBox for "not enough nails"
    }
    else if(user->Get_coin() < pow(this->level*2, 2)*100){ // not enough coins
        // QmessageBox for "not enough coins"
    }
    else{ // enough resources for upgrading
        if(user->Get_level() <= this->level+1){ // user's level will be lower than store's level after upgarde store
            // QmessageBox for "level limitation"
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
}

bool Silo::Add(int alaki, int number){
    if(this->total_storage - used_storage < number){ // not enough space
        // QmessageBox for "not enough sapce"
        return false;
    }
    else{ // enough space
        used_storage+=number;
        return true;
    }
}

bool Silo::Delete(int alaki , int number){
    if(number>used_storage){ // not enogh wheat
        // QmessageBox for "not enough wheat"
        return false;
    }
    else{ // enogh wheat
        used_storage-=number;
        return true;
    }
}

int Silo::Get_wheat(){ return used_storage; }
