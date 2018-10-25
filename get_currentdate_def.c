//GET_CURRENTDATE
#include <time.h>
#include <stdio.h>
#include "fix.h"

void get_currentdate(struct fecha_t* fecha, struct hora_t* hora){

	struct tm *tiempo;
	time_t tiempo_seg;
	tiempo_seg = time(NULL);
	tiempo = localtime(&tiempo_seg);

	fecha->year 	= (tiempo->tm_year) +1900;
	fecha->month 	= (tiempo->tm_mon) +1;
	fecha->day 		= tiempo->tm_mday;
	hora->hh		= tiempo->tm_hour;
	hora->mm		= tiempo->tm_min;
	hora->ss		= tiempo->tm_sec;

}
