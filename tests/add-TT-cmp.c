#include <stdio.h>
#include <gmp.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"
#include <errno.h>
#include "tests.h"

/* compilar con:
 * gcc ../digit/*.c suma.c -o suma -lgmp -lm
 *
 */


int main(int argc, char ** argv)
{
    if (argc != 3) { puts("Usage: prog NUMBER NUMBER\n"); return 0; }

    T x, y;
    errno = 0;
    char * tail;
    x = strtoul (argv[1], &tail, 10);
    if (errno) { puts("primer numero demasiado grande"); return 0; }
    y = strtoul (argv[2], &tail, 10);
    if (errno) { puts("segundo numero demasiado grande"); return 0; }


    struct digit * p;
    p = digits_new (x);

    /*
    ** testing:
    **    digits_set_add_T
    **     |
    **     V
    */
    
    digits_set_add_T (p, y);


    mpz_t z;
    mpz_init_set_ui (z, x);
    mpz_add_ui (z,z, y);
    gmp_lna_cmp (z, p);
    
    return 0;
}
