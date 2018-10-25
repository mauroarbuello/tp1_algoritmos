//SEARCH_COMA_DEF
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "fix.h"

status_t search_coma (char * cadena, char ** ptr2ptrarray) {
	
	if ( !cadena || !ptr2ptrarray )
		return ST_ERR_PUNT_NULL;
	
	size_t j = 0;
	size_t i;
	const char coma = ',';


	for (i = 0; cadena[i] != '\0' ; i++) {
		if ( cadena[i] == coma) {
			*(ptr2ptrarray+j) = &(cadena[i]);
			j++;
		}
	}

	*(ptr2ptrarray+j)=NULL; //el ultimo puntero del arreglo de punteros es NULL

	return ST_OK;
}
