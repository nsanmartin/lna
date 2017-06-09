#include <stdio.h>
//#include <gmp.h>
#include <string.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <aux-tests.h>
#include <time.h>

//#define VERBOSE
#ifdef VERBOSE
#define tiempo_transcurrido(DESDE, HASTA, MSG)	\
    do { \
    /* Do the work. */ \
    HASTA = clock(); \
    printf (MSG"\t%f\n", ((double) (HASTA - DESDE)) / CLOCKS_PER_SEC); \
    DESDE = HASTA; \
    } while (0);
#else
#define tiempo_transcurrido(DESDE, HASTA, MSG)	;
#endif



int main(int argc, char ** argv)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    if (argc != 2) {
        puts("Usage: prog NUM (of digits)\n");return 0;
    }
    T ndigits, i;
    errno = 0;
    char * tail;
    ndigits = strtoul (argv[1], &tail, 10);
    if (errno) { puts("primer numero demasiado grande"); return 0; }
    #ifdef VERBOSE
    printf("digitos: %llu\n", ndigits);
    #endif
    
    FILE * urand = fopen("/dev/urandom", "r");

    unsigned char c;
    char * number_str = rnd_dec_str (ndigits);
    fclose(urand);

    tiempo_transcurrido (start, end, "Ya tengo el nro.");
    
    struct digit * d, * copia;
    
    digits_init_set_decimal_string___(&d, number_str );
    free (number_str);
    tiempo_transcurrido (start, end, "Ya tendo en lni.");
    
    /*
    **
    **    Copio:
    **
    */

    digits_copy (&copia, d);
    tiempo_transcurrido (start, end, "Ya tengo la copia.");

    
    char * s, *t; 
    s = digits_get_str_hex (d);


    tiempo_transcurrido(start, end, "Ya tengo un hex.");


    
    t = digits_get_str_hex (copia);

    tiempo_transcurrido(start, end, "Ya tengo el otro hex.");

    int comparacion =  strcmp(s,t) != 0;

    tiempo_transcurrido(start, end, "Ya compare los strings");
    if (comparacion){
      puts("error en copy");
      puts(s);puts(t);
      exit(1);
    } else
      puts("ok");
    

}




