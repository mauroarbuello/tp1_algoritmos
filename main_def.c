
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fix.h"

#include "checksum_def.c"
#include "chk_gga_def.c"
#include "proc_argv_def.c"
#include "print_salida_def.c"
#include "search_coma_def.c"
#include "procesar_fix_def.c"
#include "get_currentdate_def.c"
#include "print_help_def.c"
#include "errores_def.c"

#define MIN_COMA_VALIDO 14

int main (int argc, char *argv[]) {

  struct fix_t *fix;
  char cadena [MAX_STR];
  char * ptr2comarray [MAX_STR]; //hacer otro macro de menor longitud.
  //para guardar datos
  char *c; //para verificar fgets
  size_t array_l;

  proc_argv (argc, argv, &fix);//&fix??

  print_encabezado ();
  print_metadata (&fix);//&fix??
  print_trk_start ();

  while ( (c = fgets (cadena, MAX_STR, stdin)) != NULL ) {

    if ( (chk_gga (cadena) == true) && (verify_checksum (cadena) == true) ) {

      search_coma (cadena, ptr2comarray);
      if ( (array_l = strlen (*ptr2comarray)) > (size_t) MIN_COMA_VALIDO) { //chequear que haga lo que quiero

        size_t i = 0;//declaro aca la i por comodidad.
        proc_fix_hora (ptr2comarray, fix, i);
        i++;
        proc_fix_latitud (ptr2comarray, fix, i);
        i++;
        proc_fix_longitud (ptr2comarray, fix, i);
        i++;
        proc_fix_calidad (ptr2comarray, fix, i);
        i++;
        proc_fix_cant_sat (ptr2comarray, fix, i);
        i++;
        proc_fix_hdop (ptr2comarray, fix, i);
        i++;
        proc_fix_elevacion (ptr2comarray, fix, i);
        i++;
        i++;//se pone para saltear el campo "unidades".
        proc_fix_sep_geoide (ptr2comarray, fix, i);

        print_trkpt (fix);
      }//end if 2

    }//end if 1

  }//end while

  print_trk_end ();
  print_acabado ();

}//end main
