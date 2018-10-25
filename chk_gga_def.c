//CHK_GGA
#include <string.h>
#include <stdbool.h>
#include "fix.h"

#define STR_GGA "GGA"
#define MAX_CMP4 4

bool chk_gga (const char *cadena) {

  size_t i, j;//contadores
  char salida_chkgga[MAX_CMP4];
  char * ptr2coma;
  const char * coma = ",";

  ptr2coma = strstr (cadena, coma);

  for (i = 0, j = 3; j > 0; i++, j--) {
    salida_chkgga[i] = *(ptr2coma - j);
  }

  if ( strncmp (salida_chkgga, STR_GGA, MAX_CMP4) != 0) { // la cadena no decia GGA
    return false;
  }
  return true;
}
