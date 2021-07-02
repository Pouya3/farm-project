#include "wheat_land.h"

Wheat_land::Wheat_land(User* _user, Store* _store) 
{
    store = _store;
    user = _user;
    is_active=true;
    space=5;
}

void Wheat_land::Upgrade() 
{
    if (store->Get_object(1)>=1 && user->Get_coin()>=5 && user->Get_level()>=2) {
        store->Delete(1, 1);         
        user->Set_coin(user->Get_coin()-5);

        // Qtimer

        // after Qtimer finished :

        user->Set_experience(user->Get_experience()+3);
        space*=2;
    }
    else { // not enough resources for upgrading

        if(store->Get_object(1)<1) {  } // shovel needed
        else if (user->Get_coin()<5) { } // coin needed
        else { } // level needed
    }
}
