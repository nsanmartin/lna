#include <stdio.h>
//#include <gmp.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <errno.h>
/* compilar con:
 * gcc ../digit/*.c add-TT.c -o addtt.out -lgmp -lm -I..
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
    digits_set_add_T (p, y);
    digits_print_hex(p);
    
    return 0;
}
