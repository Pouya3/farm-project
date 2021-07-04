#include "aviculture.h"

Aviculture::Aviculture(/*Silo* _silo_ptr,Store* _store_ptr*/){
   // store_ptr=_store_ptr;
   // silo_ptr=_silo_ptr;
    total_storage=2;
    used_storage=0;
    return;
}
bool Aviculture::Build(){
    if(user_ptr->Get_level()>=6){
        if(user_ptr->Get_coin()>=10){
            if(store_ptr->Get_object(2)>=2){
                user_ptr->Set_coin(user_ptr->Get_coin()-10);
                store_ptr->Delete(2,2);
                level++;
                total_storage = 2;
                user_ptr->Set_experience(user_ptr->Get_experience()+5);
            }
            //qt
        }
        //qt
    }
    //qt
}
void Aviculture::Upgrade() {
    if(user_ptr->Get_level()>=3){
        if(user_ptr->Get_coin()>=10){
            if(store_ptr->Get_object(2)>=1){
                user_ptr->Set_coin(user_ptr->Get_coin()-10);
                store_ptr->Delete(2,3);
                store_ptr->Delete(1,1);
                level++;
                total_storage *= 2;
                user_ptr->Set_experience(user_ptr->Get_experience()+5);
            }
            //qt
        }
        //qt
    }
    //qt
}
bool Aviculture::Feed() {
    if(silo_ptr->Delete(0, used_storage)){
        user_ptr->Set_experience(user_ptr->Get_experience()+(1*used_storage));
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
    if(store_ptr->Add(4,used_storage)){
        user_ptr->Set_experience(user_ptr->Get_experience()+2);
        return true;
    }
    return false;
}
