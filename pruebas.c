#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "fix.h"

#define NOMBRE_POR_DEFECTO		"archivo"
				
/* int main(int argc, char* argv[]){
	
	printf("%d\n",argc);
	
	if (argc < 2){
		printf("Sin argv\n");
	}
	
	struct fix_t fixactual;
	strcpy(fixactual.nombre,NOMBRE_POR_DEFECTO);
	
	get_fechaactual(&(fixactual.fecha),&(fixactual.hora);
	
	procesar_argv(argc,argv,&fixactual);
	
	printf("Nombre: %s\nFecha(yyyy:mm:dd): %04d:%02d:%02d \n", fixactual.nombre, fixactual.fecha.year, fixactual.fecha.month, fixactual.fecha.day);
	
	return EXIT_SUCCESS;
} */
void procesar_argv(int argc, char *argv[], struct fix_t *fix);
void get_fechaactual(struct fecha_t *fecha, struct hora_t * hora);
status_t search_coma (char * cadena, char ** ptr2ptrarray);
bool verify_checksum(const char* str_origen);
bool chk_gga (const char *cadena);
status_t procesar_fix(char ** ptr2coma,struct fix_t * fix);
void print_encabezado(void);
void print_metadata(struct fix_t * fix);
void print_trk_start(void);
void print_trkpt(struct fix_t* fix);
void print_trk_end(void);
void print_acabado(void);

// pruebas para ver los valores que devuelve la funcion search_coma
/* int main (void) {
	//prueba la funcion search_coma y check_gga
	char *array2comas[90];
	char cadena [90] = "$GPGGA,112836.854,1955.118,N,07742.541,W,1,12,1.0,0.0,M,0.0,M,,*7C";
	struct fix_t fix;
	
	print_encabezado();
	
	search_coma(cadena, array2comas);
	
	if ( procesar_fix(array2comas,&fix) != ST_OK )
		printf("%s\n","Error en el fix");
	printf("HORA: %d:%d:%f\nLAT:%f LON:%f CAL:%d SAT:%d HDoP:%f ELE:%f SEP:%f\n",fix.hora.hh,fix.hora.mm,fix.hora.ss,fix.latitud,fix.longitud,fix.calidad,fix.cant_satelites,fix.hdop,fix.elevacion,fix.sep_geoide);

	
	return 0;
	

} */

int main(int argc, char* argv[]){
	
	struct fix_t fixactual;
	char str_actual[MAX_STR];
	char *array2comas[MAX_STR];
	
	strcpy(fixactual.nombre,NOMBRE_POR_DEFECTO);
	
	get_fechaactual(&(fixactual.fecha),&(fixactual.hora));
	
	procesar_argv(argc,argv,&fixactual);
	
	print_encabezado();
	print_metadata(&fixactual);
	print_trk_start();
	
	while( fgets(str_actual,MAX_STR,stdin) != NULL ){
		if ( chk_gga(str_actual) ){
			if ( verify_checksum(str_actual) ){
				search_coma(str_actual,array2comas);
				if ( procesar_fix(array2comas,&fixactual) == ST_OK )
					print_trkpt(&fixactual);
			}
		}
	}

	print_trk_end();
	print_acabado();
	
	return 0;

}

// ./pruebaargv --name archivo1 --month 11 --day 20 >> ejemplo.gpx

/* int main(int argc, char* argv[]){
	
	char str_actual[MAX_STR];
	struct fix_t fixactual;
	
	get_fechaactual(&(fixactual.fecha),&(fixactual.hora));
	
	procesar_argv(argc,argv,&fixactual);
	
	while( fgets(str_actual,MAX_STR,stdin) != NULL ){
		
		if (verify_checksum(str_actual))
			printf("%s\n","OKA");
	}
	
	return EXIT_SUCCESS;
	
} */