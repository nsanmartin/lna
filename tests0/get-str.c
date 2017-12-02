#include <stdio.h>
//#include <gmp.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"
#include <errno.h>
/* compilar con:
 * gcc ../digit/*.c suma.c -o suma -lgmp -lm
 *
 */


int main(int argc, char ** argv)
{
    if (argc != 2) { puts("Usage: prog NUMBER\n"); return 0; }

    T x, y;
    errno = 0;
    char * tail;
    x = strtoul (argv[1], &tail, 10);
    if (errno) { puts("Numero demasiado grande"); return 0; }

    struct digit * p;
    p = digits_new (x);
    char * s = digits_get_str_hex (p);
    puts(s);
    
    return 0;
}
