#include "livestock.h"

Livestock::Livestock(Store* _store_ptr){
    store_ptr=_store_ptr;
    total_storage=0;
    used_storage=0;
    return;
}
bool Livestock::Build(){
    if(user_ptr->Get_level()>=4){
        if(user_ptr->Get_coin()>=20){
            if(store_ptr->Get_object(2)>=3){
                if(store_ptr->Get_object(1)>=1){
                    user_ptr->Set_coin(user_ptr->Get_coin()-20);
                    store_ptr->Delete(2,3);
                    store_ptr->Delete(2,1);
                    level++;
                    total_storage = 2;
                    user_ptr->Set_experience(user_ptr->Get_experience()+10);
                }
            }
            //qt
        }
        //qt
    }
    //qt
}void Livestock::Upgrade() {
    if(user_ptr->Get_level()>=5){
        if(user_ptr->Get_coin()>=15){
            if(store_ptr->Get_object(2)>=2){
                user_ptr->Set_coin(user_ptr->Get_coin()-15);
                store_ptr->Delete(2,2);
                level++;
                total_storage *= 2;
                user_ptr->Set_experience(user_ptr->Get_experience()+6);
            }
            //qt
        }
        //qt
    }
    //qt
}
bool Livestock::Feed() {
    if(store_ptr->Delete(3,2*used_storage)){
        user_ptr->Set_experience(user_ptr->Get_experience()+(3*used_storage));
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
    if(store_ptr->Add(5,used_storage)){
        user_ptr->Set_experience(user_ptr->Get_experience()+5);
        return true;
    }
    return false;
}
