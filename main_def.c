//MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fix.h"

#define MIN_COMA_VALIDO 		13
#define NOMBRE_POR_DEFECTO 		"archivo"
#define CHAR_STR_START			'$'

//Prototipos de funciones
status_t proc_fix(char ** ptr2coma,struct fix_t * fix);

void get_currentdate(struct fecha_t * fecha, struct hora_t * hora);	//devuelve por referencia un fecha_t y hora_t con fecha y hora actual
status_t proc_cad_fecha(char* fecha, int *year,int *month, int *day);	//recibe una cadena numerica ("yyyymmdd") y pasa por referencia el valor del año, mes y dia
void proc_argv(int argc, char* argv[], struct fix_t *fix);		//procesa los arg por linea de comandos
bool chk_gga(const char* cadena);					//chequea el gga de la cadena
unsigned char nmea_checksum(const char *cadena);			//recibe una cadena y devuelve por retorno el valor de la suma EXOR
bool verify_checksum(const char* str_origen);				//verifica que se cumple el checksum en una cadena
status_t search_coma(char* cadena, char **ptr2ptrarray);		//recibe una cadena y devuelve por referencia una array de punteros a las comas de esa cadena
status_t cad_entrecomas(char **ptr2coma, char* cadena_aux, size_t pos_coma);//recibe un array de punteros a comas y devuelve por referencia la cadena que se encuentra entre la coma pos_coma y la siguiente
status_t proc_fix_hora (char **ptr2coma, struct fix_t *, size_t i); //procesa el fix a partir del array de punteros de comas que recibe
status_t proc_fix_latitud (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_longitud (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_calidad (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_cant_sat (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_hdop (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_elevacion (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_sep_geoide (char **ptr2coma, struct fix_t *fix, size_t i);
//Funciones de impresión
void print_status(status_t st);
void print_help(void);
void print_encabezado(void);
void print_metadata(struct fix_t * fix);
void print_trk_start(void);
void print_trkpt(struct fix_t* fix);
void print_trk_end(void);
void print_acabado(void);

int main (int argc, char *argv[]) {

  struct fix_t fix;
  char cadena [MAX_STR];
  char * ptr2comarray [MAX_STR]; //hacer otro macro de menor longitud.
  //para guardar datos
  //char *c; //para verificar fgets
  size_t i = 0;

  strcpy(fix.nombre,NOMBRE_POR_DEFECTO);	//le copio el nombre por defecto a la struct fix_t

  get_currentdate(&(fix.fecha),&(fix.hora)); //obtengo la fecha y hora actual y la paso al fix_t

  proc_argv (argc, argv, &fix);	//proceso los argumentos por linea de comandos, si hay nombre o fecha los piso con los que tengo

  fprintf(stderr,"%s ; %d-%d-%d\n",fix.nombre,fix.fecha.year,fix.fecha.month,fix.fecha.day);
  
  print_encabezado();	//imprimo el encabezado del archivo .gpx
  print_metadata(&fix);	//imprimo la metadata (nombre, fecha, un par de cosas más)
  print_trk_start();	//imprimo el comienzo de un track

  while ( (fgets (cadena, MAX_STR, stdin)) != NULL ) {
	i++;
	fprintf(stderr,"%s\n",cadena);
	if ( *(cadena) == CHAR_STR_START ){		//compruebo que el primer caracter de la cadena sea $
		fprintf(stderr,"%s\n","$ok");
		if ( (chk_gga (cadena) == true)) {
			fprintf(stderr,"%s\n","CHKGGAok");
			if ( (verify_checksum(cadena)) == true ) {
				fprintf(stderr,"%s\n","CHKSUMok");
				fprintf(stderr,"%u\n",search_coma(cadena, ptr2comarray));
				if ( search_coma(cadena, ptr2comarray) >= MIN_COMA_VALIDO ) { //chequear que haga lo que quiero
					fprintf(stderr,"%s\n","MINVALok");
					proc_fix(ptr2comarray, &fix);

					print_trkpt (&fix);
				}//end if 4

			}//end if 3

		}//end if 2

	}//end if 1
  }//end while

  print_trk_end ();
  print_acabado ();
  
  fprintf(stderr,"%li\n",i);
  
  return EXIT_SUCCESS;

}//end main
