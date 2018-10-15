#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "fix.h"

status_t search_coma (char * cadena, char ** ptr2ptrarray) {
	int j = 0;
	int i;
	const char coma = ',';
	int largo = strlen(cadena);

	for (i = 0; i<largo ; i++) {
		if ( cadena[i] == coma) {
			*(ptr2ptrarray+j) = &(cadena[i]);
			j++;
		}
	}
	
	*(ptr2ptrarray+j)='\0';

	return ST_OK;
}
