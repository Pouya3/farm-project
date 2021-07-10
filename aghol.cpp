#include "aghol.h"

Aghol::Aghol(){
}
int Aghol::Build(){
    // return values :
    // 1 == locked
    // 2 == not enough coins
    // 3 == not enough nails
    // 4 == not enough shovels
    // 5 timer set for building
    if(building_status == 1){ // unlocked
        if(user->Get_coin()>=50){ // enough coins
            if(store->Get_object(2)>=4){ // enough nails
                if(store->Get_object(1)>=2){ // enough shovels
                    user->Set_coin(user->Get_coin()-50);
                    store->Delete(2,4);
                    store->Delete(2,2);
                    level++;
                    total_storage = 2;
                    user->Set_experience(user->Get_experience()+20);

                    return 5;
                }
                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}
int Aghol::Upgrade() {
    // return values :
    // 1 == limit for upgrade duo to user;s level
    // 2 not enough coins
    // 3 == not enough nails
    // 4 == not enough shovels
    // 5 == timer set for upgrading
    if(user->Get_level()>=7){ // not limit for upgrade duo to user's level
        if(user->Get_coin()>=50){ // enough coins
            if(store->Get_object(2)>=3){ // enuogh nails
                if(store->Get_object(1)>=1){ // enough shovels
                    user->Set_coin(user->Get_coin()-50);
                    store->Delete(2,3);
                    store->Delete(1,1);
                    level++;
                    total_storage *= 2;
                    user->Set_experience(user->Get_experience()+15);

                    // timer;

                    return 5;
                }
                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}
int Aghol::Feed() {
    // return values :
    // 1 == empty aghol
    // 2 == not enough alfalfa
    // 3 == timer set for products
    if(used_storage == 0){ // empty aghol
        return 1;
    }
    else{
        if(store->Delete(3, used_storage)){ // enough alfalfa
            user->Set_experience(user->Get_experience()+(7*used_storage));

            // timer

            return 3;
        }
        return 2;
    }
}
bool Aghol::Add(int type, int amount) {

    if(used_storage+amount<=total_storage){
        used_storage+=amount;
        return true;
    }
    return false;
}
bool Aghol::Delete(int type, int amount) {

    if(used_storage-amount>=0){
        used_storage-=amount;
        return true;
    }
    return false;
}
int Aghol::Collect() {
    // return values :
    // 1 == no product to collect
    // 2 == not enough coins
    // 3 == not enough storage in store

    if(feeding_status != 2){ // no product to collect
         return 1;
    }
    else{
        if(user->Get_coin()>=used_storage){ // enough coins
            if(store->Get_total_storage()-store->Get_used_storage()>=used_storage){ // enough storage in store
                store->Add(6,used_storage);

                user->Set_coin(user->Get_coin() - used_storage);
                user->Set_experience(user->Get_experience()+(9*used_storage));

                return true;
            }
            return 3;
        }
        return 2;
    }
}
