#include "alfalfa_land.h"

Alfalfa_land::Alfalfa_land()
{
}

int Alfalfa_land::Upgrade()
{
    // return values :
    // 1 == not enough shovels
    // 2 == not enough coins
    // 3 == limit for upgrading duo to user's level
    // 4 == timer set for upgrading

    if(store->Get_object(1)>=2){ // enough shovels
        if(user->Get_coin()>=5){ // enough coins
            if(user->Get_level()>=4){ // not limit for upgrading duo to user's level
                store->Delete(1, 2);
                user->Set_coin(user->Get_coin()-5);

                // timer;

                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}

int Alfalfa_land::Plow(int area_to_plow)
{
    // return values :
    // 1 == already plowed
    // 2 == field is cultivated. you cannot plow
    // 3 == not enough coins
    // 4 == area selected to plow is greater than total area
    // 5 == limit to plow duo to user's level
    // 6 == timer set for plowing
    if(cultivation_status == 0) { // ready to plow
        if(user->Get_coin()>=5*area_to_plow){ // enough coins
            if(plowed_area >= area_to_plow){ // area selected to plow is smaller than total area
                if(user->Get_level()>=3){ // no limit to plow duo to user's level
                    user->Set_coin(user->Get_coin()-(5*area_to_plow));

                    // timer

                    return 6;
                }
                return 5;
            }
            return 4;
        }
        return 5;
    }
    else { // not ready to plow
        if(cultivation_status == 1){ // already plowed
            return 1;
        }
        else { // field is cultivated. you cannot plow
            return 2;
        }
    }
}

int Alfalfa_land::Cultivate(int area_to_cultivate) {
    // return values :
    // 1 == not plowed
    // 2 == not enough alfalfa
    // 3 == selected area to cultivate is greater that plowed area
    // 4 == limit for cultivation duo to user's level
    // 5 == timer set for ripening
    if(cultivation_status == 1) { // plowed but not cultivated
        if(store->Get_object(3) >= area_to_cultivate){ // enough alfalfa
            if(plowed_area >= area_to_cultivate){ // selected area to cultivate is smaller that plowed area
                if(user->Get_level()>=3){ // no limit for cultivation duo to user's level
                    cultivation_status = 2;
                    plowed_area = 0;
                    user->Set_experience(user->Get_experience()+area_to_cultivate*2);
                    store->Delete(3,area_to_cultivate);
                    // timer

                    return 5;
                }
                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}

int Alfalfa_land::Harvest(){
    // return values :
    // 1 == nothing to harvest
    // 2 == not enough space in store
    // 3 == harvested successfully
    if(cultivation_status == 3){ // ready to harvest
        if(store->Get_total_storage() - store->Get_used_storage() >= cultivated_area*2){ // enough space in store
            user->Set_experience(user->Get_experience()+cultivated_area*2);
            store->Add(3, cultivated_area*2);
            cultivated_area = 0;
            cultivation_status = 0;

            return 3;
        }
        return 2;
    }
    return 1;
}

int Alfalfa_land::Build(){
    // return values :
    // 1 == locked
    // 2 == not enough coins
    // 3 == not enough shovels
    // 4 == not enough nails
    // 5 == timer set for building
    if(building_status == 1){ // unlocked
        if(user->Get_coin()>=15){ // enough coins
            if(store->Get_object(1)>=1){ // enough shovels
                if(store->Get_object(2)>=1){ // enough nails
                    user->Set_coin(user->Get_coin()-15);
                    store->Delete(1,1);
                    store->Delete(2,1);
                    // timer

                    return 5;
                }
                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}

void Alfalfa_land::set_plowed_area(int _plowed_area){
    plowed_area = _plowed_area;
}

int Alfalfa_land::Get_plowed_area(){
    return plowed_area;
}

void Alfalfa_land::Set_building_status(int _building_status){
    building_status = _building_status;
}

int Alfalfa_land::Get_building_status(){
    return building_status;
}

void Alfalfa_land::Set_building_timer(int _building_timer){
    building_timer = _building_timer;
}

int Alfalfa_land::Get_building_timer(){
    return building_timer;
}

void Alfalfa_land::Set_plowig_timer(int _plowing_timer){
    plowing_timer = _plowing_timer;
}

int Alfalfa_land::get_plowing_timer(){
    return plowing_timer;
}

