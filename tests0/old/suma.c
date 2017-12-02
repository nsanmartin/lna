#include <stdio.h>
#include <gmp.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"
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

    struct digit * x = digits_new_decimal_string( argv[1] );
    struct digit * y = digits_new_decimal_string( argv[2] );
    struct digit * suma = digits_add (x, y);

    digits_print_hex (suma);

    mpz_t a, b;
    mpz_init_set_str (a, argv[1], 10);
    mpz_init_set_str (b, argv[2], 10);
    mpz_add (a, a, b);		

    gmp_printf ("%#Zx", a); 
    
      
    
    return 0;
}
