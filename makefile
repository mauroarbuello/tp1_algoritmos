# Fichero: makefile
# Fichero makefile para la construccion del ejecutable "programa". 

nmeatogpx: main_def.o proc_argv_def.o procesar_fix_largo.o print_help_def.o print_salida_def.o search_coma_def.o checksum_def.o chk_gga_def.o errores_def.o get_currentdate_def.o
	
	gcc -Wall -Wpedantic -std=c99 -o nmeatogpx main_def.o proc_argv_def.o procesar_fix_largo.o print_help_def.o print_salida_def.o search_coma_def.o checksum_def.o chk_gga_def.o errores_def.o get_currentdate_def.o
	
procesar_fix_largo.o: procesar_fix_largo.c get_currentdate_def.o
	gcc -Wall -Wpedantic -std=c99 -o procesar_fix_largo.o procesar_fix_largo.c get_currentdate_def.o

proc_argv_def.o: proc_argv_def.c get_currentdate_def.o
	gcc -Wall -Wpedantic -std=c99 -o proc_argv_def.o proc_argv_def.c get_currentdate_def.o

print_help_def.o: print_help_def.c
    gcc -Wall -Wpedantic -std=c99 -o print_help_def.o print_help_def.c

print_salida_def.o: print_salida_def.c
    gcc -Wall -Wpedantic -std=c99 -o print_salida_def.o print_salida_def.c
	
search_coma_def.o: search_coma_def.c
	gcc -Wall -Wpedantic -std=c99 -o search_coma_def.o search_coma_def.c
	
checksum_def.o: checksum_def.c
	gcc -Wall -Wpedantic -std=c99 -o checksum_def.o checksum_def.c
	
chk_gga_def.o: chk_gga_def.c
	gcc -Wall -Wpedantic -std=c99 -o chk_gga_def.o chk_gga_def.c
	
errores_def.o: errores_def.c
	gcc -Wall -Wpedantic -std=c99 -o errores_def.o errores_def.c

get_currentdate_def.o: get_currentdate_def.c
	gcc -Wall -Wpedantic -std=c99 -o get_currentdate_def.o get_currentdate_def.c

	
