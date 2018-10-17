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

void imprimir_ayuda (void) {

  printf("%s\n\n", MSJ_AYUDA_INICIO);
  printf("%s\n", SEPARADOR_);
  printf("%s\n", SEPARADOR_);
  printf("%s\n", MSJ_ARG_LCMD);
  printf("%s\n", SEPARADOR_);

  //help
  printf("%s\n", CMD_HELP1);
  printf("%s\n", CMD_HELP2);
  printf("%s\n", MSJ_CMD_EQ);

  printf("%s%s%s\n", START_COMENT, COMENT_HELP, END_COMENT);
  printf("%s\n", SEPARADOR_);

  //nombre
  printf("%s %s\n", CMD_NOMBRE1, MSJ_NOMBRE);
  printf("%s %s\n", CMD_NOMBRE2, MSJ_NOMBRE);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s %d\n", MSJ_FORMATO, FORMATO_NOMBRE, MAX_NOMBRE);
  printf("%s %s\n", MSJ_EJEMPLO , EJ_NOMBRE);
  printf("%s%s%s\n", START_COMENT, COMENT_NOMBRE, END_COMENT);
  printf("%s\n", SEPARADOR_);

  //fecha
  printf("%s %s\n", CMD_FECHA1, MSJ_FECHA);
  printf("%s %s\n", CMD_FECHA2, MSJ_FECHA);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s\n", MSJ_FORMATO, FORMATO_FECHA);
  printf("%s %s\n",MSJ_EJEMPLO , EJ_FECHA);
  printf("%s%s%s\n", START_COMENT, COMENT_FECHA, END_COMENT);
  printf("%s\n", SEPARADOR_);

  //año
  printf("%s %s\n", CMD_YEAR1, MSJ_YEAR);
  printf("%s %s\n", CMD_YEAR2, MSJ_YEAR);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s\n", MSJ_FORMATO, FORMATO_YEAR);
  printf("%s %s\n",MSJ_EJEMPLO , EJ_YEAR);
  printf("%s %s\n", MSJ_VALIDEZ, VALIDEZ_YEAR);
  printf("%s%s%s\n", START_COMENT, COMENT_YEAR, END_COMENT);
  printf("%s\n", SEPARADOR_);

  //mes
  printf("%s %s\n", CMD_MES1, MSJ_MES);
  printf("%s %s\n", CMD_MES2, MSJ_MES);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s\n", MSJ_FORMATO, FORMATO_MES);
  printf("%s %s\n",MSJ_EJEMPLO , EJ_MES);
  printf("%s %s\n", MSJ_VALIDEZ, VALIDEZ_MES);
  printf("%s%s%s\n", START_COMENT, COMENT_MES, END_COMENT);
  printf("%s\n", SEPARADOR_);

  //dia
  printf("%s %s\n", CMD_DIA1, MSJ_DIA);
  printf("%s %s\n", CMD_DIA2, MSJ_DIA);

  printf("%s\n", MSJ_CMD_EQ);
  printf("%s %s\n", MSJ_FORMATO, FORMATO_DIA);
  printf("%s %s\n",MSJ_EJEMPLO , EJ_DIA);
  printf("%s %s\n", MSJ_VALIDEZ, VALIDEZ_DIA);
  printf("%s%s%s\n", START_COMENT, COMENT_DIA, END_COMENT);
  printf("%s\n", SEPARADOR_);

  printf("%s\n", SEPARADOR_);

  //info sobre el programa
  printf("%s\n", MSJ_INFO_PROG);
  printf("%s\n", SEPARADOR_);

  //caso de error de lectura
  printf("%s%s%s\n", START_COMENT, MSJ_HORA_SIS, END_COMENT);
  //max char leidos
  printf("%s%s%d%s\n", START_COMENT, MSJ_MAX_CHAR, MAX_STR, END_COMENT);



}

}

//ASI DE VE IMPRESO
/* ---AYUDA---

Lista de comandos validos con sus respectivos formatos:

-n nombre
--name nombre
Ambos comandos son equivalentes.
Formato esperado: maximo 50 caracteres
Ejemplo: @1bocalaconchadetumadre1@
----------------------
-f fecha
--format fecha
Ambos comandos son equivalentes.
Formato esperado: yyyymmdd
Ejemplo: 20181016
----------------------
-Y año
--year año
Ambos comandos son equivalentes.
Formato esperado: yyyy
Ejemplo: 2018
Condiciones de validez:  0 < yyy <= año actual
----------------------
-m mes
--month mes
Ambos comandos son equivalentes.
Formato esperado: mm
Ejemplo: 10
Condiciones de validez:  1 - 12
----------------------
-d día
--day día
Ambos comandos son equivalentes.
Formato esperado: dd
Ejemplo: 16
Condiciones de validez:  1 - 31
---------------------- */
