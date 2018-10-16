status_t procesar_fix_hora (char **ptr2coma, struct fix_t *fix);
status_t procesar_fix_latitud (char **ptr2coma, struct fix_t *fix);
status_t procesar_fix_longitud (char **ptr2coma, struct fix_t *fix);
status_t procesar_fix_calidad (char **ptr2coma, struct fix_t *fix);
status_t procesar_fix_cant_sat (char **ptr2coma, struct fix_t *fix);
status_t procesar_fix_hdop (char **ptr2coma, struct fix_t *fix);
status_t procesar_fix_elevacion (char **ptr2coma, struct fix_t *fix);
status_t procesar_fix_sep_geoide (char **ptr2coma, struct fix_t *fix);

status_t procesar_fix_hora (char **ptr2coma, struct fix_t *fix) {

  char cadena_aux[MAX_STR];	//cadena auxiliar
	char *ctemp;				//puntero a char temporal, para strtod
	double ntemp;				//double temporal
  size_t i = 0;

  cad_entrecomas (ptr2coma, cadena_aux, i);

  ntemp = strtod(cadena_aux, &ctemp);

	if ( *ctemp != '\0' && *ctemp != '\n'){
		return ST_ERR_FIX_INVALIDO;
  }
	if ( (fix->hora.hh = (int)ntemp/10000) < 0 ||  fix->hora.hh> 23 ){ 	//me fijo que sea hora validos entre 0 y 23
		return ST_ERR_FIX_INVALIDO;
	}
	ntemp -= fix->hora.hh*10000; 										//le saco las horas

	if ( (fix->hora.mm = (int)ntemp/100) < 0 || fix->hora.mm > 59){ //me fijo que sea un dia valido entre 0 y 59
		return ST_ERR_FIX_INVALIDO;
  }
	ntemp -= fix->hora.mm*100;  // le saco los minutos

	if ( (fix->hora.ss = ntemp) < 0 || fix->hora.ss >= 60  ){ //me fijo que sea un dia valido entre 0 y 60
		return ST_ERR_FIX_INVALIDO;
	}
  return ST_OK;
  //si no hubo ningun dato fuera de rango, quedaron guardadas las variables bien, sigo con el siguiente dato
}

status_t procesar_fix_latitud (char **ptr2coma, struct fix_t *fix) {

  char cadena_aux[MAX_STR];	//cadena auxiliar
	char *ctemp;				//puntero a char temporal, para strtod
	double ntemp;				//double temporal
  size_t i = 0;

  cad_entrecomas(ptr2coma,cadena_aux,i);
	ntemp = strtod(cadena_aux, &ctemp);

	if ( *ctemp != '\0' && *ctemp != '\n'){
		return ST_ERR_FIX_INVALIDO;
  }

  if ( (fix->latitud = (int)ntemp/100) > 180 ){ 	// compruebo que los grados sean menor a 180
		return ST_ERR_FIX_INVALIDO;
  }

	ntemp -= fix->latitud*100;			//le saco los grados
	fix->latitud += ntemp/60; 			//le agrego los minutos pasados a grados

  //para procesar norte/sur.
	i++;	//aumento 1 la posicion de comas

	cad_entrecomas(ptr2coma,cadena_aux,i);

	if ( (strcmp(cadena_aux, STR_SUR))!= 0 && (strcmp(cadena_aux,STR_NORTE)) != 0 ){
		return ST_ERR_FIX_INVALIDO;
  }
	if ( strcmp(cadena_aux, STR_SUR) == 0 ){
    fix->latitud *= -1;
  }
  return ST_OK;
}

status_t procesar_fix_longitud (char **ptr2coma, struct fix_t *fix) {

  char cadena_aux[MAX_STR];	//cadena auxiliar
	char *ctemp;				//puntero a char temporal, para strtod
	double ntemp;				//double temporal
  size_t i = 0;

  cad_entrecomas(ptr2coma,cadena_aux,i);
	ntemp = strtod(cadena_aux, &ctemp);

	if ( *ctemp != '\0' && *ctemp != '\n'){
		return ST_ERR_FIX_INVALIDO;
	}
	if ( (fix->longitud = (int)ntemp/100) > 180 ){ 	// compruebo que los grados sean menor a 180
		return ST_ERR_FIX_INVALIDO;
	}

	ntemp -= fix->longitud*100;				//le saco los grados
	fix->longitud += ntemp/60; 				//le agrego los minutos pasados a grados

  //para procesar este/oeste.
	i++;	//aumento 1 la posicion de comas

	cad_entrecomas(ptr2coma,cadena_aux,i);

	if ( (strcmp(cadena_aux, STR_OESTE))!= 0 && (strcmp(cadena_aux,STR_ESTE)) != 0 ){}
		return ST_ERR_FIX_INVALIDO;
  }
	if ( strcmp(cadena_aux, STR_OESTE) == 0 ){
    fix->longitud *= -1;
  }
  return ST_OK;
}

status_t procesar_fix_calidad (char **ptr2coma, struct fix_t *fix) {

  char cadena_aux[MAX_STR];	//cadena auxiliar
	char *ctemp;				//puntero a char temporal, para strtod
	double ntemp;				//double temporal
  size_t i = 0;

  cad_entrecomas(ptr2coma,cadena_aux,i);
	ntemp = strtod(cadena_aux, &ctemp);

	if ( *ctemp != '\0' && *ctemp != '\n'){
		return ST_ERR_FIX_INVALIDO;
	}
	if ( ntemp < 0  || ntemp > MAX_CALIDAD ){
		return ST_ERR_FIX_INVALIDO;
	}

  fix->calidad = (int)ntemp;
  return ST_OK;
}

status_t procesar_fix_cant_sat (char **ptr2coma, struct fix_t *fix) {

  char cadena_aux[MAX_STR];	//cadena auxiliar
	char *ctemp;				//puntero a char temporal, para strtod
	double ntemp;				//double temporal
  size_t i = 0;

  cad_entrecomas(ptr2coma,cadena_aux,i);
	ntemp = strtod(cadena_aux, &ctemp);

	if ( *ctemp != '\0' && *ctemp != '\n'){
		return ST_ERR_FIX_INVALIDO;
	}
	if ( ntemp < 0  || ntemp > MAX_SATELITES ){
		return ST_ERR_FIX_INVALIDO;
	}

  fix->cant_satelites = (int)ntemp;
  return ST_OK;
}

status_t procesar_fix_hdop (char **ptr2coma, struct fix_t *fix) {

  char cadena_aux[MAX_STR];	//cadena auxiliar
	char *ctemp;				//puntero a char temporal, para strtod
	double ntemp;				//double temporal
  size_t i = 0;

  ad_entrecomas(ptr2coma,cadena_aux,i);
	ntemp = strtod(cadena_aux, &ctemp);

	if ( *ctemp != '\0' && *ctemp != '\n'){
		return ST_ERR_FIX_INVALIDO;
	}
  fix->hdop = ntemp;
  return ST_OK;
}

status_t procesar_fix_elevacion (char **ptr2coma, struct fix_t *fix) {

  char cadena_aux[MAX_STR];	//cadena auxiliar
	char *ctemp;				//puntero a char temporal, para strtod
	double ntemp;				//double temporal
  size_t i = 0;

  cad_entrecomas(ptr2coma,cadena_aux,i);
	ntemp = strtod(cadena_aux, &ctemp);

	if ( *ctemp != '\0' && *ctemp != '\n'){
		return ST_ERR_FIX_INVALIDO;
	}
  fix->elevacion = ntemp;
  return ST_OK;
}

status_t procesar_fix_sep_geoide (char **ptr2coma, struct fix_t *fix) {

  char cadena_aux[MAX_STR];	//cadena auxiliar
	char *ctemp;				//puntero a char temporal, para strtod
	double ntemp;				//double temporal
  size_t i = 0;

  cad_entrecomas(ptr2coma,cadena_aux,i);
	ntemp = strtod(cadena_aux, &ctemp);

	if ( *ctemp != '\0' && *ctemp != '\n'){
		return ST_ERR_FIX_INVALIDO;
	}
	fix->sep_geoide = ntemp;
	return ST_OK;
}
