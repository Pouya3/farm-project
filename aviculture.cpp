#include "aviculture.h"

Aviculture::Aviculture(){
}
int Aviculture::Build(){
    // return values:
    // 1 == already built
    // 2 == locked
    // 3 == not enough coins
    // 4 == not enough nails
    // 5 == timer set for building
    if(building_status != 2){ // not built
        if(building_status == 1){ // unlocked
            if(user->Get_coin()>=10){ // enough coins
                if(store->Get_object(2)>=2){ // enough nails
                    user->Set_coin(user->Get_coin()-10);
                    store->Delete(2,2);

                    building_timer = 3;

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
int Aviculture::Upgrade() {
    // return values :
    // 1 == is not built yet
    // 2 == limit for building duo to user's level
    // 3 == not enough coins
    // 4 == not enough nails
    // 5 == is upgrading
    // 6 == timer set for upgrade

    if(building_status == 2){ // already built
        if(user->Get_level()>=3){ // no limit for building duo to user's level
            if(user->Get_coin()>=10){ // enough coins
                if(store->Get_object(2)>=1){ // enough nails
                    if(upgrade_timer==0){ // is upgrading
                        user->Set_coin(user->Get_coin()-10);
                        store->Delete(2,1);

                        upgrade_timer = 3;
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
int Aviculture::Feed() {
    // return values :
    // 1 == is not built yet
    // 2 == empty aviculture
    // 3 == already fed or eggs ready to collect
    // 4 == not enough wheat to feed
    // 5 == timer set for product

        if(building_status == 2){ // already built
            if(used_storage != 0){ // aviculture is empty
                if(feeding_status != 0){ // not fed and no egg to collect
                    if(upgrade_timer==0){
                        if(silo->Delete(0, used_storage)){ // enough wheat
                            user->Set_experience(user->Get_experience()+(1*used_storage));

                            feeding_status = 1;
                            feeding_timer = 2;
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
    // 4 == aviculture is not built yet
    if(building_status != 2){
        return 4;
    }
    else{
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
}
