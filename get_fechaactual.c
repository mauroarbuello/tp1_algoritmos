#include <time.h>
#include <fix.h>

void get_fechaactual(struct fecha_t *fecha){
	
	struct tm tiempo= *localtime(time_t(NULL));
	
	fecha->year = tiempo.tm_year;
	fecha->month = tiempo.tm_month;
	fecha->day = tiempo.tm_day;
	
}
