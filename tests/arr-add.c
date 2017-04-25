#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"

int main(int argc, char ** argv)
{
    if (argc == 1)
    {
        puts("Usage: prog NUMBER [NUMBER ...]\n");
        return 0;
    }
    
    T * x =  malloc (sizeof(T) * (argc - 1));
    int i;
    int coma = 0;
    for (i = 0; i < argc - 1; i++) {
        if (*argv[i+1] == '.') {
            coma = i+1;
            x [i] = ~0;
            continue;
        }
        x[i] = atoll(argv[i+1]);
    }

    struct digit * d = digits_new_array(x, coma - 1);
    struct digit * e = digits_new_array(x + coma, argc - 1 - coma);

    puts ("\tlna\n\t===");
    digits_print_hex(d);
    digits_print_hex(e);

    struct digit * sum = digits_add (d, e);
    digits_print_hex(sum);
    return 0;
}


void print_arr (T const * a, unsigned l)
{
   
    unsigned i = 0;
    while (i < l) {
        if (i == 0)
            puts("En print_arr:");
        else
            printf(", ");
        printf("%llx", a[i]);
        i++;
    }
    puts("");
}
