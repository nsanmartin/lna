#include <stdio.h>
#include "../print.h"
#include "../digit.h"
//#include "../arit.h"

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
	puts("Usage: prog NUMBER\n");
	return 0;
    }

    unsigned long long xll = atoll(argv[1]);
    T x = (T) xll;

    printf ("Nro ingresado: %llx\n", x);

    digit d = digit_new_T (x);
    puts("Uso digit_print_hex:\n");
    digit_print_hex(d);
    endl;
    return 0;
}
