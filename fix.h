//FIX_H
#ifndef FIX_H		//proteccion a la inclusion multiple
#define FIX_H

#include <stdlib.h>
#include <stdbool.h>

#define MAX_NOMBRE			50
#define MAX_STR 			500
#define MAX_CALIDAD			8
#define MAX_SATELITES		12

#define MSJ_ERR_PREFIJO 	"ERROR"


typedef enum status_t{ ST_OK, ST_ERR_DATO_INCOMP, ST_ERR_PUNT_NULL, ST_ERR_FECHA_INVALIDA, ST_ERR_FIX_INVALIDO, ST_ERR_MISSING_ARG}status_t; //estados posibles dentro de todo el proyecto, hay que ir agregando

/* const char dic_status[][MAX_STR] = {
	TXT_ST_OK, TXT_ST_ERR_DATO_INCOMP, TXT_ST_ERR_PUNT_NULL, TXT_ST_ERR_FECHA_INVALIDA, TXT_ST_ERR_FIX_INVALIDO}; */

typedef struct fecha_t{	int year;	//estructura para la fecha
			int month;
			int day;
			}fecha_t;

typedef struct hora_t{	int hh;		//estructura para la hora
			int mm;
			double ss;
			}hora_t;

typedef enum calidad_t{ CAL_INVALIDO, CAL_FIX_GPS, CAL_FIX_DGPS, CAL_FIX_PPS, CAL_RTK, CAL_RTK_FLOAT, CAL_DEAD_RECK, CAL_MANUAL, CAL_SIMULATION }calidad_t;	//tipo para la calidad del fix


/* const char dic_calidad [] [MAX_STR] = {
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

//Prototipos de funciones
status_t proc_fix(char ** ptr2coma,struct fix_t * fix);

void get_currentdate(struct fecha_t * fecha, struct hora_t * hora);	//devuelve por referencia un fecha_t y hora_t con fecha y hora actual
status_t proc_cad_fecha(char* fecha, int *year,int *month, int *day);	//recibe una cadena numerica ("yyyymmdd") y pasa por referencia el valor del año, mes y dia
void proc_argv(int argc, char* argv[], struct fix_t *fix);		//procesa los arg por linea de comandos
bool chk_gga(const char* cadena);					//chequea el gga de la cadena
unsigned char nmea_checksum(const char *cadena);			//recibe una cadena y devuelve por retorno el valor de la suma EXOR
bool verify_checksum(const char* str_origen);				//verifica que se cumple el checksum en una cadena
size_t search_coma(char* cadena, char **ptr2ptrarray);		//recibe una cadena y devuelve por referencia una array de punteros a las comas de esa cadena
status_t cad_entrecomas(char **ptr2coma, char* cadena_aux, size_t pos_coma);//recibe un array de punteros a comas y devuelve por referencia la cadena que se encuentra entre la coma pos_coma y la siguiente
status_t proc_fix_hora (char **ptr2coma, struct fix_t *, size_t i); //procesa el fix a partir del array de punteros de comas que recibe
status_t proc_fix_latitud (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_longitud (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_calidad (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_cant_sat (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_hdop (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_elevacion (char **ptr2coma, struct fix_t *fix, size_t i);
status_t proc_fix_sep_geoide (char **ptr2coma, struct fix_t *fix, size_t i);
//Funciones de impresión
void print_status(status_t st);
void print_help(void);
void print_encabezado(void);
void print_metadata(struct fix_t * fix);
void print_trk_start(void);
void print_trkpt(struct fix_t* fix);
void print_trk_end(void);
void print_acabado(void);




#endif
