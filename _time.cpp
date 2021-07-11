#include "_time.h"

void Time :: Set_hour(int _hour){
  hour=_hour;
  if(hour==24){
    hour=0;
    day++;
  }
}
int Time :: Get_hour(){
 return hour; 
}
int Time :: Get_day(){
 return day; 
}
