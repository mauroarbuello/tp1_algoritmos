CC=gcc
CFLAGS=-std=c99 -Wall -Wpedantic -o3
all: nmeatogpx.exe clean

nmeatogpx.exe: main_def.o proc_argv_def.o procesar_fix_largo.o print_help_def.o print_salida_def.o search_coma_def.o checksum_def.o chk_gga_def.o errores_def.o get_currentdate_def.o
	$(CC) $(CFLAGS) -o nmeatogpx.exe main_def.o proc_argv_def.o procesar_fix_largo.o print_help_def.o print_salida_def.o search_coma_def.o checksum_def.o chk_gga_def.o errores_def.o get_currentdate_def.o
	
main_def.o: main_def.c fix.h
	$(CC) $(CFLAGS) -o main_def.o -c main_def.c
	
procesar_fix_largo.o: procesar_fix_largo.c fix.h
	$(CC) $(CFLAGS) -o procesar_fix_largo.o -c procesar_fix_largo.c

proc_argv_def.o: proc_argv_def.c fix.h
	$(CC) $(CFLAGS) -o proc_argv_def.o -c proc_argv_def.c

print_help_def.o: print_help_def.c fix.h
	$(CC) $(CFLAGS) -o print_help_def.o -c print_help_def.c

print_salida_def.o: print_salida_def.c fix.h
	$(CC) $(CFLAGS) -o print_salida_def.o -c print_salida_def.c
	
search_coma_def.o: search_coma_def.c fix.h
	$(CC) $(CFLAGS) -o search_coma_def.o -c search_coma_def.c
	
checksum_def.o: checksum_def.c fix.h
	$(CC) $(CFLAGS) -o checksum_def.o -c checksum_def.c
	
chk_gga_def.o: chk_gga_def.c fix.h
	$(CC) $(CFLAGS) -o chk_gga_def.o -c chk_gga_def.c
	
errores_def.o: errores_def.c fix.h
	$(CC) $(CFLAGS) -o errores_def.o -c errores_def.c

get_currentdate_def.o: get_currentdate_def.c fix.h
	$(CC) $(CFLAGS) -o get_currentdate_def.o -c get_currentdate_def.c

clean:
	rm -v *.o