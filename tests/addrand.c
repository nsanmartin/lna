#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <aux-tests.h>
#include <time.h>

//#define VERBOSE
#ifdef VERBOSE
#define tiempo_transcurrido(MSG)	\
    do { \
    /* Do the work. */ \
    end = clock(); \
    printf (MSG"\t%f\n", ((double) (end - start)) / CLOCKS_PER_SEC); \
    start = end; \
    } while (0);
#else
#define tiempo_transcurrido(MSG)	;
#endif

int main(int argc, char ** argv)
{

  puts("Este test no esta implementado.");
  exit(1);
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

    
    char const * fst  = rnd_dec_str(ndigits);
    char const * snd  = rnd_dec_str(ndigits);
    tiempo_transcurrido("tengo los nros");
    char *s, *t;
    struct digit * d, * e, * lna_sum;
    mpz_t w, z, mpz_sum, mpz_diff, cpy_lna;
    FILE * urand =  fopen ("/dev/urand", "r");

    d = digits_rnd (urand, ndigits);
    e = digits_rnd (urand, ndigits);
    fclose(urand);
		    
    /* digits_init_set_decimal_string(&d, fst ); */
    /* digits_init_set_decimal_string(&e, snd ); */
    tiempo_transcurrido("los inicializo");

    
    mpz_init_set_str (w, fst, 10);
    mpz_init_set_str (z, snd, 10);
    mpz_init ( mpz_sum );
    mpz_init ( mpz_diff );



    /*
    **
    **    Sumo:
    **
    */

    lna_sum = digits_add (d, e);
    mpz_add (mpz_sum,w,z);

    /* mpz_init_set_str ( cpy_lna, */
    /*                    digits_get_str_hex(lna_sum), */
    /*                    16); */

    /* mpz_sub (mpz_diff, mpz_sum, cpy_lna); */
    /* gmp_printf ("diff: %Zx\n", mpz_diff); */

    gmp_lna_cmp (mpz_sum, lna_sum);
}