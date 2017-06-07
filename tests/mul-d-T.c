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

    
    T * x;
    errno = 0;
    char * tail;
    x = strtoul (argv[2], &tail, 10);
    if (errno) { puts("segundo numero demasiado grande"); return 0; }

    char const * fst  = strdup(argv[1]);
    struct digit * d, * lna_mul;
    digits_init_set_decimal_string(&d, fst );
    
    mpz_t z, mpz_sum;
    mpz_init_set_str (z, fst, 10);

    /*
    **
    **    mul:
    **
    */

    lna_mul = digits_set_mul_ui (d, x);
    mpz_mul_ui (z, z, x);
    
    
    
    return 0;
}
