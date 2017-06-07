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
#define DEB(str, d) \
    printf((str)); digits_print_hex ((d));
#include <print.h>
struct digit * digits_mul (struct digit const * x, struct digit const * y)
{
    struct digit * r = digits_new(0);
    struct digit ** res = &r;
    struct digit * tmp;

    unsigned veces = 0;
    /* DEB( "x: ", x); */
    /* DEB( "y: ", y); */
    
    while ( x ) {
	digits_copy (&tmp, y);
	//DEB("tmp (copy y): ", tmp);
	digits_set_mul_ui (tmp, x -> num);
	//DEB("tmp (post set mul): ", tmp);
	digits_set_add (r, tmp);
        digits_clear (&tmp);
	veces++;
	if ( x -> next == 0x0) {
	    break;
	}
        if ( r -> next == 0x0 ) {
	    puts ("nuevo");
	    r -> next = digits_new(0);
	    r -> next -> prev = r ;
	}
        r = r -> next;
        x = x -> next;
    }
    //    printf ("veces: %u res (post): ", veces);
    //digits_print_hex (*res);

    return *res;
    /* struct digit * r = digits_new_(0);  digit res = r; */
    /* while ( x ) { */
    /*     digit tmp = digit_mul_T ( y, x -> num ); */
    /*     digit_set_add ( r, tmp ); */
    /*     digit_clear (&tmp); */
    /*     if ( x -> next == 0x0) break; */
    /*     if ( r -> next == 0x0 ) r -> next = digit_new_zero(); */
    /*     r = r -> next; */
    /*     x = x -> next; */
    /* } */
    /* return res; */
}
