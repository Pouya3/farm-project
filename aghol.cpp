#include "aghol.h"

Aghol::Aghol(){
}
int Aghol::Build(){
    // return values :
    // 1 == already built
    // 2 == locked
    // 3 == not enough coins
    // 4 == not enough nails
    // 5 == not enough shovels
    // 6 == timer set for building
    if(building_status != 2){ // not built
        if(building_status == 1){ // unlocked
            if(user->Get_coin()>=50){ // enough coins
                if(store->Get_object(2)>=4){ // enough nails
                    if(store->Get_object(1)>=2){ // enough shovels
                        user->Set_coin(user->Get_coin()-50);
                        store->Delete(2,4);
                        store->Delete(2,2);

                        building_timer = 10;


                        return 6;
                    }
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
    // 1 == aghol is not built yet
    // 2 == you cannot upgrade until feeding timer finishes and wools get collected
    // 3 == limit for upgrade duo to user's level
    // 4 == not enough coins
    // 5 == not enough nails
    // 6 == not enough shovels
    // 7 == timer set for upgrading
    if(building_status == 2){ // built aghol
        if(feeding_status == 0 ){ // feeding status == 0
            if(user->Get_level()>=7){ // not limit for upgrade duo to user's level
                if(user->Get_coin()>=50){ // enough coins
                    if(store->Get_object(2)>=3){ // enuogh nails
                        if(store->Get_object(1)>=1){ // enough shovels
                            if(upgrade_timer==0){
                                user->Set_coin(user->Get_coin()-50);
                                store->Delete(2,3);
                                store->Delete(1,1);
                                /*level++;
                                total_storage *= 2;
                                user->Set_experience(user->Get_experience()+15);*/

                                upgrade_timer = 9;
                                return 8;
                            }
                            return 7;
                        }
                        return 6;
                    }
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
    // 1 == aghol is not built yet
    // 2 == empty aghol
    // 3 == already fed or product ready to collect
    // 4 == not enough alfalfa
    // 5 == timer set for products
    if(building_status != 2){
        return 1;
    }
    else{
        if(used_storage == 0){ // empty aghol
            return 2;
        }
        else{
            if(feeding_status == 0){ // not fed and no product to collect
                if(upgrade_timer==0){
                    if(store->Delete(3, used_storage)){ // enough alfalfa

                        user->Set_experience(user->Get_experience()+(7*used_storage));

                        feeding_status = 1;
                        feeding_timer = 10;
                        return 6;
                    }

                    return 5;
                }
                return 4;
            }
            return 3;
        }
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
    // 1 == aghol is not built yet
    // 2 == no product to collect
    // 3 == not enough coins
    // 4 == not enough storage in store
    // 5 == product collected successfully

    if(building_status != 2){
        return 1;
    }
    else{
        if(feeding_status != 2){ // no product to collect
             return 2;
        }
        else{
            if(user->Get_coin()>=used_storage){ // enough coins
                if(store->Get_total_storage()-store->Get_used_storage()>=used_storage){ // enough storage in store
                    store->Add(6,used_storage);

                    user->Set_coin(user->Get_coin() - used_storage);
                    user->Set_experience(user->Get_experience()+(9*used_storage));

                    return 5;
                }
                return 4;
            }
            return 3;
        }
    }
}
