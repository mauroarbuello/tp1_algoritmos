//CHECKSUM
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fix.h"

unsigned char nmea_checksum ( const char * sentence ){
	unsigned char sum = 0;

	while (* sentence )
	sum ^= * sentence ++;
	return sum;
}

bool verify_checksum(const char* str_origen){

	char str_aux[MAX_STR];	//aca voy a guardar la cadena sin el $ y sin los valores del checksum
	size_t i;				//variable de iteración
	char* temp;
	unsigned char char_temp;
	unsigned long int num_temp;

	for( i=0; *(str_origen+i+1) != '*' && *(str_origen+i+1) != '\0'; i++){
		str_aux[i] = *(str_origen+i+1);
	}

	str_aux[i+1]= '\0';
	char_temp = nmea_checksum(str_aux);
	num_temp = strtoul((str_origen+i+2),&temp, 16);
	
	if (*temp != '\0' || *temp != '\n' )
		return false;
	
	if (char_temp == num_temp)
		return true;

	return false;

}
