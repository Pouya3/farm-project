#include "land.h"

Land::Land()
{
}

void Land::Set_time(int _time) { time=_time; }
int Land::Get_time() { return time; }
int Land::Get_level() { return level; }
void Land::Set_level(int _level) { level = _level; }
int Land::Get_cultivated() { return cultivated; }
int Land::Get_space() { return space; }
int Land::Get_status() { return status; }
