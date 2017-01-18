#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"
#include "../primes.h"

T factorial_T (T x);

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
	puts("Usage: is_prime NUMBER\n");
	return 0;
    }

    unsigned long long xll = atoll(argv[1]);
    T x = (T) xll;
            
    if ( is_prime_T ( x ) )
      puts("es primo nomas");
    else
      puts("es divisible");
    return 0;
}

T factorial_T (T x)
{
    T res = 1;
    while (x)  res *= x--;
    return res;
}
