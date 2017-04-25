#include "../arit.h"
#include <stdio.h>

void multiplicador (const T x, const T y, T * lbits, T * rbits)
{
    *lbits = *rbits = 0;
    if ( !x || !y )
        return;
    else if (1 & y)
        *rbits = x;
    unsigned dnum = 1;
    while ( y >> dnum && dnum < BITS_OF_T)
    {
          if ( 1 & ( y >> dnum) )
          {
              *rbits += x << dnum ;
              *lbits += x >> (BITS_OF_T - dnum);
          }
          dnum++;
    }
}

void digits_set_mul_T (struct digit * ds, T const x)
{
    T lb, rb;
    T mulcarry = 0; T addcarry;
    T num;
    struct digit * prev;
    for ( ; ds ; ds = ds -> next)
    {
        multiplicador (ds -> num, x, &lb, &rb);
        sumador (mulcarry, rb, 0, &num, &addcarry);
        if (addcarry) {
            fprintf(stderr, "error en digit_set_mul_t, revisarla\n");
            exit(1);
        }
        mulcarry = lb;
        ds -> num = num;
        prev = ds;
    }
    if (mulcarry) {
        prev -> next = digits_new (mulcarry);
        prev -> next -> prev = prev;
    }
}
