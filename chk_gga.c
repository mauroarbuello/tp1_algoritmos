#include <stdio.h>
#include <string.h>

#define MAX_4 4

#define MAX_STR 5000
#define STR_GGA "GGA"
//#define CHAR_PROC ,


int main (void) {
  int c, val_chkgga; //devolver datos
  int i, j; //contaores
  char * ptr2start, ptr2end;
  char * ptr2coma;
  char * ptr2$;
  const char cadena [50] = "$GPGA,$A ,3 ,01";
  const char * coma = ",";
  const char * pesos = "$";
  char chk_gga [MAX_4];//inicializar // para chequear que la entrada sea GGA
  size_t max_cmp4 = 4;

//ptr2coma = strstr (cadena, coma); //HC



/////while (c = fgets(cadena, MAX_STR, stdin) != NULL ) {

  ptr2coma = strstr (cadena, coma);
printf ("%s\n", ptr2coma); //HC
  /*hay que validar el caso en que hay una ',' antes de la
  tercera posicion*/
  for (i = 0, j = 3; j > 0 && i < 3; i++, j--) {
    chk_gga [i] = *(ptr2coma - j);
    }// guarda los 3 char para luego comparar con GGA.

  val_chkgga = strncmp (chk_gga, STR_GGA, max_cmp4);
 
    if (val_chkgga != 0) { // si el dato no es GGA
    printf ("%s : %s\n", "error", chk_gga); // -------PRUEBA
  } else {
    printf ("%s : %s\n", chk_gga, "joya"); //-------- PRUEBAS
 
  }
} //end main
