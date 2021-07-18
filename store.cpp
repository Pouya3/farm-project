#include "store.h"
#include "aghol.h"
#include "alfalfa_land.h"
#include "aviculture.h"
#include "livestock.h"
#include "silo.h"
#include "wheat_land.h"
#include <math.h>

Store::Store() : aghol(NULL), alfalfa_land(NULL), aviculture(NULL), livestock(NULL), silo(NULL), wheat_land(NULL)
{

}

int Store::Upgrade(){
    // return values :
    // 1 == not enough nails
    // 2 == not enough shovels
    // 3 == not enough coins
    // 4 == limit for upgrading duo to user's level
    // 5 == timer set for upgrade (successful upgrade)

    if(upgrade_timer!=0){
        return 6;
    }
    if(nail < level){ // not enough nails
        return 1;
    }
    else if(shovel < level - 1){ // not enough shovels
        return 2;
    }
    else if(user->Get_coin() < pow(this->level,3) * 10){ // not enough coins
        return 3;
    }
    else{ // enough resources
        if(user->Get_level() <= this->level){ // user's level will be lower than store's level after upgarde store
            return 4;
        }
        else{ // no problem for upgrading
            this->Delete(2, this->level);
            this->Delete(1, this->level-1);
            user->Set_coin(user->Get_coin()-pow(this->level,3) * 10);

            upgrade_timer = 5;

            return 5;
        }
    }
}

bool Store::Add(int object_type, int number){
    if(total_storage - used_storage < number){ // not enough space
        return false;
    }
    else{ // enough space
       switch(object_type){
          case 1: this->shovel+=number; break;
          case 2: this->nail+=number; break;
          case 3: this->alfalfa+=number; break;
          case 4: this->egg+=number; break;
          case 6: this->wool+=number; break;
          case 5:
                milk+=number;
                milk_info.push_back(std::pair<int,int>(number, 10)); // 1 = temp value for time
                break;
        }
       used_storage += number;
       return true;
    }
}

bool Store::Delete(int object_type, int number){
    std::vector<std::pair<int, int>>::iterator milk_iter;

    switch(object_type){
    case 1:
        if(shovel<number){ // not enough shovels
            return false;
        }
        else{ // enough shovels
            this->shovel-=number;
            used_storage -= number;
            return true;
        }

    case 2:
        if(nail<number){ // not enough nails
            return false;
        }
        else{ // enough nails
            this->nail-=number;
            used_storage -= number;
            return true;
        }
    case 3:
        if(alfalfa<number){ // not enough alfalfa
            return false;
        }
        else{ // enough alfalfa
            this->alfalfa-=number;
            used_storage -= number;
            return true;
        }
    case 4:
        if(egg<number){ // not enough egg
            return false;
        }
        else{ // enough egg
            this->egg-=number;
            used_storage -= number;
            return true;
        }
    case 6:
        if(wool<number){ // not enough wool
            return false;
        }
        else{ // enough wool
            this->wool-=number;
            used_storage -= number;
            return true;
        }
    case 5:
        if(milk<number){ // not enough milk
            return false;
        }
        else{ // enough milk
            milk-=number;
            used_storage -= number;

            milk_iter=milk_info.begin();
            while(number>0){
                if(number>milk_iter->first){ // not enough milk in this vector node
                    number-=milk_iter->first;
                    milk_info.erase(milk_iter);
                    milk_iter=milk_info.begin();
                }
                else { // enough milk in this vector node
                    milk_info.erase(milk_iter);
                    Set_milk_info(milk_info);
                    number=0;
                }
            }
            return true;
        }
    }
}

void Store::Set_object(int type, int number){
    used_storage = used_storage - this->Get_object(type) + number;

    switch(type){
    case 1: shovel = number; break;
    case 2: nail = number; break;
    case 3: alfalfa = number; break;
    case 4: egg = number; break;
    case 5: milk = number; break;
    case 6: wool = number; break;
    }


}

int Store::Get_object(int type){
    switch(type){
    case 1: return shovel; break;
    case 2: return nail; break;
    case 3: return alfalfa; break;
    case 4: return egg; break;
    case 5: return milk; break;
    case 6: return wool; break;
    }
}

void Store::Set_milk_info(std::vector<std::pair<int, int>> _milk_info){
    milk_info = _milk_info;
}

std::vector<std::pair<int, int>> Store::Get_milk_info(){
    return milk_info;
}
