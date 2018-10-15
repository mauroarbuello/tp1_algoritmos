#include <stdio.h>
#include <string.h>
#define STR_GGA "GGA"

typedef enum {ST_OK, ST_ERR_DATO_INCOMP} status_t;

//
status_t chk_gga (const char *cadena, char *salida_chkgga) {

  int i, j;//contadores
  char * ptr2coma;
  const char * coma = ",";
  int val_chkgga;
  size_t max_cmp4 = 4;

  ptr2coma = strstr (cadena, coma);

  for (i = 0, j = 3; j > 0; i++, j--) {
    salida_chkgga[i] = *(ptr2coma - j);
  }

  val_chkgga = strncmp (salida_chkgga, STR_GGA, max_cmp4);

  if (val_chkgga != 0) { // la cadena no decia GGA
    return ST_ERR_DATO_INCOMP;
  }
  return ST_OK;
}
// end chk_gga
//pruebas
int main (void) {
  const char cadena [50] = "$GPGGA,$A ,3 ,01";
  char salida[4]; //HC

  chk_gga (cadena, &salida);

  printf("%s\n", salida);

}
