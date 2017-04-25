#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"


void print (char * msg, struct digit * d);
void print_arr (T const * a, unsigned l);

int main(int argc, char ** argv)
{
    if (argc != 2) {
        puts("Usage: prog NUMBER\n");return 0;
    }

    char * input = argv[1];
    
    struct digit * d = digits_new_decimal_string( input );

    printf("d es %p", d);
    print ("d: ", d);
    
    
    return 0;
}

void print (char * msg, struct digit * d)
{
    puts (msg); digits_print_hex(d);
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
