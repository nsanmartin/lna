#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <aux-tests.h>


int main(int argc, char ** argv)
{
  
    if (argc != 3) {
        puts("Usage: prog NUMBER NUMBER\n");return 0;
    }
    char const * fst  = strdup(argv[1]);
    char const * snd  = strdup(argv[2]);
    
    struct digit * d, * e, * lna_sum;
    mpz_t w, z, mpz_sum, mpz_diff;
    
    digits_init_set_decimal_string(&d, fst );
    digits_init_set_decimal_string(&e, snd );
    
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

    gmp_lna_cmp_ask (mpz_sum, lna_sum, 0);
    digits_print_hex(lna_sum);
}
