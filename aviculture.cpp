#include "aviculture.h"

Aviculture::Aviculture(){
}
int Aviculture::Build(){
    // return values:
    // 1 == locked
    // 2 == not enough coins
    // 3 == not enough nails
    // 4 == timer set for building
    if(building_status == 1){ // unlocked
        if(user->Get_coin()>=10){ // enough coins
            if(store->Get_object(2)>=2){ // enough nails
                 // timer

                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}
int Aviculture::Upgrade() {
    // return values :
    // 1 == limit for building duo to user's level
    // 2 == not enough coins
    // 3 == not enough nails
    // 4 == timer set for upgrade

    if(user->Get_level()>=3){ // no limit for building duo to user's level
        if(user->Get_coin()>=10){ // enough coins
            if(store->Get_object(2)>=1){ // enough nails
                // timer

                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}
int Aviculture::Feed() {
    // return values :
    // 1 == empty aviculture
    // 2 == not enough wheat to feed
    // 3 == timer set for product
    if(used_storage == 0){ // aviculture is empty
        return 1;
    }
    else{
        if(silo->Delete(0, used_storage)){ // enough wheat
            user->Set_experience(user->Get_experience()+(1*used_storage));
            // timer
            return 3;
        }
    return 2;
    }
}

bool Aviculture::Add(int type, int amount) {

    if(used_storage+amount<=total_storage){
        used_storage+=amount;
        return true;
    }
    return false;
}
bool Aviculture::Delete(int type, int amount) {

    if(used_storage-amount>=0){
        used_storage-=amount;
        return true;
    }
    return false;
}

int Aviculture::Collect() {
    // return values :
    // 1 == no product to collect
    // 2 == not enough storage in store
    // 3 == collected successfully
    if(feeding_status != 2){ // no product to collect
        return 1;
    }
    else{
        if(store->Add(4,used_storage)){ // enough storage in store
            user->Set_experience(user->Get_experience()+2);
            return 3;
        }
        return 2;
    }
}
