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

void Store::Add(int object_type, int number){
    switch(object_type){
    case 1: this->shovel+=number; break;
    case 2: this->nail+=number; break;
    case 3: this->alfalfal+=number; break;
    case 4: this->egg+=number; break;
    case 6: this->wool+=number; break;
    case 5:
        milk+=number;
        milk_info.push_back(std::pair<int,int>(number, 1)); // 1 = temp value for time
        break;
    }
}

void Store::Delete(int object_type, int number){
    switch(object_type){
    case 1: this->shovel-=number; break;
    case 2: this->nail-=number; break;
    case 3: this->alfalfal-=number; break;
    case 4: this->egg-=number; break;
    case 6: this->wool-=number; break;
    case 5:
        milk-=number;
        milk_info.push_back(std::pair<int,int>(number, 1)); // 1 = temp value for time
        break;
    }
}

int Store::Get_object(int type){
    switch(type){
    case 1: return shovel; break;
    case 2: return nail; break;
    case 3: return alfalfal; break;
    case 4: return egg; break;
    case 5: return milk; break;
    case 6: return wool; break;
    }
}
