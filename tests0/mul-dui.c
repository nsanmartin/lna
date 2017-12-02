#include <stdio.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <errno.h>
#include <gmp.h>
#include <aux-tests.h>
#include <time.h>

int verbose = 1;
int main(int argc, char ** argv)
{
  srand (time (0));
    if (argc != 2)
    {
        puts("Usage: prog NUMBER (max digits dec)\n");
        return 0;
    }

    
    T  x, ndigs;
    errno = 0;
    char * tail;
    ndigs = strtoul (argv[1], &tail, 10);
    if (errno) { puts("numero demasiado grande"); return 0; }

    T size = rand() % ndigs;
    char const * fst  = rnd_dec_str(size);

    struct digit * d, * lna_mul;
    digits_init_set_decimal_string(&d, fst );
    
    mpz_t z, mpz_sum;
    mpz_init_set_str (z, fst, 10);

    /*
    **
    **    mul:
    **
    */
    x = rand();
    if (verbose) {
      printf ("x: %llu\t", x);
      printf ("d size: %llu\n", size);
    }
    digits_set_mul_ui (d, x);
    mpz_mul_ui (z, z, x);
    
    gmp_lna_cmp (z, d);

    
    return 0;
}
