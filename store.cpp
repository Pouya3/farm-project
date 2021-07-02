#include "store.h"
#include <math.h>

Store::Store(User* _user)
{
    user = _user;
}

void Store::Upgrade(){
    if(
            nail >= level
            && shovel >= level - 1
            && user->Get_coin() >= pow(this->level,3) * 10
      ) // enough resources
    {
        if(user->Get_level() <= this->level){ // user's level will be lower than store's level after upgarde store

        }
        else{ // no problem for upgrading
            this->Delete(2, this->level);
            this->Delete(1, this->level-1);
            user->Set_coin(user->Get_coin()-pow(this->level,3) * 10);
            // Qtimer

            // after Qtimer finished :
            this->level++;
            this->total_storage = round(this->total_storage*1.5);
            user->Set_experience(user->Get_experience()+this->level*3);
        }

    }
    else{ // not enough resources

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
                milk_info.push_back(std::pair<int,int>(number, 1)); // 1 = temp value for time
                break;
        }
       return true;
    }
}

bool Store::Delete(int object_type, int number){
    vector<pair<int, int>>::iterator milk_iter;

    switch(object_type){
    case 1:
        if(shovel<number){ // not enough shovels
            return false;
        }
        else{ // enough shovels
            this->shovel-=number;
            return true;
        }

    case 2:
        if(nail<number){ // not enough nails
            return false;
        }
        else{ // enough nails
            this->nail-=number;
            return true;
        }
    case 3:
        if(alfalfa<number){ // not enough alfalfa
            return false;
        }
        else{ // enough alfalfa
            this->alfalfa-=number;
            return true;
        }
    case 4:
        if(egg<number){ // not enough egg
            return false;
        }
        else{ // enough egg
            this->egg-=number;
            return true;
        }
    case 6:
        if(wool<number){ // not enough wool
            return false;
        }
        else{ // enough wool
            this->wool-=number;
            return true;
        }
    case 5:
        if(milk<number){ // not enough milk
            return false;
        }
        else{ // enough milk
            milk-=number;

            milk_iter=milk_info.begin();
            while(number>0){
                if(number>milk_iter->first){ // not enough milk in this vector node
                    number-=milk_iter->first;
                    milk_info.erase(milk_iter);
                    milk_iter=milk_info.begin();
                }
                else { // enough milk in this vector node
                    milk_iter->first-=number;
                    number=0;
                }
            }
            return true;
        }
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
