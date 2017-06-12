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
  //  puts("empiezo");
    srand (time (0));
    if (argc != 2) {
        puts("Usage: prog NUMBER (max digits)\n");return 0;
    }

    errno = 0;
    char * tail;
    T ndigits = strtoul (argv[1], &tail, 10);
    if (errno) { puts("input numero demasiado grande"); return 0; }

    if (verbose)
      puts("leido el parametro");
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
    if (verbose)
      printf("fst:\n%s\nsnd:\n%s\n", fst, snd);
    
    digits_init_set_decimal_string(&d, fst );
    digits_init_set_decimal_string(&e, snd );


    if (verbose)
      puts("inicializados los digits");
    mpz_init_set_str (w, fst, 10);
    mpz_init_set_str (z, snd, 10);

    mpz_init ( mpz_mul_res );
    mpz_init ( mpz_diff );

    if (verbose)
      puts("inicializados los gmp");



    /*
    **
    **    Multiplico:
    **
    */

    lna_mul = digits_mul (d, e);

    if (verbose)
      puts("hecha la cuenta en lna");  
    mpz_mul (mpz_mul_res, w,z);
    if (verbose)
      puts("hecha la cuenta en gmp");

    gmp_lna_cmp (mpz_mul_res, lna_mul);
    if (verbose)
      puts("ya compare\nfin.\n");
}
