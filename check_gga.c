#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "fix.h"

#define STR_GGA "GGA"

bool chk_gga (const char * cadena, char** ptr2coma) {

	size_t i, j;						//contadores
	char cadena_aux[MAX_STR];			//cadena auxiliar
    
	for( i=0, j=0 ; *ptr2coma != &(cadena[i]) ; i++){ //itero hasta la primer coma de cadena
		if ( isalpha(cadena[i]) ){					//si es alphanumerico el caracter, lo copio
			cadena_aux[j] = cadena[i];
			j++;
		}
	}
	
	cadena_aux[j] = '\0';			//le pongo un '\0' para finalizar la cadena
	
	if ( !strcmp(cadena_aux+2,STR_GGA) ){ //comparo los caracteres a partir del 3ro para ver si son GGA
		
		return true;
	}
	
	return false;
	
}
			
			