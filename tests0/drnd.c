#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <aux-tests.h>
#include <time.h>

#define VERBOSE
#ifdef VERBOSE
#define tiempo_transcurrido(MSG)	\
    do { \
    end = clock(); \
    fprintf (stderr,MSG"\t%f\n", ((double) (end - start)) / CLOCKS_PER_SEC); \
    start = end; \
    } while (0);
#else
#define tiempo_transcurrido(MSG)	;
#endif

int main(int argc, char ** argv)
{

  if (argc != 2) {
        puts("Usage: prog NUMBER (max of digits)\n");return 0;
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    errno = 0;
    char * tail;
    T ndigits = strtoul (argv[1], &tail, 10);
    if (errno) { puts("primer numero demasiado grande"); return 0; }
#ifdef VERBOSE
    printf("digitos: %llu\n", ndigits);
#endif
    tiempo_transcurrido ("empiezo:");
    struct digit * d;
    FILE * urand = fopen("/dev/urandom", "r");
    d = digits_rnd (urand, ndigits);
    fclose(urand);
    tiempo_transcurrido ("tengo el nro");
    digits_print_hex(d);
    tiempo_transcurrido("falta borrar");
    digits_clear(&d);
    tiempo_transcurrido("fin");
}
