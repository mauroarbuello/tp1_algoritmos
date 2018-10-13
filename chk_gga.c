#include <stdio.h>
#include <string.h>

#define MAX_4 4
#define STR_GGA "GGA"

status_t chk_gga (char * cadena) {

  int val_chkgga; //devolver datos
  int i, j;//contadores
  char * ptr2coma;
  const char * coma = ",";
  char chk_gga [MAX_4];//inicializar // para chequear que la entrada sea GGA
  size_t max_cmp4 = 4;

  ptr2coma = strstr (cadena, coma);

  /*hay que validar el caso en que hay una ',' antes de la
  tercera posicion*/
  for (i = 0, j = 4; j > 1 && i < 3; i++, j--) {
    chk_gga [i] = *(ptr2coma - j);
  }// guarda los 3 y char y ''\0' para luego comparar con GGA.

  val_chkgga = strncmp (chk_gga, STR_GGA, max_cmp4);
  if (val_chkgga != 0) { // si el dato no es GGA
    return ST_ERR_DATO_INCOMP;
  }
  return ST_OK;

}// end function
