#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "fix.h"

#define NOMBRE_POR_DEFECTO		"archivo"
#define CHAR_STR_START			'$'

//funciones para argv
void get_currentdate(struct fecha_t *fecha, struct hora_t * hora);
void proc_argv(int argc, char *argv[], struct fix_t *fix);
//funciones para la cadena nmea (fix)
bool chk_gga (const char *cadena);
bool verify_checksum(const char* str_origen);
status_t search_coma (char * cadena, char ** ptr2ptrarray);
status_t proc_fix(char ** ptr2coma,struct fix_t * fix);
//funciones de impresion
void print_encabezado(void);
void print_metadata(struct fix_t * fix);
void print_trk_start(void);
void print_trkpt(struct fix_t* fix);
void print_trk_end(void);
void print_acabado(void);
					
int main(int argc, char* argv[]){
	
	struct fix_t fixactual;
	char str_actual[MAX_STR];
	char *array2comas[MAX_STR];
	
	strcpy(fixactual.nombre,NOMBRE_POR_DEFECTO);	//le copio el nombre por defecto a la struct fix_t
	
	get_currentdate(&(fixactual.fecha),&(fixactual.hora));	//obtengo la fecha y hora actual y la paso al fix_t
	
	proc_argv(argc,argv,&fixactual);	//proceso los argumentos por linea de comandos, si hay nombre o fecha los piso con los que tengo
	
	print_encabezado();	//imprimo el encabezado del archivo .gpx
	print_metadata(&fixactual);	//imprimo la metadata (nombre, fecha, un par de cosas más)
	print_trk_start();	//imprimo el comienzo de un track
	
	while( fgets(str_actual,MAX_STR,stdin) != NULL ){	//leo la cadena, cuando fgets me devuelva NULL quiere decir que llegó a EOF
		if ( *(str_actual) == CHAR_STR_START ){		//compruebo que el primer caracter de la cadena sea $
			if ( chk_gga(str_actual) ){			//compruebo que corresponde a un GGA
				if ( verify_checksum(str_actual) ){		//hago la suma de verificacion
					search_coma(str_actual,array2comas);		//genero un array de punteros a comas
					if ( proc_fix(array2comas,&fixactual) == ST_OK )	//proceso la cadena
						print_trkpt(&fixactual);	//si dio todo OK la imprimo
				}
			}
		}
	}
	//si sale es porque llegó al EOF
	
	print_trk_end();		//imprimo la finalizacion de un track
	print_acabado();		// imprimo la ultima parte del archivo .gpx
	
	return EXIT_SUCCESS;		//devuelvo EXIT_SUCCESS, el programa se ejecutó bien

}
