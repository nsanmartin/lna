#include <stdio.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <errno.h>
#include <gmp.h>
#include <aux-tests.h>

int main(int argc, char ** argv)
{
    if (argc != 3)
    {
        puts("Usage: prog NUMBER:lni NUMBER:T\n");
        return 0;
    }

    
    T  x;
    errno = 0;
    char * tail;
    x = (T)strtoul (argv[2], &tail, 10);
    if (errno) { puts("segundo numero demasiado grande"); return 0; }

    char const * fst  = strdup(argv[1]);
    struct digit * d, * lna_mul;
    digits_init_set_decimal_string(&d, fst );
    
    mpz_t z, mpz_sum;
    mpz_init_set_str (z, fst, 10);

    /*
    **
    **   div:
    **
    */
    puts("la cuenta");
    digits_set_div_ui (d, x);
    mpz_div_ui (z, z, x);
    
    gmp_lna_cmp (z, d);
    
    
    return 0;
}
