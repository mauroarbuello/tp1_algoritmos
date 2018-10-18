#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fix.h"

#include "checksum_def.c"
#include "chk_gga_def.c"
#include "proc_argv_def.c"
#include "print_salida_def.c"
#include "search_coma_def.c"
#include "procesar_fix_largo.c"
#include "get_currentdate_def.c"
#include "print_help_def.c"
#include "errores_def.c"

#define NOMBRE_POR_DEFECTO "archivo"
#define MIN_COMA_VALIDO 14

int main (int argc, char *argv[]) {

  struct fix_t *fix;
  char cadena [MAX_STR];
  char * ptr2comarray [MAX_STR]; //hacer otro macro de menor longitud.
  //para guardar datos
  //char *c; //para verificar fgets
  size_t array_l;

get_currentdate(&(fix->fecha),&(fix->hora)); //PATO, acordate de pedir la fecha al sistema cada vez que se ejectuta el programa
strcpy(&(fix->nombre),NOMBRE_POR_DEFECTO);	//Y hay que copiar el nombre por defecto, por si no nos mandan ningun nombre
  proc_argv (argc, argv, fix);//&fix?? NO, solo fix (porque fix lo declaraste como un puntero)

  print_encabezado ();
  print_metadata (*fix);//*fix porque fix es fix_t* y la funcion quiere el tipo fix_t
  print_trk_start ();

  while ( (fgets (cadena, MAX_STR, stdin)) != NULL ) {

    if ( (chk_gga (cadena) == true)) {

      if ( (verify_checksum (cadena) == true) ) {

        search_coma (cadena, ptr2comarray);
        if ( (array_l = strlen (*ptr2comarray)) > (size_t) MIN_COMA_VALIDO) { //chequear que haga lo que quiero

          proc_fix(ptr2comarray, fix);

          print_trkpt (*fix);
		
        }//end if 3

      }//end if 2

    }//end if 1

  }//end while

  print_trk_end ();
  print_acabado ();
	 
	return EXIT_SUCCESS; //acordate de poner un retorno, es int main, debe devolver un int;
}//end main
