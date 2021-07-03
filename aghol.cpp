#include "aghol.h"

Aghol::Aghol(Store* _store_ptr){
    store_ptr=_store_ptr;
    total_storage=2;
    used_storage=0;
    return;
}
void Aghol::Upgrade() {
	level++;
	total_storage *= 2;
}
bool Aghol::Feed() {
    if(store_ptr->Delete(3, used_storage)){
    return true;
    }
    return false;
}
int Aghol::Wool_shaving() {
    if(user_ptr->Get_coin()>=used_storage){
        if(store_ptr->Get_total_storage()-store_ptr->Get_used_storage()>=used_storage){
            //user_ptr->Delete_coin(used_storage);
            store_ptr->Add(6,used_storage);
            return 1;// to send wool added
        }
        return -1;// to send not enogh space in store
    }
    return -2;// to send not enogh coin
}
/*bool Aghol::Collect() {

}*/