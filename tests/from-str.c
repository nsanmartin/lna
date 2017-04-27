#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"

/* compilar con:
 * gcc ../digit/*.c from-str.c -o from-str -lgmp -lm
 *
 */


int main(int argc, char ** argv)
{
    if (argc != 2) {
        puts("Usage: prog NUMBER\n");return 0;
    }

    char const * input = argv[1];
    char *s, *t;
    struct digit * d;
    mpz_t m;
    
    int i = digits_init_set_decimal_string(&d, input );
    int j = mpz_init_set_str (m, input, 10);

    printf ("`%s'\ni: %d, j:%d\n", input, i, j);

    puts("(en test begin) d:");
    digits_print_hex (d );
    puts("(en test end)");
    
    
    s = digits_get_str_hex (d);
    t = mpz_get_str (NULL, 16, m);
    printf("lna:%s\n", s);
    printf("gmp:%s\n", t);
    
    if ( strcmp ( s, t ) == 0 || i==j && i)
      puts ("ok");
    else
      puts ("error");
      
    
    return 0;
}
