#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"


void print (char * msg, struct digit * d);
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


    struct digit * d = digits_new_array(x, argc - 1);

    struct digit * e;
    T len = digits_copy (&e, d);

    printf("d es %p", e);
    print ("d: ", e);

    digits_set_mul_T (e, 16);
    print ("e * 16: ", e);
    
    
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
