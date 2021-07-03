#include "aghol.h"

Aghol::Aghol(Store* _store_ptr){
    store_ptr=_store_ptr;
    total_storage=2;
    used_storage=0;
    return;
}
bool Aghol::Build(){
    if(user_ptr->Get_level()>=6){
        if(user_ptr->Get_coin()>=50){
            if(store_ptr->Get_object(2)>=4){
                if(store_ptr->Get_object(1)>=2){
                    user_ptr->Set_coin(user_ptr->Get_coin()-50);
                    store_ptr->Delete(2,4);
                    store_ptr->Delete(2,2);
                    level++;
                    total_storage = 2;
                    user_ptr->Set_experience(user_ptr->Get_experience()+20);
                }
            }
            //qt
        }
        //qt
    }
    //qt
}
void Aghol::Upgrade() {
    if(user_ptr->Get_level()>=7){
        if(user_ptr->Get_coin()>=50){
            if(store_ptr->Get_object(2)>=3){
                if(store_ptr->Get_object(1)>=1){
                    user_ptr->Set_coin(user_ptr->Get_coin()-50);
                    store_ptr->Delete(2,3);
                    store_ptr->Delete(1,1);
                    level++;
                    total_storage *= 2;
                    user_ptr->Set_experience(user_ptr->Get_experience()+15);
                }
                //qt
            }
            //qt
        }
        //qt
    }
    //qt
}
bool Aghol::Feed() {
    if(store_ptr->Delete(3, used_storage)){
        user_ptr->Set_experience(user_ptr->Get_experience()+(7*used_storage));
        return true;
    }
    return false;
}
int Aghol::Wool_shaving() {
    if(user_ptr->Get_coin()>=used_storage){
        if(store_ptr->Get_total_storage()-store_ptr->Get_used_storage()>=used_storage){
            //user_ptr->Delete_coin(used_storage);
            store_ptr->Add(6,used_storage);
            user_ptr->Set_experience(user_ptr->Get_experience()+(9*used_storage));
            return 1;// to send wool added
        }
        return -1;// to send not enough space in store
    }
    return -2;// to send not enough coin
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
/*bool Aghol::Collect() {

}*/