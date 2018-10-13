#include <time.h>

typedef struct fecha{int year;
					int month;
					int day;
					}fecha_t

typedef struct hora{int hh;
					int mm;
					double ss;
					}hora_t

typedef struct fix{char nombre[MAX_NOMBRE];
					struct fecha_t fecha;
					struct hora_t hora;
					double latitud;
					double longitud;
					/* Aca hay que completar los campos necesarios */			
					
					}fix_t;
					

void get_fechaactual(struct fix_t *fix){
	
	struct tm* tiempo= *localtime(time_t(NULL));
	
	fix->fecha.year = tiempo.tm_year;
	fix->fecha.month = tiempo.tm_month;
	fix->fecha.day = tiempo.tm_day;
	
}