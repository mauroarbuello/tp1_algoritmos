#include <stdio.h>
#include <string.h>
#include "fix.h"

#define MSJ_HELP	"Ayuda"

#define STR_HELP_1 "-h"
#define STR_HELP_2 "--help"
#define STR_NAME_1 "-n"
#define STR_NAME_2 "--name"
#define STR_FECHA_1 "-f"
#define STR_FECHA_2 "--format"
#define STR_YEAR_1 "-y"
#define STR_YEAR_2 "--year"
#define STR_MONTH_1 "-m"
#define STR_MONTH_2 "--month"
#define STR_DAY_1 "-d"
#define STR_DAY_2 "--day"

status_t procesar_cad_fecha(char* fecha, int* year, int* month, int* day);
void get_fechaactual(struct fecha_t* fecha, struct hora_t* hora);
void print_status(status_t st);

status_t procesar_cad_fecha(char* fecha, int* year, int* month, int* day){
	
	char* temp;
	long int ntemp; //numero temporario donde almaceno la fecha como 20180925 (ejemplo)
	struct fecha_t fecha_actual, fecha_aux;	//en fecha_aux guardo los datos de la fecha y si son validos los guardo en los punteros que me pasaron
	struct hora_t hora_actual;
	
	get_fechaactual(&fecha_actual,&hora_actual);
	
	ntemp = strtol(fecha,&temp,10); // ntemp = yyyymmdd
	
	if (*temp != '\n' && *temp != '\0')
		return ST_ERR_FECHA_INVALIDA;
	
	if ( (fecha_aux.year = ntemp/10000) > fecha_actual.year) //me fijo que no sea un año mas grande que el actual
		return ST_ERR_FECHA_INVALIDA;
	
	ntemp -= fecha_aux.year*10000; //saco el año, queda ntemp = mmdd
	
	if ( (fecha_aux.month = ntemp/100) > 12 || fecha_aux.month < 1) //me fijo que sea un dia valido entre 1 y 12
		return ST_ERR_FECHA_INVALIDA;

	ntemp -= fecha_aux.month*100; //me saco de encima el mes, queda ntemp = dd
	
	if ( (fecha_aux.day = ntemp) > 31 || fecha_aux.day < 1 ) //me fijo que sea un dia valido entre 1 y 31
		return ST_ERR_FECHA_INVALIDA;
		
	//si no hubo ningun dato fuera de rango, guardo la fecha en las variables que me pusieron por puntero
		
	*day = fecha_aux.day;
	*month = fecha_aux.month;
	*year = fecha_aux.year;
	
	return ST_OK; //retorno un OK (todo salio bien)

}

void procesar_argv(int argc, char* argv[], struct fix_t* fix){
	
	size_t i;
	char* ptemp; //puntero a char auxiliar
	double ntemp; //numero para guardar los strtod temporalmente
	struct fecha_t fecha_actual; //guardo la fecha actual en una struct fecha_t
	struct hora_t hora_actual;
	status_t st; //guardo la informacion del estado
	
	get_fechaactual(&(fecha_actual),&(hora_actual));//obtengo la fechaactual y lo guarda en fecha
	
	for(i=1;i<argc;i++){
		if( (strcmp(argv[i],STR_HELP_1)==0) || (strcmp(argv[i],STR_HELP_2)==0))
			printf("%s\n",MSJ_HELP);
		
		else if( (strcmp(argv[i],STR_NAME_1)==0 ) || (strcmp(argv[i],STR_NAME_2)==0) )
			strcpy(fix->nombre,argv[i+1]);
		
		else if( (strcmp(argv[i],STR_FECHA_1)==0) || (strcmp(argv[i],STR_FECHA_2)==0) ){
			if ( (i+1) < argc){
				if ( (st = procesar_cad_fecha(argv[i+1],&(fix->fecha.year),&(fix->fecha.month),&(fix->fecha.day))) != ST_OK )
					print_status(st);
			}
			else {	st = ST_ERR_MISSING_ARG;
					print_status(st);
			}
		}
		else if( (strcmp(argv[i],STR_YEAR_1)==0) || (strcmp(argv[i],STR_YEAR_2)==0) ){
			if ( (i+1)<argc ){
				ntemp = strtod(argv[i+1],&ptemp);
				if ( (*ptemp == '\n' || *ptemp == '\0') && ( ntemp <= fecha_actual.year) ) //compruebo que no sea un año mayor a este
					fix->fecha.year = ntemp;
			}
		}
			
		else if( (strcmp(argv[i],STR_MONTH_1) ==0) || (strcmp(argv[i],STR_MONTH_2)==0) ){
			if ( (i+1)<argc ){
				ntemp = strtod(argv[i+1],&ptemp);
				if ( (*ptemp == '\n' || *ptemp == '\0') && ( ntemp < 13 && ntemp > 0)  )
					fix->fecha.month = ntemp;
			}
		}
		else if( (strcmp(argv[i],STR_DAY_1)==0) || (strcmp(argv[i],STR_DAY_2)==0) ){
			if ( (i+1)<argc ){
				ntemp = strtod(argv[i+1],&ptemp);
				if ( (*ptemp == '\n' || *ptemp == '\0') && ( ntemp < 32 && ntemp > 0) )
					fix->fecha.day = ntemp;
			}
		}
	}
		
}
