#include <stdio.h>
#include <gmp.h>
#include <errno.h>
#include <string.h>

#include "../print.h"
#include "../digit.h"
#include "../arit.h"

/* compilar con:
 * gcc ../digit/*.c test-new.c -o test-new -lgmp -lm
 *
 */


int main(int argc, char ** argv)
{
    if (argc != 2) { puts("Usage: prog NUMBER\n"); return 0; }

    T x;
    errno = 0;
    char * tail;
    x = strtoul (argv[1], &tail, 10);
    if (errno) { puts("Numero demasiado grande"); return 0; }

    struct digit * p;
    p = digits_new (x);
    char * s = digits_get_str_hex (p);


    mpz_t mpz;
    mpz_init_set_ui ( mpz, x );
    char * t = mpz_get_str (NULL, 16, mpz);

    
    if (strcmp(s, t))  {
        puts ("error");
        exit(1);
    } else {
        puts("ok");
    }

    return 0;
}
