#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit-digit.h"



int main(int argc, char ** argv)
{
    if (argc < 3)
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

    digit e = digit_new_list_arr(x, argc - 1);
    
    digit d = digit_new_T(1);

    puts("d:");
    digit_list_print_hex(d);
    endl;
    puts("e:");
    digit_list_print_hex(e);
    endl;

    digit_set_add (d, e);
    
    puts("d+e:");

    digit_list_print_hex(d);
    endl;

    puts("e:");
    digit_list_print_hex(e);
    endl;
    
    return 0;
}
