#include <stdlib.h>

#define MAX_NOMBRE			50
#define MAX_STR 			100

#define MSJ_ERR_PREFIJO 	"ERROR"

#define TXT_CAL_INVALIDO 	"Fix Inválido"
#define TXT_CAL_FIX_GPS 	"Fix GPS"
#define TXT_CAL_FIX_DGPS 	"Fix DGPS"
#define TXT_CAL_FIX_PPS 	"Fix PPS"
#define TXT_CAL_RTK 		"Fix Real Time Kinematic"
#define TXT_CAL_RTK_FLOAT 	"Fix Float Real Time Kinematic"
#define TXT_CAL_DEAD_RECK	"Fix Estimado"
#define TXT_CAL_MANUAL 		"Fix Manual"
#define TXT_CAL_SIMULATION	"Fix Simulación"

#define TXT_ST_OK					"Correcto"
#define TXT_ST_ERR_DATO_INCOMP		"Dato incompleto"
#define TXT_ST_ERR_PUNT_NULL		"Puntero nulo"
#define TXT_ST_ERR_FECHA_INVALIDA 	"Fecha ingresa invalida. Se utilizará la fecha del sistema."

typedef enum status_t{ ST_OK, ST_ERR_DATO_INCOMP, ST_ERR_PUNT_NULL, ST_ERR_FECHA_INVALIDA}status_t; //estados posibles dentro de todo el proyecto, hay que ir agregando

/* const char dic_status[][MAX_STR] = {
	TXT_ST_OK, TXT_ST_ERR_DATO_INCOMP, TXT_ST_ERR_PUNT_NULL, TXT_ST_ERR_FECHA_INVALIDA}; */

typedef struct fecha_t{	int year;	//estructura para la fecha
			int month;
			int day;
			}fecha_t;

typedef struct hora_t{	int hh;		//estructura para la hora
			int mm;
			double ss;
			}hora_t;

typedef enum calidad_t{ CAL_INVALIDO, CAL_FIX_GPS, CAL_FIX_DGPS, CAL_FIX_PPS, CAL_RTK, CAL_RTK_FLOAT, CAL_DEAD_RECK, CAL_MANUAL, CAL_SIMULATION }calidad_t;	//tipo para la calidad del fix


/* const char dic_calidad [][MAX_STR] = {
	TXT_CAL_INVALIDO, TXT_CAL_FIX_GPS, TXT_CAL_FIX_DGPS, TXT_CAL_FIX_PPS, TXT_CAL_RTK, 
	TXT_CAL_RTK_FLOAT, TXT_CAL_DEAD_RECK, TXT_CAL_MANUAL, TXT_CAL_SIMULATION
};	//diccionario para la calidad */
	

typedef struct fix_t{	char nombre[MAX_NOMBRE];	//estructura con todos los datos del fix
			struct fecha_t fecha;
			struct hora_t hora;
			double latitud;
			double longitud;
			calidad_t calidad;
			unsigned int cant_satelites;
			float hdop;
			float elevacion;
			float sep_geoide;					
			}fix_t;
