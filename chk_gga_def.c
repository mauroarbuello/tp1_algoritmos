//CHK_GGA
#include <string.h>
#include <stdbool.h>
#include "fix.h"

#define STR_GGA "GGA"
#define MAX_CMP 4

bool chk_gga (const char *cadena) {

  size_t i, j;//contadores
  char salida_chkgga[MAX_CMP];
  char * ptr2coma;
  const char * coma = ",";

  ptr2coma = strstr (cadena, coma);
  
  //Se valida ptr2coma para el caso en que es nulo.
  if (!ptr2coma) {
    return false;
  }
  
  salida_chkgga[MAX_CMP-1]='\0';
  
  for (i = MAX_CMP-2, j = 1; j <= MAX_CMP && (ptr2coma -j)!= cadena; i--, j++) {
    salida_chkgga[i] = *(ptr2coma - j);
  }

  if ( strncmp (salida_chkgga, STR_GGA, MAX_CMP) != 0) { // la cadena no decia GGA
    return false;
  }
  
  return true;
}