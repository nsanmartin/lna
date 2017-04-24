#include <stdio.h>

typedef unsigned long long T;
void large_mul (T x, T y, T * lbits, T * rbits);

int main(int argc, char ** argv)
{
    if (argc != 3)
    {
        puts("Usage: prog NUMBER NUMBER\n");
        return 0;
    }
    T x = atoll( argv[1] );
    T y = atoll( argv[2] );
    large_mul (x, y, l, r);
    printf ("%ull * $ull = %ull , %ull\n", x, y, l, r);
    return 0;
}

void large_mul (T x, T y, T * lbits, T * rbits)
{
    lbits = rbits = 0;
    unsigned dnum = 0;
    while ( y ) {
        if ( 1 & ( y >> dnum) ) {
            rbits += x << dnum ;
            lbits += x >> (BITS_IN_T - dnum);
        }
        dnum++;
    }
    
}
