#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit-digit.h"


void print_arr (T const * a, unsigned l);

int main(int argc, char ** argv)
{
    if (argc == 1)
    {
        puts("Usage: prog NUMBER [NUMBER ...]\n");
        return 0;
    }

    T * x =  malloc (sizeof(T) * (argc - 1));

    int i;
    printf("argc: %d\n",argc);

    for (i = 0; i < argc - 1; i++) {
        x[i] = atoll(argv[i+1]);
    }


    struct digit * d = digits_new_list_arr(x, argc - 1);
    print_arr(x, argc - 1);
    puts("\nUso digit_list_print_hex:");
    digits_print_hex(d);
    struct digit * e;
    T len = digits_copy (&e, d);
    digits_clear(&d);
    digits_print_hex(e);
    printf("len = %llu\n", len);

    digits_incr(e);
    digits_print_hex(e);
    digits_decr(e);
    digits_print_hex(e);
    puts("sumandos:");
    struct digit * n = digits_new (2);
    digits_print_hex(e);
    digits_print_hex(n);
    puts("--------");
    struct digit * suma = digits_add (e, n);
    digits_print_hex(suma);
    
    
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
