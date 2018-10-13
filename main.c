#include <stdio.h>
#include <time.h>
#include <stdlib.h>

bool procesar_argv(int argc, char *argv[], struct fix_t *fix);
void get_fechaactual(struct fix_t *fix);

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

					
int main(int argc, char* argv[]){
	
	struct fix_t fixactual;
	
	get_fechaactual(&fixactual);
	
	procesar_argv(argc,argv,&fixactual);
	
}