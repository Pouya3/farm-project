#include "alfalfa_land.h"

Alfalfa_land::Alfalfa_land(User* _user, Store* _store) 
{
    store = _store;
    user = _user;
    if(user->Get_level()>=3)
        is_active=true;
    else
        is_active=false;
    space=4;
}

void Alfalfa_land::Upgrade() 
{
    if (store->Get_object(1)>=2 && user->Get_coin()>=5 && user->Get_level()>=4) {
        store->Delete(1, 2);         
        user->Set_coin(user->Get_coin()-5);

        // Qtimer

        // after Qtimer finished :

        user->Set_experience(user->Get_experience()+3);
        space*=2;
    }
    else { // not enough resources for upgrading

        if(store->Get_object(1)<2) {  } // shovel needed
        else if (user->Get_coin()<5) { } // coin needed
        else { } // level needed
    }
}

void Alfalfa_land::Plow(int tedad) 
{
    if(status==0) { // zamin bikar
        if(user->Get_coin()>=5*tedad && user->Get_level()>=3){
            user->Set_coin(user->Get_coin()-5);
            status=1;
            // Qtimer

            // after Qtimer finished :
            status=2;
            user->Set_experience(user->Get_experience()+tedad);
        }
        else { // not enough resources for upgrading
            if (user->Get_coin()<5*tedad) { } // coin needed
            else { } // level needed
        }
    }
    else { // zamin ra nemi shavad shokm zad

    }
}