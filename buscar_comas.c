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

// intento para que devuekva un puntero al arreglo de punteros
char ** search_coma ( const char * cadena) {

  int j = 0;
  int i;
  const char * coma = ",";
  char * ptr2coma [MAX_STR];
  char ** ptr2ptrarray;

  for (i = 0; cadena[i] != '\0'; i++) {
    if ( cadena[i] == ',') {

    *(ptr2coma + j) = (cadena [i]);
    j++;

    }
  }
  *ptr2ptrarray = ptr2coma;
  return ptr2ptrarray;
}


// pruebas para ver los valores que devuelve la funcion
int main (void) {
  char **arr_ptr2 [MAX_STR];
  //char * ptr[MAX_STR];
  const char cadena [90] = "$GPGGA ,112836.854 ,1955.118 , N1";
  *arr_ptr2 = search_coma (cadena);
  printf ("|%c|\n", arr_ptr2);
  printf ("|%p|\n", arr_ptr2);
  printf ("|%c|\n", *arr_ptr2);
  printf ("|%p|\n", *arr_ptr2);
  printf ("|%c|\n", *(cadena + 7));
  printf ("|%p|\n", (cadena + 7));
  //printf ("|%c|\n", *(cadena + 7));
  //printf ("%p\n", (cadena + 7));
  //printf ("%p\n", *(cadena + 7));
}
