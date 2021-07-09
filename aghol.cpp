#include "aghol.h"

Aghol::Aghol(){
   // store_ptr=_store_ptr;
    total_storage=2;
    used_storage=0;
    return;
}
bool Aghol::Build(){
    if(user->Get_level()>=6){
        if(user->Get_coin()>=50){
            if(store->Get_object(2)>=4){
                if(store->Get_object(1)>=2){
                    user->Set_coin(user->Get_coin()-50);
                    store->Delete(2,4);
                    store->Delete(2,2);
                    level++;
                    total_storage = 2;
                    user->Set_experience(user->Get_experience()+20);

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
void Aghol::Upgrade() {
    if(user->Get_level()>=7){
        if(user->Get_coin()>=50){
            if(store->Get_object(2)>=3){
                if(store->Get_object(1)>=1){
                    user->Set_coin(user->Get_coin()-50);
                    store->Delete(2,3);
                    store->Delete(1,1);
                    level++;
                    total_storage *= 2;
                    user->Set_experience(user->Get_experience()+15);
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
    if(store->Delete(3, used_storage)){
        user->Set_experience(user->Get_experience()+(7*used_storage));
        return true;
    }
    return false;
}
int Aghol::Wool_shaving() {
    if(user->Get_coin()>=used_storage){
        if(store->Get_total_storage()-store->Get_used_storage()>=used_storage){
            //user->Delete_coin(used_storage);
            Collect();
            user->Set_experience(user->Get_experience()+(9*used_storage));
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
bool Aghol::Collect() {
     if(store->Get_total_storage()-store->Get_used_storage()>=used_storage){
        store->Add(6,used_storage);
        return true;
     }
   return false;
}
