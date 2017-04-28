#include "../arit.h"
#include <stdio.h>

#define nth_bit(word, n) 1 & ((word) >> (n))
// testear con 15 * 15
void multiplicador (T const x,T const y, T * left, T * right)
{
    if (!x || !y) {
	* left = * right = 0;
	return;
    }
    T suma, carry;
    * left = 0;
    * right = 1 & y ? x : 0;
    T n = 1;
//    printf("lf 0:\t 0\trg 0:\t %x\tacu %x\n", *right,*right );
    while (y >> n && n < BITS_OF_T) {
	
	sumador (* right, nth_bit(y, n) ? x << n : 0, 0, &suma, &carry);
	
	* left += nth_bit(y, n) 
	    ?  x >> (BITS_OF_T - n) 
	    : 0;

	* left += carry;
	* right = suma;

	/* printf("lf %d:\t %x\t",n, (x >> (BITS_OF_T - n)) ); */
	/* printf("rg %d:\t %x\tacu r: %x\n",n, (x << n), *right ); */

//	printf("rigth in bit %d: %x\n", n, (*right- suma) & 15);


	n++;
    }
    /* if ( x * y != * right) { */
    /* 	fprintf (stderr, "error en multiplicador?.\nx * y ==  '%x' pero *right == '%x'\n", */
    /* 		 x * y, * right); */
    /* 	exit(1); */
    /* } */
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
