#include <stdio.h>
#include "fix.h"        //contiene a MSJ_ERR_PREFIJO y al typedef status_t con sus correspondientes posibles estados

//mensajes de calidad del fix (a pesar de que no los usamos)
#define TXT_CAL_INVALIDO 	  "Fix Inválido"
#define TXT_CAL_FIX_GPS 	  "Fix GPS"
#define TXT_CAL_FIX_DGPS 	  "Fix DGPS"
#define TXT_CAL_FIX_PPS 	  "Fix PPS"
#define TXT_CAL_RTK 		    "Fix Real Time Kinematic"
#define TXT_CAL_RTK_FLOAT   "Fix Float Real Time Kinematic"
#define TXT_CAL_DEAD_RECK	  "Fix Estimado"
#define TXT_CAL_MANUAL 		  "Fix Manual"
#define TXT_CAL_SIMULATION  "Fix Simulación"
  
//mensajes de errores  
#define TXT_ST_OK					         "Correcto"              
#define TXT_ST_ERR_DATO_INCOMP		"Dato incompleto"
#define TXT_ST_ERR_PUNT_NULL		"Puntero nulo"
#define TXT_ST_ERR_FECHA_INVALIDA 	"Fecha ingresa inválida. Se utilizará la fecha del sistema."
#define TXT_ST_ERR_FIX_INVALIDO		"Fix inválido. Se ignora."

//comienzo de la funcion
void print_status(status_t st){     //funcion que imprime errores de estado con su correspondiente mensaje
//le paso una variable status_t que va a imprimir
static const char *dic_status[] = {     //diccionario de estados, contiene el mensaje de error de cada estado
	TXT_ST_OK, TXT_ST_ERR_DATO_INCOMP, TXT_ST_ERR_PUNT_NULL, TXT_ST_ERR_FECHA_INVALIDA, TXT_ST_ERR_FIX_INVALIDO}; //diccionario para status_t
  
  if ( st != ST_OK )    //si el estado es ST_OK no imprime error (no hay error)
      fprintf(stderr,"%s: %s\n",MSJ_ERR_PREFIJO, dic_status[st]);   //los imprime por stderr
	
}
//fin de la funcion
