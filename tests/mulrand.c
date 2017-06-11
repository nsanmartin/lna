#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <aux-tests.h>
#include <time.h>

int verbose = 1;

int main(int argc, char ** argv)
{
    srand (time (0));
    if (argc != 2) {
        puts("Usage: prog NUMBER (max digits)\n");return 0;
    }

    errno = 0;
    char * tail;
    T ndigits = strtoul (argv[1], &tail, 10);
    if (errno) { puts("input numero demasiado grande"); return 0; }
    
    char *s, *t;
    struct digit * d, * e, * lna_mul;
    mpz_t w, z, mpz_mul_res, mpz_diff, cpy_lna;

    
    T size1 = rand() % ndigits;
    T size2 = rand() % ndigits;
    if(verbose) {
        printf("ndigits: %llu\t",ndigits);
        printf("digitos decimales: %llu, %llu\n", size1, size2);
    }
    char const * fst  = rnd_dec_str(size1);
    char const * snd  = rnd_dec_str(size2);

    digits_init_set_decimal_string(&d, fst );
    digits_init_set_decimal_string(&e, snd );
    
    mpz_init_set_str (w, fst, 10);
    mpz_init_set_str (z, snd, 10);
    mpz_init ( mpz_mul_res );
    mpz_init ( mpz_diff );



    /*
    **
    **    Multiplico:
    **
    */

    lna_mul = digits_mul (d, e);
    mpz_mul (mpz_mul_res, w,z);

    gmp_lna_cmp (mpz_mul_res, lna_mul);
}
