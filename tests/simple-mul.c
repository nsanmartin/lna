#include <stdio.h>
#include "../digit.h"
#include "../print.h"
void large_mul (const T x, const T y, T * lbits, T * rbits);

int main(int argc, char ** argv)
{
    /* T test = 1; */
    /* T test2 = 1L >> 64; */
    /* printf ("test: %llx\ntest2: %llx", test, test2 ); */
    if (argc != 3)
    {
        puts("Usage: prog NUMBER NUMBER\n");
        return 0;
    }
    T x = atoll( argv[1] );
    T y = atoll( argv[2] );

    T l, r;
    //large_mul (x, y, &l, &r);
    r = x * y;
    printf ("%llu * %llu = %llu\n", x, y,  r);

    return 0;
}

void large_mul (const T x, const T y, T * lbits, T * rbits)
{
    *lbits = *rbits = 0;
    if ( !x || !y )
        return;
    *rbits = x;
    unsigned dnum = 1;
    while ( dnum < BITS_OF_T) {
        if ( 1 & ( y >> dnum) ) {
            *rbits += x << dnum ;
            *lbits += x >> (BITS_OF_T - dnum);
        }
        dnum++;
    }
    
}
