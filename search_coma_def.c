//SEARCH_COMA_DEF
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "fix.h"

#define CHAR_DELIM ','

size_t search_coma (char * cadena, char ** ptr2ptrarray) {
	
	size_t j = 0;
	size_t i;

	if ( !cadena || !ptr2ptrarray )
		return 0;
	

	for (i = 0; cadena[i] != '\0' ; i++) {
		if ( cadena[i] == CHAR_DELIM) {
			*(ptr2ptrarray+j) = &(cadena[i]);
			j++;
		}
	}

	*(ptr2ptrarray+j) = NULL; //el ultimo puntero del arreglo de punteros es NULL

	return j;
}
