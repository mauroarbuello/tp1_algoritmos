#include <stdio.h>
#include <string.h>

#define CHAR_BARRA "/"
#define CHAR_COMA ","

#define MSJ_AYUDA_INICIO "---AYUDA---"
#define MSJ_ARG_LCMD "Lista de comandos validos con sus respectivos formatos:"

//formatos
#define FORMATO_FECHA "yyyymmdd"
#define FORMATO_NOMBRE "maximo 50 caracteres"
#define FORMATO_YEAR "yyyy"
#define FORMATO_MES "mm"
#define FORMATO_DIA "dd"
//mensajes std para todos los comandos
#define MSJ_CMD_EQ "Ambos comandos son equivalentes."
#define MSJ_FORMATO "Formato esperado:"
#define MSJ_EJEMPLO "Ejemplo:"
#define MSJ_VALIDEZ "Condiciones de validez: "
#define SEPARADOR "----------------------"
//fecha
#define CMD_FECHA1 "-f"
#define CMD_FECHA2 "--format"
#define MSJ_FECHA "fecha"
//year
#define CMD_YEAR1 "-Y"//es en mayuscula
#define CMD_YEAR2 "--year"
#define MSJ_YEAR "año"
//nombre
#define CMD_NOMBRE1 "-n"
#define CMD_NOMBRE2 "--name"
#define MSJ_NOMBRE "nombre"
//mes
#define CMD_MES1 "-m"
#define CMD_MES2 "--month"
#define MSJ_MES "mes"
//dia
#define CMD_DIA1 "-d"
#define CMD_DIA2 "--day"
#define MSJ_DIA "día"
//ejemplos
#define EJ_FFECHA "20181016"
#define EJ_NOMBRE "@1bocalaconchadetumadre1@"
#define EJ_YEAR "2018"
#define EJ_MES "10"
#define EJ_DIA "16"
//rangos
#define VALIDEZ_YEAR "0 < yyy <= año actual"//chequear
#define VALIDEZ_MES "1 - 12"
#define VALIDEZ_DIA "1 - 31"
void print_help (void) {

  printf("%s\n\n", MSJ_AYUDA_INICIO);
  printf("%s\n\n", MSJ_ARG_LCMD);

  //nombre
  printf("%s %s\n", CMD_NOMBRE1, MSJ_NOMBRE);
  printf("%s %s\n", CMD_NOMBRE2, MSJ_NOMBRE);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s\n", MSJ_FORMATO, FORMATO_NOMBRE);
  printf("%s %s\n",MSJ_EJEMPLO , EJ_NOMBRE);
  printf("%s\n", SEPARADOR);

  //fecha
  printf("%s %s\n", CMD_FECHA1, MSJ_FECHA);
  printf("%s %s\n", CMD_FECHA2, MSJ_FECHA);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s\n", MSJ_FORMATO, FORMATO_FECHA);
  printf("%s %s\n",MSJ_EJEMPLO , EJ_FFECHA);
  printf("%s\n", SEPARADOR);

  //año
  printf("%s %s\n", CMD_YEAR1, MSJ_YEAR);
  printf("%s %s\n", CMD_YEAR2, MSJ_YEAR);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s\n", MSJ_FORMATO, FORMATO_YEAR);
  printf("%s %s\n",MSJ_EJEMPLO , EJ_YEAR);
  printf("%s %s\n", MSJ_VALIDEZ, VALIDEZ_YEAR);
  printf("%s\n", SEPARADOR);

  //mes
  printf("%s %s\n", CMD_MES1, MSJ_MES);
  printf("%s %s\n", CMD_MES2, MSJ_MES);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s\n", MSJ_FORMATO, FORMATO_MES);
  printf("%s %s\n",MSJ_EJEMPLO , EJ_MES);
  printf("%s %s\n", MSJ_VALIDEZ, VALIDEZ_MES);
  printf("%s\n", SEPARADOR);

  //dia
  printf("%s %s\n", CMD_DIA1, MSJ_DIA);
  printf("%s %s\n", CMD_DIA2, MSJ_DIA);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s\n", MSJ_FORMATO, FORMATO_DIA);
  printf("%s %s\n",MSJ_EJEMPLO , EJ_DIA);
  printf("%s %s\n", MSJ_VALIDEZ, VALIDEZ_DIA);
  printf("%s\n", SEPARADOR);

}

/*
//formato de impresion de comandos.
printf("%s %s\n", CMD_1, MSJ_);
printf("%s %s\n", CMD_2, MSJ_);

printf("%s\n", MSJ_CMD_EQ);
printf("%s %s\n", MSJ_FORMATO, FORMATO_);
printf("%s %s\n",MSJ_EJEMPLO , EJ_);
printf("%s\n", SEPARADOR);
*/

int main (void) {

  print_help ();

}
