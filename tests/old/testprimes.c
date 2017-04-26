#include <stdio.h>
#include "../print.h"
#include "../digit-lnn.h"
#include "../arit.h"
#include "../primes.h"

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
    	puts("Usage: primes NUMBER\n");
    	return 0;
    }


    unsigned long long xll = atoll(argv[1]);
    T x = (T) xll;

    lnn_t n = ln_primes_factors_T (x);
    lnn_print_digits_list_dec(n);
    endl;
    return 0;
}

