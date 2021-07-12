#include "habitat.h"

Habitat::Habitat() {
}
bool Habitat::Add(int type, int amount) {

    if(used_storage+amount<=total_storage){
        used_storage+=amount;
        return true;
    }
    return false;
}

bool Habitat::Delete(int type, int amount) {

    if(used_storage-amount>=0){
        used_storage-=amount;
        return true;
    }
    return false;
}

void Habitat::Set_building_status(int _building_status){
    building_status = _building_status;
}

int Habitat::Get_building_status() {
    return building_status;
}

void Habitat::Set_feeding_status(int _feeding_status){
    feeding_status = _feeding_status;
}

int Habitat::Get_feeding_status(){
    return feeding_status;
}

void Habitat::Set_feeding_timer(int _feeding_timer){
    feeding_timer = _feeding_timer;
}

int Habitat::Get_feeding_timer(){
    return feeding_timer;
}

void Habitat::Set_building_timer(int _building_timer){
    building_timer = _building_timer;
}

int Habitat::Get_building_timer(){
    return building_timer;
}

void Habitat::Set_upgrade_timer(int _upgrade_timer){
    upgrade_timer = _upgrade_timer;
}

int Habitat::Get_upgrade_timer(){
    return upgrade_timer;
}
