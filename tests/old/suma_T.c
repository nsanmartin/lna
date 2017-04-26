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
    if (argc != 2) {
        puts("Usage: prog NUMBER\n");return 0;
    }


    
    struct digit * x = digits_new_decimal_string( argv[1] );
    puts("");
    digits_incr(x);
    digits_print_hex( x );
    mpz_t a;
    mpz_init_set_str (a, argv[1], 10);

    mpz_add_ui (a, a, 1);		
    
    gmp_printf ("%#Zx", a); 
    
      
    
    return 0;
}
