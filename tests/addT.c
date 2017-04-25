#include <stdio.h>
#include <gmp.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"
#include <errno.h>
/* compilar con:
 * gcc ../digit/*.c suma.c -o suma -lgmp -lm
 *
 */

void print (char * msg, struct digit * d);

int main(int argc, char ** argv)
{
    if (argc != 3) {
        puts("Usage: prog NUMBER\n");return 0;
    }
    puts("digits_set_add_T:");

    errno = 0;
    char * tail;
    T p = strtoul (argv[2], &tail, 10);

    if (errno) {
        puts("segundo numero demasiado grande\n");
        return 0;
    }

    mpz_t a;
    mpz_init_set_str (a, argv[1], 10);


    mpz_add_ui (a, a, p);
    gmp_printf ("gmp: %#Zx\n", a); 
    
      
    struct digit * x = digits_new_decimal_string( argv[1] );
    digits_set_add_T (x, p);

    printf ("lna: ");
    digits_print_hex (x);
    
    return 0;
}
