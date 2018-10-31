//MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fix.h"

#define MIN_COMA_VALIDO 		13
#define NOMBRE_POR_DEFECTO 		"archivo"
#define CHAR_STR_START			'$'

int main (int argc, char *argv[]) {

  struct fix_t fix;
  char cadena [MAX_STR];
  char * ptr2comarray [MAX_STR]; //hacer otro macro de menor longitud.

  strcpy(fix.nombre,NOMBRE_POR_DEFECTO);	//le copio el nombre por defecto a la struct fix_t

  get_currentdate(&(fix.fecha),&(fix.hora)); //obtengo la fecha y hora actual y la paso al fix_t

  proc_argv (argc, argv, &fix);	//proceso los argumentos por linea de comandos, si hay nombre o fecha los piso con los que tengo
  
  print_encabezado();	//imprimo el encabezado del archivo .gpx
  print_metadata(&fix);	//imprimo la metadata (nombre, fecha, un par de cosas más)
  print_trk_start();	//imprimo el comienzo de un track

  while ( (fgets (cadena, MAX_STR, stdin)) != NULL ) {
	
	if ( *(cadena) == CHAR_STR_START ){		//compruebo que el primer caracter de la cadena sea $

		if ( (chk_gga (cadena) == true)) {

			if ( (verify_checksum(cadena)) == true ) {

				if ( search_coma(cadena, ptr2comarray) >= MIN_COMA_VALIDO ) { //chequear que haga lo que quiero
					if ( proc_fix(ptr2comarray, &fix) == ST_OK) {
							print_trkpt (&fix);
					} //end if 5
				}//end if 4

			}//end if 3

		}//end if 2

	}//end if 1
  }//end while

  print_trk_end ();
  print_acabado ();
  
  return EXIT_SUCCESS;

}//end main
