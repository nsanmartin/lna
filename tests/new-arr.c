#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"
#include <errno.h>
#include <gmp.h>
#include "tests.h"

int main(int argc, char ** argv)
{
    if (argc == 1)
    {
        puts("Usage: prog NUMBER [NUMBER ...] . NUMBER\n");
        return 0;
    }
    
    T * x =  malloc (sizeof(T) * (argc - 2));
    T y;
    char * tail;
    errno = 0;
    int i;
    int dot = 0;
    char * p;
    for (i = 1; i < argc; i++) {
        if (*argv[i] == '.') {
            dot = i; 
            if (dot + 1 == argc) { 
                puts("falto un nro");
                return 0;
            }
            
            y = strtoul (argv [ dot + 1 ], &tail, 10);
            if (errno) { puts("Numero demasiado grande"); return 0; }

            break;
        }
        p = argv [i];
        while (*p) {
          if (!isdigit(*p)) {
            printf("error en parametro: `%s'.\n", argv[i]);
            exit(1);
          }
          p++;
        }
        x[i-1] = strtoul (argv[i], &tail, 10);        
        if (errno) { puts("Numero demasiado grande"); return 0; }
    }


    
    struct digit * d;// = digits_new_array(x, dot - 1);
    digits_init_array (&d, x, dot-1);

    mpz_t z;
    gmp_from_arr (z, x, dot - 1);

    char * s = digits_get_str_hex (d);
    printf ("lna: %s\n", s);
    digits_print_hex(d);

    gmp_printf ("gmp: %Zx\n", z);

    return 0;
}
