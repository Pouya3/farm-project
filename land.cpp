#include "land.h"

Land::Land()
{
}

int Land::Get_level() { return level; }
void Land::Set_level(int _level) { level = _level; }
void Land::Set_total_area(int _total_area) { total_area = _total_area; }
int Land::Get_total_area() { return total_area; }
int Land::Get_cultivated_area() { return cultivated_area; }
void Land::Set_cultivated_area(int _cultivated_area) { cultivated_area = _cultivated_area; }
int Land::Get_cultivation_status() { return cultivation_status; }
void Land::Set_cultivation_status(int _cultivation_status) { cultivation_status = _cultivation_status; }
void Land::Set_ripening_timer(int _ripening_timer) { ripening_timer = _ripening_timer; }
int Land::Get_ripening_timer() { return ripening_timer; }
void Land::Set_upgrade_timer(int _upgrade_timer) { upgrade_timer = _upgrade_timer; }
int Land::Get_upgrade_timer() { return upgrade_timer; }
