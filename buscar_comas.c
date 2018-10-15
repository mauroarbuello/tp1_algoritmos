#include <stdio.h>
#include <string.h>

#define MAX_STR 50

typedef enum {ST_OK = 0, ST_ERR_NULLPTR} status_t;

/* este fue el intento para hacerla status_t
status_t search_coma ( const char * cadena, char ** arr_ptr []) {

  int j = 0;
  int i;
  const char * coma = ",";
  if (!cadena || !arr_ptr) {
    return ST_ERR_NULLPTR;
  }

  for (i = 0; cadena[i] != '\0'; i++) {
    if ( cadena[i] == coma) {
    *(arr_ptr + j) = &(cadena [i]);
      j++;
    }
  }
  return ST_OK;
}
*/
/*
// intento para que devuekva un puntero al arreglo de punteros
char ** search_coma ( const char * cadena) {

  int j = 0;
  int i;
  const char coma = ",";
  char * ptr2coma [MAX_STR];
  char *(*ptr2ptrarray)[MAX_STR];

  for (i = 0; cadena[i] != '\0'; i++) {
    if ( cadena[i] == ',') {

    *(ptr2coma + j) = (cadena [i]);
    j++;

    }
  }
  ptr2ptrarray = ptr2coma[0];
  return ptr2ptrarray;
}
*/

status_t search_coma ( char * cadena, char ** ptr2ptrarray) {
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

	return ST_OK;
}


// pruebas para ver los valores que devuelve la funcion
int main (void) {
  char * ptr2ptr[90];
  //char * ptr[MAX_STR];
  char cadena [90] = "$GPGGA ,112836.854 ,1955.118 , N1";
  search_coma (cadena, ptr2ptr);
  //printf ("|%c|\n", arr_ptr2);
  //printf ("|%p|\n", arr_ptr2);
  printf ("valor arr_ptr2:      |%c|\n",**ptr2ptr);
  //printf ("direccion arr_ptr2:  |%p|\n",ptr2ptr);
  printf ("valor cadena:        |%c|\n",*(cadena + 7));
  printf ("direccion cadena:    |%p|\n",(cadena + 7));
  //printf ("|%c|\n", *(cadena + 7));
  //printf ("%p\n", (cadena + 7));
  //printf ("%p\n", *(cadena + 7));
}
