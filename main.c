#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fix.h>

bool procesar_argv(int argc, char *argv[], struct fix_t *fix);
void get_fechaactual(struct fecha_t *fecha);
					
int main(int argc, char* argv[]){
	
	struct fix_t fixactual;
	
	get_fechaactual(&(fixactual.fecha));
	
	procesar_argv(argc,argv,&fixactual);
	
}
