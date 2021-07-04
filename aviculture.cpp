#include "aviculture.h"

Aviculture::Aviculture(/*Silo* _silo_ptr,Store* _store_ptr*/){
   // store_ptr=_store_ptr;
   // silo_ptr=_silo_ptr;
    total_storage=2;
    used_storage=0;
    return;
}
bool Aviculture::Build(){
    if(user->Get_level()>=6){
        if(user->Get_coin()>=10){
            if(store->Get_object(2)>=2){
                user->Set_coin(user->Get_coin()-10);
                store->Delete(2,2);
                level++;
                total_storage = 2;
                user->Set_experience(user->Get_experience()+5);

                return true;
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
void Aviculture::Upgrade() {
    if(user->Get_level()>=3){
        if(user->Get_coin()>=10){
            if(store->Get_object(2)>=1){
                user->Set_coin(user->Get_coin()-10);
                store->Delete(2,3);
                store->Delete(1,1);
                level++;
                total_storage *= 2;
                user->Set_experience(user->Get_experience()+5);
            }
            //qt
        }
        //qt
    }
    //qt
}
bool Aviculture::Feed() {
    if(silo->Delete(0, used_storage)){
        user->Set_experience(user->Get_experience()+(1*used_storage));
        return true;
    }
    return false;
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

bool Aviculture::Collect() {
    if(store->Add(4,used_storage)){
        user->Set_experience(user->Get_experience()+2);
        return true;
    }
    return false;
}
