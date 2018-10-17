#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "fix.h"

#define STR_SUR 	"S"
#define STR_NORTE 	"N"
#define STR_OESTE	"W"
#define STR_ESTE	"E"

/* Donde:
$ Caracter inicial de TODAS las sentencias
GP ID del talker (GPS)
GGA Tipo de la sentencia (Fix Data)
222310.983 Horario del fix (22:23:10.983 UTC): hhmmss.sss
3437.064 Latitud (34 deg 37.064'): ddmm.mmm
S Indicador de latitud Norte o Sur (S): S/N
05822.107 Longitud (58 deg 22.107'): dddmm.mmm
W Indicador de longitud Este u Oeste (W): E/W
1 Calidad del Fix (1): 0 a 8
0 = invalido
1 = fix GPS (SPS)
2 = fix DGPS
3 = fix PPS
4 = Real Time Kinematic
5 = Float RTK
6 = Estimada (dead reckoning)
7 = Manual
8 = Simulación
12 Cantidad de Satélites utilizados (12): 0 a 12.
1.0 HDoP (1.0)
0.0 Elevación (0.0)
M Unidad (M, metros)
0.0 Separación del geoide (aproximación)
M Unidad (M, metros)
,, Secuencia de campos nulos para el receptor
*69 suma de verificación (siempre comienza con *) */

status_t cad_entrecomas(char ** ptr2coma, char* cadena_aux, size_t pos_coma){
	
	char *ptr2cad;				//puntero a comienzo de cadena nuevo
	size_t i;				//variables de iteración
	
	if ( *(ptr2coma + pos_coma) == NULL)
		return ST_ERR_PUNT_NULL;
	
	ptr2cad = *(ptr2coma + pos_coma) + 1; //comienzo la cadena en el caracter siguiente a la coma correspondiente a la pos_coma
	
	for( i=0 ; (ptr2cad + i) != *(ptr2coma + pos_coma + 1) ; i++){ //itero hasta la otra coma
		
		cadena_aux[i] = *(ptr2cad + i);
		
	}
	cadena_aux[i] = '\0';
	
	return ST_OK;
}

status_t procesar_fix(char ** ptr2coma,struct fix_t * fix){
	
	char cadena_aux[MAX_STR];	//cadena auxiliar
	char* ctemp;				//puntero a char temporal, para strtod
	double ntemp;				//double temporal
	size_t i=0;
	
	//comienzo de procesar la hora del fix
	if (cad_entrecomas(ptr2coma,cadena_aux,i) != ST_OK)
		return ST_ERR_FIX_INVALIDO;
	ntemp = strtod(cadena_aux, &ctemp);
	
	if ( *ctemp != '\0' && *ctemp != '\n')
		return ST_ERR_FIX_INVALIDO;
	
	if ( (fix->hora.hh = (int)ntemp/10000) < 0 ||  fix->hora.hh> 23 ) 	//me fijo que sea hora validos entre 0 y 23
		return ST_ERR_FIX_INVALIDO;
	
	ntemp -= fix->hora.hh*10000; 										//le saco las horas
	
	if ( (fix->hora.mm = (int)ntemp/100) < 0 || fix->hora.mm > 59) //me fijo que sea un dia valido entre 0 y 59
		return ST_ERR_FIX_INVALIDO;

	ntemp -= fix->hora.mm*100;  // le saco los minutos
	
	if ( (fix->hora.ss = ntemp) < 0 || fix->hora.ss >= 60  ) //me fijo que sea un dia valido entre 0 y 60
		return ST_ERR_FIX_INVALIDO;
	
	//si no hubo ningun dato fuera de rango, quedaron guardadas las variables bien, sigo con el siguiente dato
	//fin de procesar la hora del fix
	
	//comienzo de procesar la latitud
	i++;	//aumento 1 la posicion de comas
	
	if (cad_entrecomas(ptr2coma,cadena_aux,i) != ST_OK)
		return ST_ERR_FIX_INVALIDO;
	ntemp = strtod(cadena_aux, &ctemp);
	
	if ( *ctemp != '\0' && *ctemp != '\n')
		return ST_ERR_FIX_INVALIDO;
	
	if ( (fix->latitud = (int)ntemp/100) > 180 ) 	// compruebo que los grados sean menor a 180
		return ST_ERR_FIX_INVALIDO;
	
	ntemp -= fix->latitud*100;			//le saco los grados
	fix->latitud += ntemp/60; 			//le agrego los minutos pasados a grados
	
	i++;	//aumento 1 la posicion de comas
	
	if (cad_entrecomas(ptr2coma,cadena_aux,i) != ST_OK)
		return ST_ERR_FIX_INVALIDO;
	
	if ( (strcmp(cadena_aux, STR_SUR))!= 0 && (strcmp(cadena_aux,STR_NORTE)) != 0 )
		return ST_ERR_FIX_INVALIDO;
	if ( strcmp(cadena_aux, STR_SUR) == 0 )
		fix->latitud *= -1;
	
	//fin de procesar la latitud
	
	//comienzo de procesar la longitud
	
	i++;	//aumento 1 la posicion de comas
	
	if (cad_entrecomas(ptr2coma,cadena_aux,i) != ST_OK)
		return ST_ERR_FIX_INVALIDO;
	ntemp = strtod(cadena_aux, &ctemp);
	
	if ( *ctemp != '\0' && *ctemp != '\n')
		return ST_ERR_FIX_INVALIDO;
	
	if ( (fix->longitud = (int)ntemp/100) > 180 ) 	// compruebo que los grados sean menor a 180
		return ST_ERR_FIX_INVALIDO;
	
	ntemp -= fix->longitud*100;				//le saco los grados
	fix->longitud += ntemp/60; 				//le agrego los minutos pasados a grados
	
	i++;	//aumento 1 la posicion de comas
	
	if (cad_entrecomas(ptr2coma,cadena_aux,i) != ST_OK)
		return ST_ERR_FIX_INVALIDO;
	
	if ( (strcmp(cadena_aux, STR_OESTE))!= 0 && (strcmp(cadena_aux,STR_ESTE)) != 0 )
		return ST_ERR_FIX_INVALIDO;
	if ( strcmp(cadena_aux, STR_OESTE) == 0 )
		fix->longitud *= -1;
	
	//fin de procesar la longitud
	
	//comienzo de procesar la calidad del fix
	
	i++;	//aumento 1 la posicion de comas
	
	if (cad_entrecomas(ptr2coma,cadena_aux,i) != ST_OK)
		return ST_ERR_FIX_INVALIDO;
	ntemp = strtod(cadena_aux, &ctemp);
	
	if ( *ctemp != '\0' && *ctemp != '\n')
		return ST_ERR_FIX_INVALIDO;
	
	if ( ntemp < 0  || ntemp > MAX_CALIDAD )
		return ST_ERR_FIX_INVALIDO;
	
	fix->calidad = (int)ntemp;
	
	//fin de procesar la calidad del fix
	
	//comienzo de procesar cant_satelites
	
	i++;	//aumento 1 la posicion de comas
	
	if (!cad_entrecomas(ptr2coma,cadena_aux,i))
		return ST_ERR_FIX_INVALIDO;
	ntemp = strtod(cadena_aux, &ctemp);
	
	if ( *ctemp != '\0' && *ctemp != '\n')
		return ST_ERR_FIX_INVALIDO;
	
	if ( ntemp < 0  || ntemp > MAX_SATELITES )
		return ST_ERR_FIX_INVALIDO;
	
	fix->cant_satelites = (int)ntemp;
	
	//fin de procesar cant_satelites
	
	//comienzo de procesar HDoP
	
	i++;	//aumento 1 la posicion de comas
	
	if (cad_entrecomas(ptr2coma,cadena_aux,i) != ST_OK)
		return ST_ERR_FIX_INVALIDO;
	ntemp = strtod(cadena_aux, &ctemp);
	
	if ( *ctemp != '\0' && *ctemp != '\n')
		return ST_ERR_FIX_INVALIDO;
	
	fix->hdop = ntemp;
	
	//fin de procesar HDoP
	
	//comienzo de procesar elevacion
	i++;	//aumento 1 la posicion de comas
	
	if (cad_entrecomas(ptr2coma,cadena_aux,i) != ST_OK)
		return ST_ERR_FIX_INVALIDO;
	ntemp = strtod(cadena_aux, &ctemp);
	
	if ( *ctemp != '\0' && *ctemp != '\n')
		return ST_ERR_FIX_INVALIDO;
	
	fix->elevacion = ntemp;
	
	//fin de procesar elevacion
	
	//comienzo de procesar sep_geoide
	i += 2; 	//le sumo 2, porque no me interesa el dato de la unidad de la elevacion
	
	if (cad_entrecomas(ptr2coma,cadena_aux,i) != ST_OK)
		return ST_ERR_FIX_INVALIDO;
	ntemp = strtod(cadena_aux, &ctemp);
	
	if ( *ctemp != '\0' && *ctemp != '\n')
		return ST_ERR_FIX_INVALIDO;
	
	fix->sep_geoide = ntemp;
	
	//fin de procesar sep_geoide
	
	//fin de procesar datos del fix relevantes, si llego hasta acá todo salió bien, entonces retorno ST_OK
	
	return ST_OK;
	
}
