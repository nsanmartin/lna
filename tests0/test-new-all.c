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


    T x, anterior;
    x = ~0;

    T const by =  1;//256L * 256L * 256L;
    T const cada = 1;//256L * 256L * 256L
    struct digit * p;
    char * s, * t;
    mpz_t mpz;

    //x + by < ~0 - by
    
    while( x > 0 ) {
        p = digits_new (x);
        s = digits_get_str_hex (p);

        mpz_init_set_ui ( mpz, x );
        t = mpz_get_str (NULL, 16, mpz);
        
        if (strcmp(s, t))  { puts ("error"); exit(1); }
        if (x % cada == 0) {
            printf("ok %x.\t ", x);
        }
        digits_clear(&p);
        mpz_clear(mpz);

        x--;

    }
    printf("x:%x, ant %x", x, anterior);

    puts("Todos los valores ok");
    return 0;
}
