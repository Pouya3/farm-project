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
            if(store->Get_object(1)>=2*total_area){ // enough shovels
                if(user->Get_coin()>=5*total_area){ // enough coins
                    if(user->Get_level()>=4){ // not limit for upgrading duo to user's level
                        if(upgrade_timer==0){
                            store->Delete(1, 2*total_area);
                            user->Set_coin(user->Get_coin()-5*total_area);

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
    // 1 == not built
    // 2 == is upgrading
    // 3 == is getting plowed
    // 4 == is already plowed
    // 5 == is cultivated
    // 6 == is ripe (first harves)
    // 7 == not enough coins
    // 8 == timer set for plowing

    if(building_status == 2){ // built
        if(upgrade_timer == 0){ // is not upgrading
            if(plowing_timer == 0){ // not getting plowed
                if(cultivation_status != 1){ // not plowed
                    if(cultivation_status != 2){ // not cultivated
                        if(cultivation_status != 3){ // not ripe
                            if(user->Get_coin() >= total_area*5){ // enough coins
                                user->Set_coin(user->Get_coin()-(5*total_area));
                                plowing_timer = 1;

                                return 8;
                            }
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

int Alfalfa_land::Cultivate(int area_to_cultivate) {
    // return values :
    // 1 == alfalfland is not built yet
    // 2 == is upgrading
    // 3 == is cultivated
    // 4 == not plowed
    // 5 == area selected is more than total area
    // 6 == not enough alfalfa
    // 7 == timer set for ripening

    if(building_status == 2){ // already built
        if(upgrade_timer == 0){ // not upgrading
            if((cultivation_status != 2)&&(cultivation_status != 3)){ // not cultivated
                if(cultivation_status == 1) { // plowed but not cultivated
                    if(area_to_cultivate <= total_area){ // area selected to cultivate is smaller than total area
                        if(store->Get_object(3) >= area_to_cultivate){ // enough alfalfa
                            cultivation_status = 2;
                            cultivated_area = area_to_cultivate;
                            user->Set_experience(user->Get_experience()+area_to_cultivate*2);
                            store->Delete(3,area_to_cultivate);

                            ripening_timer = 4;
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

int Alfalfa_land::Harvest(){
    // return values :
    // 1 == is not built
    // 2 == nothing to harvest
    // 3 == not enough space in store
    // 4 == harvested successfully
    if (building_status == 2){ // is built
        if(cultivation_status == 3){ // ready to harvest
            if(store->Get_total_storage() - store->Get_used_storage() >= cultivated_area*2){ // enough space in store
                user->Set_experience(user->Get_experience()+cultivated_area*2);
                store->Add(3, cultivated_area*2);
                cultivated_area = 0;
                cultivation_status = 0;

                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}

int Alfalfa_land::Build(){
    // return values :
    // 1 == already built
    // 2 == locked
    // 3 == not enough coins
    // 4 == not enough shovels
    // 5 == not enough nails
    // 6 == timer set for building
    if(building_status != 2){ // not built
        if(building_status == 1){ // unlocked
            if(user->Get_coin()>=15){ // enough coins
                if(store->Get_object(1)>=1){ // enough shovels
                    if(store->Get_object(2)>=1){ // enough nails
                        user->Set_coin(user->Get_coin()-15);
                        store->Delete(1,1);
                        store->Delete(2,1);

                        building_timer = 3;

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

