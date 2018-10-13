#include <stdio.h>
#include <string.h>
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

typedef struct fecha{int year;
					int month;
					int day;
					}fecha_t

typedef struct hora{int hh;
					int mm;
					double ss;
					}hora_t

typedef struct fix{char nombre[MAX_NOMBRE];
					struct fecha_t fecha;
					struct hora_t hora;
					double latitud;
					double longitud;
					/* Aca hay que completar los campos necesarios */			
					
					}fix_t;

	

bool procesar_argv(int argc, char *argv[], struct fix_t *fix){
	
	size_t i;
	
	for(i=1;i<argc;i++){
		if (strcmp(argv[i],STR_HELP_1)==0 || strcmp(argv[i],STR_HELP_2)==0)
			printf("%s\n",MSJ_HELP);
		
		else if (strcmp(argv[i],STR_NAME_1)==0 || strcmp(argv[i],STR_NAME_2)==0)
			strcpy(fix->nombre,argv[i+1]);
		
		else if ((!strcmp(argv[i],STR_FECHA_1) || !strcmp(argv[i],STR_FECHA_2))
			procesar_fecha(argv[i],p2info);
		
		else if ((!strcmp(argv[i],STR_YEAR_1) || !strcmp(argv[i],STR_YEAR_2))
			*p2info.fecha.year = argv[i+1];
		
		else if ((!strcmp(argv[i],STR_MONTH_1) || !strcmp(argv[i],STR_MONTH_2))
			*p2info.fecha.month = argv[i+1];
		
		else if ((!strcmp(argv[i],STR_DAY_1) || !strcmp(argv[i],STR_DAY_2))
			strcpy(*p2info.fecha.day = argv[i+1];
	}
		
}


bool todigits(char*str){
	
	size_t largo = strlen(str);
	
	if (!str)
		return false;
	
	for(size_t i=0; i<largo; i++){
		if (!isdigit(str[i]))
			for(size_t j=i; j<largo; j++)
				*(str+j)=*(str+j+1);
	}
	
	return true;
}

bool procesar_fecha(char *fecha){
	
	char* temp;

	fecha = strtol(fecha,&temp,10);
	if (*temp != '\n' && *temp != '\0')
		return false;
	
	*p2info.fecha.day = fecha%10 + 10*(fecha-fecha%10)%10;
	fecha -= fecha%100;
	fecha /= 100;
	*p2info.fecha.month = fecha%10 + 10*(fecha-fecha%10)%10;
	fecha -= fecha%100;
	fecha /= 100;
	*p2info.fecha.year = fecha;
	
}
	
	
	