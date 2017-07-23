#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <aux-tests.h>
#include <time.h>
#include <unistd.h>

#define VERBOSE
#ifdef VERBOSE
#define tiempo_transcurrido(MSG)                \
    do { \
    end = clock(); \
    printf (MSG"\t%fs\n", ((double) (end - start)) / CLOCKS_PER_SEC); \
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

    
    char const * fst  = rnd_dec_str(ndigits);
    char const * snd  = rnd_dec_str(ndigits);
    tiempo_transcurrido("tengo los nros");
    char *s, *t;
    struct digit * d, * e, * lna_sum;
    mpz_t w, z, mpz_sum, mpz_diff, cpy_lna;
    /* FILE * urand =  fopen ("/dev/urand", "r"); */

    /* d = digits_rnd (urand, ndigits); */
    /* e = digits_rnd (urand, ndigits); */
    /* fclose(urand); */
		    
    digits_init_set_decimal_string(&d, fst );
    digits_init_set_decimal_string(&e, snd );
    tiempo_transcurrido("inicialce los digits");
    
    mpz_init_set_str (w, fst, 10);
    mpz_init_set_str (z, snd, 10);
    tiempo_transcurrido("inicialce los gmp");
    
    mpz_init ( mpz_sum );
    mpz_init ( mpz_diff );



    /*
    **
    **    Sumo:
    **
    */

    lna_sum = digits_add (d, e);
    digits_clear (&d);
    digits_clear (&e);
    tiempo_transcurrido("sume digits");
    mpz_add (mpz_sum,w,z);
    tiempo_transcurrido("sume gmp");


    gmp_lna_cmp (mpz_sum, lna_sum);
}

