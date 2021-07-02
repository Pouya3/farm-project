#include "land.h"

Land::Land()
{
    level=1;
    status=0;
    time=0;
}

void Land::Set_time(int _time) { time=_time; }
int Land::Get_time() { return time; }