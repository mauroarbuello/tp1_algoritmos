//PRINT_HELP
#include <stdio.h>
#include <string.h>
#include "fix.h"
//signos
#define CHAR_BARRA "/"
#define CHAR_COMA ","
#define START_COMENT "/*"
#define END_COMENT "*/"

#define MSJ_AYUDA_INICIO "------AYUDA------"
#define MSJ_ARG_LCMD "#LISTA DE COMANDOS VALIDOS CON SUS RESPECTIVOS FORMATOS#"
#define MSJ_INFO_PROG "#INFORMACION SOBRE EL PROGRAMA#"

//formatos
#define FORMATO_FECHA "yyyymmdd"
#define FORMATO_NOMBRE "max char leidos ="
#define FORMATO_YEAR "yyyy"
#define FORMATO_MES "mm"
#define FORMATO_DIA "dd"
//mensajes std para todos los comandos
#define MSJ_CMD_EQ "Ambos comandos son equivalentes."
#define MSJ_FORMATO "Formato esperado:"
#define MSJ_EJEMPLO "Ejemplo:"
#define MSJ_VALIDEZ "Condiciones de validez: "
#define SEPARADOR_ "------------------------------------"
//fecha
#define CMD_FECHA1 "-f"
#define CMD_FECHA2 "--format"
#define MSJ_FECHA "fecha"
//year
#define CMD_YEAR1 "-y"
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
//help
#define CMD_HELP1 "-h"
#define CMD_HELP2 "--help"
//ejemplos
#define EJ_FECHA "20181016"
#define EJ_NOMBRE "@1_nombre_1@"
#define EJ_YEAR "2018"
#define EJ_MES "10"
#define EJ_DIA "16"
//rangos
#define VALIDEZ_YEAR "0 < yyyy <= año actual"//chequear
#define VALIDEZ_MES "1 - 12"
#define VALIDEZ_DIA "1 - 31"
//comentarios
#define COMENT_HELP "Se muestra una ayuda"
#define COMENT_FECHA "Modifica el metadato fecha"
#define COMENT_NOMBRE "Modifica el metadato nombre"
#define COMENT_YEAR "Modifica el metadato año"
#define COMENT_MES "Modifica el metadato mes"
#define COMENT_DIA "Modifica el metadato dia"
//info del programa
#define MSJ_HORA_SIS "En caso de un error de lectura, se tomaran los datos del sistema"
#define MSJ_MAX_CHAR "El largo máximo de la cadena a procesar es "

void print_help (void) {

  fprintf(stderr , "%s\n\n", MSJ_AYUDA_INICIO);
  fprintf(stderr , "%s\n", SEPARADOR_);
  fprintf(stderr , "%s\n", SEPARADOR_);
  fprintf(stderr , "%s\n", MSJ_ARG_LCMD);
  fprintf(stderr , "%s\n", SEPARADOR_);

  //help
  fprintf(stderr , "%s\n", CMD_HELP1);
  fprintf(stderr , "%s\n", CMD_HELP2);
  fprintf(stderr , "%s\n", MSJ_CMD_EQ);

  fprintf(stderr , "%s%s%s\n", START_COMENT, COMENT_HELP, END_COMENT);
  fprintf(stderr , "%s\n", SEPARADOR_);

  //nombre
  fprintf(stderr , "%s %s\n", CMD_NOMBRE1, MSJ_NOMBRE);
  fprintf(stderr , "%s %s\n", CMD_NOMBRE2, MSJ_NOMBRE);

  fprintf(stderr , "%s\n", MSJ_CMD_EQ);
  fprintf(stderr , "%s %s %d\n", MSJ_FORMATO, FORMATO_NOMBRE, MAX_NOMBRE);
  fprintf(stderr , "%s %s\n", MSJ_EJEMPLO , EJ_NOMBRE);
  fprintf(stderr , "%s%s%s\n", START_COMENT, COMENT_NOMBRE, END_COMENT);
  fprintf(stderr , "%s\n", SEPARADOR_);

  //fecha
  fprintf(stderr , "%s %s\n", CMD_FECHA1, MSJ_FECHA);
  fprintf(stderr , "%s %s\n", CMD_FECHA2, MSJ_FECHA);

  fprintf(stderr , "%s\n", MSJ_CMD_EQ);
  fprintf(stderr , "%s %s\n", MSJ_FORMATO, FORMATO_FECHA);
  fprintf(stderr , "%s %s\n",MSJ_EJEMPLO , EJ_FECHA);
  fprintf(stderr , "%s%s%s\n", START_COMENT, COMENT_FECHA, END_COMENT);
  fprintf(stderr , "%s\n", SEPARADOR_);

  //año
  fprintf(stderr , "%s %s\n", CMD_YEAR1, MSJ_YEAR);
  fprintf(stderr , "%s %s\n", CMD_YEAR2, MSJ_YEAR);

  fprintf(stderr , "%s\n", MSJ_CMD_EQ);
  fprintf(stderr , "%s %s\n", MSJ_FORMATO, FORMATO_YEAR);
  fprintf(stderr , "%s %s\n",MSJ_EJEMPLO , EJ_YEAR);
  fprintf(stderr , "%s %s\n", MSJ_VALIDEZ, VALIDEZ_YEAR);
  fprintf(stderr , "%s%s%s\n", START_COMENT, COMENT_YEAR, END_COMENT);
  fprintf(stderr , "%s\n", SEPARADOR_);

  //mes
  fprintf(stderr , "%s %s\n", CMD_MES1, MSJ_MES);
  fprintf(stderr , "%s %s\n", CMD_MES2, MSJ_MES);

  fprintf(stderr , "%s\n", MSJ_CMD_EQ);
  fprintf(stderr , "%s %s\n", MSJ_FORMATO, FORMATO_MES);
  fprintf(stderr , "%s %s\n",MSJ_EJEMPLO , EJ_MES);
  fprintf(stderr , "%s %s\n", MSJ_VALIDEZ, VALIDEZ_MES);
  fprintf(stderr , "%s%s%s\n", START_COMENT, COMENT_MES, END_COMENT);
  fprintf(stderr , "%s\n", SEPARADOR_);

  //dia
  fprintf(stderr , "%s %s\n", CMD_DIA1, MSJ_DIA);
  fprintf(stderr , "%s %s\n", CMD_DIA2, MSJ_DIA);

  fprintf(stderr , "%s\n", MSJ_CMD_EQ);
  fprintf(stderr , "%s %s\n", MSJ_FORMATO, FORMATO_DIA);
  fprintf(stderr , "%s %s\n",MSJ_EJEMPLO , EJ_DIA);
  fprintf(stderr , "%s %s\n", MSJ_VALIDEZ, VALIDEZ_DIA);
  fprintf(stderr , "%s%s%s\n", START_COMENT, COMENT_DIA, END_COMENT);
  fprintf(stderr , "%s\n", SEPARADOR_);

  fprintf(stderr , "%s\n", SEPARADOR_);

  //info sobre el programa
  fprintf(stderr , "%s\n", MSJ_INFO_PROG);
  fprintf(stderr , "%s\n", SEPARADOR_);

  //caso de error de lectura
  fprintf(stderr , "%s%s%s\n", START_COMENT, MSJ_HORA_SIS, END_COMENT);
  //max char leidos
  fprintf(stderr , "%s%s%d%s\n", START_COMENT, MSJ_MAX_CHAR, MAX_STR, END_COMENT);



}
