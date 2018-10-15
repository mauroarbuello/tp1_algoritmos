#include <stdio.h>
#include <string.h>

#define MAX_STR 50

typedef enum {ST_OK = 0, ST_ERR_NULLPTR} status_t;

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

// pruebas para ver los valores que devuelve la funcion
/* int main (void) {
	
	char *array2comas[90];
	char cadena [90] = "$GPGGA ,112836.854 ,1955.118 , N1";
	search_coma(cadena, array2comas);
	

} */
