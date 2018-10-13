#include <time.h>
#include <fix.h>

void get_fechaactual(struct fix_t *fix){
	
	struct tm* tiempo= *localtime(time_t(NULL));
	
	fix->fecha.year = tiempo.tm_year;
	fix->fecha.month = tiempo.tm_month;
	fix->fecha.day = tiempo.tm_day;
	
}
