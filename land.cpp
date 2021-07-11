#include "land.h"

Land::Land()
{
}

void Land::Set_time(int _time) { time=_time; }
int Land::Get_time() { return time; }
int Land::get_level() { return level; }
void Land::Set_level(int _level) { level = _level; }
