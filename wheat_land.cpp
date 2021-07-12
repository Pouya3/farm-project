#include "wheat_land.h"

Wheat_land::Wheat_land()
{
}

int Wheat_land::Upgrade()
{
    // return values :
    // 1 == you have to wait unlit wheats ripen and collect them to upgrade
    // 2 == not enough shovels
    // 3 == not enough coins
    // 4 == limit for upgrade duo to user's level
    // 5 == timer set for upgrade

    if(cultivation_status == 0){ // zamin bikar
        if(store->Get_object(1)>=1){ // enough shovels
            if(user->Get_coin()>=5){ // enough coins
                if(user->Get_level()>=2){ // no limit for upgrade duo to user's level
                    store->Delete(1, 1);
                    user->Set_coin(user->Get_coin()-5);

                    upgrade_timer = 2;

                    return 4;
                }
                return 3;
            }
            return 2;
        }
    }
    return 1;
}

int Wheat_land::Cultivate(int area_to_cultivate) {
    // return values :
    // 1 == already cultivated
    // 2 == not enough area to cultivate
    // 3 == not enough wheat
    // 4 == timer set for ripening timer
    if(cultivation_status == 0){ // not cultivated
        if(total_area >= area_to_cultivate){ // total_area >= area_to_cultivate
            if(silo->Get_wheat() >= area_to_cultivate){ // enough wheat
                cultivation_status = 1;
                user->Set_experience(user->Get_experience()+area_to_cultivate);
                silo->Delete(1,area_to_cultivate);

                cultivation_status = 1;
                ripening_timer = 2;

                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}

int Wheat_land::Harvest(){
    // return values :
    // 1 == nothing to harvest
    // 2 == not enough space in silo
    // 3 == harvested successfully

    if(cultivation_status == 2){ // wheat is ripe
        if(silo->Get_total_storage() - silo->Get_used_storage() >= cultivated_area*2){ // enough space in silo
              user->Set_experience(user->Get_experience()+cultivated_area);
              silo->Add(1, cultivated_area*2);
              cultivated_area = 0;
              cultivation_status = 0;

              return 3;
        }
        return 2;
    }
    return 1;
}
