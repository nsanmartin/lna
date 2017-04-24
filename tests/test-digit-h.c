#include <stdio.h>
#include "../print.h"
#include "../digit.h"
//#include "../arit.h"
#define len(A) (sizeof(A)/sizeof(*(A)))

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


    struct digit * d = digit_new_list_arr(x, argc - 1);
    print_arr(x, argc - 1);
    puts("\nUso digit_list_print_hex:");
    digit_list_print_hex(d);
    struct digit * e;
    T len = digit_list_copy (&e, d);
    digit_list_clear(&d);
    digit_list_print_hex(e);
    printf("len = %llu\n", len);
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
