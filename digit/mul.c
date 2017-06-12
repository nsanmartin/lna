#include <arit.h>
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
	sumador (* right, nth_bit(y, n) ? x << n : 0, &suma, &carry);
	* left += nth_bit(y, n) ?
          x >> (BITS_OF_T - n)  :
          0;
	* left += carry;
	* right = suma;
	n++;
    }
}

void digits_set_mul_ui (struct digit * ds, T const x)
{
    T lb, rb;
    T mulcarry = 0; T addcarry;
    T sum;
    struct digit * prev;
    for ( ; ds ; ds = ds -> next)
    {
        multiplicador (ds -> num, x, &lb, &rb);
        sumador (mulcarry, rb, &sum, &addcarry);

	
        ds -> num = sum;

	sumador (addcarry, lb, &mulcarry, &sum);

        if (sum) {
            fprintf(stderr, "error en digit_set_mul_ui, revisarla\n");
            exit(1);
        }
        prev = ds;
    }

    if (mulcarry) {
        prev -> next = digits_new (mulcarry);
        prev -> next -> prev = prev;
    }
}

struct digit * digits_mul (struct digit const * x, struct digit const * y)
{
    struct digit * r = digits_new(0);
    struct digit * res = r;
    if ( iszero (x) ||  iszero (y) )
        return r;
    struct digit * tmp;
    while ( x ) {
        // set tmp = copy(y)
	digits_copy (&tmp, y);
        // set tmp *= x_i
	digits_set_mul_ui (tmp, x -> num);

        // set r += tmp
	digits_set_add (r, tmp);
        // clear tmp
        digits_clear (&tmp);

	if ( x -> next == 0x0) 
	    break;
        if ( r -> next == 0x0 ) {
            digits_new_next(r, 0);
	}
        r = r -> next;
        x = x -> next;
    }
    return res;
}
