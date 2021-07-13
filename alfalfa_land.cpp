#include "alfalfa_land.h"

Alfalfa_land::Alfalfa_land()
{
}

int Alfalfa_land::Upgrade()
{
    // return values :
    // 1 == alfalfa land is not built yet
    // 2 == you cannot upgrade until alfalfs ripen and get harvested
    // 3 == not enough shovels
    // 4 == not enough coins
    // 5 == limit for upgrading duo to user's level
    // 6 == timer set for upgrading

    if(building_status == 2){ // alfalfa land is built
        if(cultivation_status == 0){ // zamin bikar
            if(store->Get_object(1)>=2){ // enough shovels
                if(user->Get_coin()>=5){ // enough coins
                    if(user->Get_level()>=4){ // not limit for upgrading duo to user's level
                        if(upgrade_timer==0){
                            store->Delete(1, 2);
                            user->Set_coin(user->Get_coin()-5);

                            upgrade_timer = 3;
                            return 7;
                        }
                        return 6;
                    }
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

int Alfalfa_land::Plow()
{
    // return values :
    // 1 == you have to wait until alfalfa ripens and gets collected
    // 2 == field is cultivated. you cannot plow
    // 3 == not enough coins
    // 4 == timer set for plowing
    // 5 == alfalfa land is not built yet
    if(upgrade_timer==0){
        if(cultivation_status == 0) { // ready to plow
            if(user->Get_coin()>=5*total_area){ // enough coins
                  user->Set_coin(user->Get_coin()-(5*total_area));

                  plowing_timer = 1;

                  return 4;
            }
            return 3;
        }
        else { // not ready to plow
            if(building_status != 2){
                return 5;
            }
            else{
                if(cultivation_status == 1){ // already plowed
                    return 1;
                }
                else { // field is cultivated. you cannot plow
                    return 2;
                }
            }
        }
    }
    return 6;
}

int Alfalfa_land::Cultivate(int area_to_cultivate) {
    // return values :
    // 1 == alfalfland is not built yet
    // 2 == not plowed
    // 3 == not enough alfalfa
    // 4 == timer set for ripening

    if(building_status == 2){ // already built
        if(cultivation_status == 1) { // plowed but not cultivated
            if(store->Get_object(3) >= area_to_cultivate){ // enough alfalfa
                 cultivation_status = 2;
                 plowed_area = 0;
                 user->Set_experience(user->Get_experience()+area_to_cultivate*2);
                 store->Delete(3,area_to_cultivate);

                 ripening_timer = 4;

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

                    building_timer = 3;

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

void Alfalfa_land::Set_plowed_area(int _plowed_area){
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

void Alfalfa_land::Set_plowing_timer(int _plowing_timer){
    plowing_timer = _plowing_timer;
}

int Alfalfa_land::Get_plowing_timer(){
    return plowing_timer;
}

