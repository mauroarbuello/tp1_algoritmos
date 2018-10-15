#include <time.h>
#include <stdio.h>
#include "fix.h"

void get_fechaactual(struct fecha_t* fecha){
	
	struct tm *tiempo;
	time_t tiempo_seg;
	tiempo_seg = time(NULL);
	tiempo = localtime(&tiempo_seg);
	
	(*fecha).year = (tiempo->tm_year) +1900;
	(*fecha).month = (tiempo->tm_mon) +1;
	(*fecha).day = tiempo->tm_mday;
	
}
