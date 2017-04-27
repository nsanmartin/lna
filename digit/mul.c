#include "../arit.h"
#include <stdio.h>

void multiplicador (T const x,T const y, T * lbits, T * rbits)
{
    *rbits = x * y;
    *lbits = (T)0;

    T rb, suma, carry, carry_total;
    carry_total = 0;
    if ( !x || !y )
        return;

    struct digits * rb = digits_new (y & 1 ? x : 0);

    for (int i = 1; i < BITS_OF_T; i++) {
        if ( 1 & (y >> i) ) {
            (*lbits) += x >> BITS_OF_T - i;
            digits_set_add (rb, x << i);
        }
     }
    *lbits = suma;
        
}




void multiplicador__ (const T x, const T y, T * lbits, T * rbits)
{
  *lbits = *rbits = (T)0;
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
