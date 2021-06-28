#include "user.h"

User::User()
{
    level=1;
    experience=0;
    max_experience=10;
}
void User::Check_experience()
{
    if(experience==max_experience)
    {
        level++;
        max_experience=max_experience*2+10;
        //peygham bede be karbar ke level bala rafte va namayeshe emkanate jadid
    }
}

long long int User::Get_coin(){return coin;}
int User::Get_level(){return level;}
int User::Get_time(){return time;}
int User::Get_experience(){return experience;}
void User::Set_coin(long long int _coin){coin=_coin;}
void User::Set_experience(int _experience){experience=_experience;}
void User::Set_level(int _level){level=_level;}
void User::Set_time(int _time){time=_time;}

