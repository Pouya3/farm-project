#include "livestock.h"

Livestock::Livestock(/*Store* _store_ptr*/){
    //store_ptr=_store_ptr;
    total_storage=0;
    used_storage=0;
    return;
}
bool Livestock::Build(){
    if(user->Get_level()>=4){
        if(user->Get_coin()>=20){
            if(store->Get_object(2)>=3){
                if(store->Get_object(1)>=1){
                    user->Set_coin(user->Get_coin()-20);
                    store->Delete(2,3);
                    store->Delete(2,1);
                    level++;
                    total_storage = 2;
                    user->Set_experience(user->Get_experience()+10);
                    return true;
                }
                return false;
            }
            return false;
            //qt
        }
        return false;
        //qt
    }
    return false;
    //qt
}
void Livestock::Upgrade() {
    if(user->Get_level()>=5){
        if(user->Get_coin()>=15){
            if(store->Get_object(2)>=2){
                user->Set_coin(user->Get_coin()-15);
                store->Delete(2,2);
                level++;
                total_storage *= 2;
                user->Set_experience(user->Get_experience()+6);
            }
            //qt
        }
        //qt
    }
    //qt
}
bool Livestock::Feed() {
    if(store->Delete(3,2*used_storage)){
        user->Set_experience(user->Get_experience()+(3*used_storage));
        return true;
    }
    return false;
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

bool Livestock::Collect() {
    if(store->Add(5,used_storage)){
        user->Set_experience(user->Get_experience()+5);
        return true;
    }
    return false;
}
