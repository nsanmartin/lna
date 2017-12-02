#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"
#include <errno.h>
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
        x[i-1] = strtoul (argv[i], &tail, 10);        
        if (errno) { puts("Numero demasiado grande"); return 0; }
    }


    
    struct digit * d = digits_new_array(x, dot - 1);
    struct digit * e = digits_new (y);
    struct digit * sum = digits_add (d, e);
    digits_set_add_T (d, y);
    digits_print_hex(sum);
    digits_print_hex(d);

    return 0;
}
