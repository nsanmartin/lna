#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"
#include "aux-tests.h"
/* compilar con:
 * gcc ../digit/*.c from-str.c -o from-str -lgmp -lm
 *
 */


int main(int argc, char ** argv)
{
    if (argc != 2) {
        puts("Usage: prog NUMBER\n");return 0;
    }

    char const * input = strdup(argv[1]);
    char *s, *t;
    struct digit * d;
    mpz_t m;
    
    int i = digits_init_set_decimal_string(&d, input );
    int j = mpz_init_set_str (m, input, 10);

    
    printf("input len: %lu\t", strlen(input));

    gmp_lna_cmp (m, d);
    
    if (i != j) {
      fprintf (stderr, "error i != j\n"); exit(1);
    }

}
