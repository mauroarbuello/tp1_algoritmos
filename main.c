#include <stdio.h>
#include <time.h>
#include <stdlib.h>

bool procesar_argv(int argc, char *argv[], struct fix_t *fix);
void get_fechaactual(struct fix_t *fix);

typedef struct fecha{	int year;	//estructura para la fecha
			int month;
			int day;
			}fecha_t;

typedef struct hora{	int hh;		//estructura para la hora
			int mm;
			double ss;
			}hora_t;

typedef enum calidad{ 0; 1; 2; 3; 4; 5; 6; 7; 8; }calidad_t;	//tipo para la calidad del fix
					
				

typedef struct fix{	char nombre[MAX_NOMBRE];	//estructura con todos los datos del fix
			struct fecha_t fecha;
			struct hora_t hora;
			double latitud;
			double longitud;
			calidad_t calidad;
			unsigned int cant_satelites;
			float hdop;
			float elevacion;
			float sep_geoide;					
			}fix_t;

					
int main(int argc, char* argv[]){
	
	struct fix_t fixactual;
	
	get_fechaactual(&fixactual);
	
	procesar_argv(argc,argv,&fixactual);
	
}
