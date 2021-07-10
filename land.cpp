#include "land.h"

Land::Land()
{
}

int Land::Get_level() { return level; }
void Land::Set_level(int _level) { level = _level; }
int Land::Get_total_area() { return total_area; }
int Land::Get_cultivated_area() { return cultivated_area; }
int Land::Get_cultivation_status() { return cultivation_status; }
void Land::Set_ripe_timer(int _time) { ripening_timer = _time; }
int Land::Get_ripe_timer() { return ripening_timer; }
