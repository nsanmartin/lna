#include "../arit.h"
#include <stdio.h>

#define nth_bit(word, n) 1 & ((word) >> (n))

void multiplicador (T const x,T const y, T * left, T * right)
{
    if (!x || !y) {
	* left = * right = 0; return;
    }
    T suma, carry;
    * left = 0;
    * right = 1 & y ? x : 0;
    T n = 1;

    while (y >> n && n < BITS_OF_T) {
	sumador (* right, nth_bit(y, n) ? x << n : 0, 0, &suma, &carry);
	* left += nth_bit(y, n) ?
          x >> (BITS_OF_T - n)  :
          0;
	* left += carry;
	* right = suma;
	n++;
    }
}

void digits_set_mul_T (struct digit * ds, T const x)
{
    T lb, rb;
    T mulcarry = 0; T addcarry;
    T sum;
    struct digit * prev;
    for ( ; ds ; ds = ds -> next)
    {
        multiplicador (ds -> num, x, &lb, &rb);
        sumador (mulcarry, rb, 0, &sum, &addcarry);
        
        ds -> num = sum;


        mulcarry = lb;

        if (addcarry) {
            fprintf(stderr, "error en digit_set_mul_t, revisarla\n");
            exit(1);
        }
        prev = ds;
    }

    if (mulcarry) {
        prev -> next = digits_new (mulcarry);
        prev -> next -> prev = prev;
    }
}
