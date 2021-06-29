#include "habitat.h"

Habitat::Habitat() {

    status=0;
    time=0;
}
bool Habitat::Is_full() {

    if(used_sorage==total_storage)
        return true;
    return false;
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
int  Habitat::Get_time() {

	return time;
}
void Habitat::Set_time(int _time) {
	
	time += _time;
}

