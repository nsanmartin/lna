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

int is_prime_T (T x)
{
    T i = 2;
    while ( i * i <= x )
    {
	if ( x % i == 0)
	    return 0;
	i++;
    }
    return 1;
}

/* lnn_t  * lnn_min_divisor (lnn_t * n) */
/* { */
/*     lnn_t * i = lnn_new_T ( 2 ); */
/*     while ( 1 ) */
/*     { */
/* 	lnn_t * tmp = lnn_mul (i, i); */
/* 	if ( lnn_minor( n, i ) ) */
/* 	    break; */
/* 	else if ( */
/*     } */
/* } */
