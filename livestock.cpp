#include "livestock.h"

Livestock::Livestock(){
}
int Livestock::Build(){
    // return values :
    // 1 == is already built
    // 2 == locked
    // 3 == not enough coins
    // 4 == not enough nails
    // 5 == not enough shovels
    // 6 == timer set for building
    if (building_status != 2){ // not built
        if(building_status == 1){ // unlocked
            if(user->Get_coin()>=20){ // enough coins
                if(store->Get_object(2)>=3){ // enough nails
                    if(store->Get_object(1)>=1){ // enough shovels
                        user->Set_coin(user->Get_coin()-20);
                        store->Delete(2,3);
                        store->Delete(2,1);
                        /*level++;
                        total_storage = 2;
                        user->Set_experience(user->Get_experience()+10);*/

                        building_timer = 5;

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
int Livestock::Upgrade() {
    // return values :
    // 1 == livestock is not built yet
    // 2 == to upgrade you have to wait until feeding timer finishes and milks get collected
    // 3 == limit for upgrade dou to user's level
    // 4 == not enough coins
    // 5 == not enough nails
    // 6 == timer set for upgrade

    if(building_status == 2){ // already built
        if(feeding_status == 0){ // not fed and no product to collect
            if(user->Get_level()>=5){ // not limit for upgrade dou to user's level
                if(user->Get_coin()>=15){ // enough coins
                    if(store->Get_object(2)>=2){ // enough nails
                        if(upgrade_timer==0){
                            user->Set_coin(user->Get_coin()-15);
                            store->Delete(2,2);
                            /*level++;
                            total_storage *= 2;
                            user->Set_experience(user->Get_experience()+6);*/

                            upgrade_timer = 5;

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
int Livestock::Feed() {
    // return values :
    // 1 == empty livestock
    // 2 == already fed
    // 3 == product is ready. to feed cows first collect milk
    // 4 == not enough alfalfa
    // 5 == timer set for products
    // 6 == livestock is not built yet
    if(building_status != 2){
        return 6;
    }
    else{
        if(upgrade_timer!=0){
            return 7;
        }
        else if(used_storage == 0){ // empty livestock
            return 1;
        }
        else if(feeding_status == 1){ // already fed
            return 2;
        }
        else if(feeding_status == 2){ // product is ready
            return 3;
        }
        if(store->Delete(3,2*used_storage)){ // enough alfalfa
            user->Set_experience(user->Get_experience()+(3*used_storage));
            feeding_status = 1;
            feeding_timer = 3;

            return 5;
        }
        return 4;
    }
}

bool Livestock::Add(int type, int amount) {

    if(used_storage+amount<=total_storage){
        used_storage+=amount;
        return true;
    }
    return false;
}
bool Livestock::Delete(int type, int amount) {

    if(used_storage-amount>=0){
        used_storage-=amount;
        return true;
    }
    return false;
}

int Livestock::Collect() {
    // return values :
    // 1 == not product to collect
    // 2 == not enough space in store
    // 3 == collected successfully
    // 4 == livstock is not built yet
    if(building_status != 2){
        return 4;
    }
    else{
        if(feeding_status != 2){ // product is not ready yet
            return 1;
        }
        else{
            if(store->Add(5,used_storage)){ // enough space in store
                user->Set_experience(user->Get_experience()+5);
                feeding_status = 0;

                return 3;
            }
            return 2;
        }
    }
}
