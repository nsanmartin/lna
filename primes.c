#include "primes.h"
#include <stdio.h>
lnn_t * ln_primes_factors_T (T x)
{
    T i = 2;
    lnn_t * r = lnn_new_T ( (T) 1 );
    lnn_t * res = r;
    while ( i <= x )
    {
	if ( i * i > x) {
	    r -> num = x;
	    break;
	}

	while ( x % i == 0 )
	{
	    r -> num *= i;
	    x /= i;
	}
	if (x != 1 && r -> num != 1) {
	    r -> next = lnn_new_T ( (T) 1);
	    r = r -> next;
	}
	i++;
    }
    return res;
}
