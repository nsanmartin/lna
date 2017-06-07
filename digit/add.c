#include <arit.h>
#include <stdio.h>

void sumador (const T x, const T y, T * sum, T * carry)
{
    * carry = ( x > (T)~0 - y ) ? 1 : 0;
    * sum = x + y;
}

void digits_set_add_ui (struct digit * ds, T const y)
{
    T suma, carry;
    sumador (ds -> num, y, &suma, &carry);
    ds -> num = suma;
    if (carry) {
        puts("set add carry");
        if (ds -> next) {
            puts("se incr tail");
            digits_incr (ds -> next);
        } else {
            puts ("se agranda list");
            ds -> next = digits_new (carry);
            ds -> next -> prev = ds;
        }
    }
}


void digits_set_add (struct digit * n, struct digit const *  x)
{
    T carry = 0;
    T carry_ac = 0;
    struct digit * prev = n;


    unsigned l = 0;
    struct digit const * ptr = n;
    /* while (ptr) { l++; ptr = ptr -> next; } */
    /* printf("len x: %ud ", l); */
    /* l = 0; */
    /* ptr = x; */
    /* while (ptr) { l++; ptr = ptr -> next; } */
    /* printf("len n: %ud\t", l); */
    
    
    while (n && x) {
	
	sumador (n -> num, x -> num, &(n -> num), &carry);
	sumador (carry_ac, n -> num, &(n -> num), &carry_ac);
	sumador (carry_ac, carry, &carry_ac, &carry);
	if  (carry) {
	    fprintf(stderr,
		    "error en digits_set_add, revisar implementacion\n");
	    exit(1);
	}
	prev = n;
	n = n -> next;
	x = x -> next;
    }
    struct digit * tmp;
    
    if (x && carry_ac) {
	puts("carry y x");
	digits_copy (&tmp, x);
	digits_set_add_ui (tmp, carry_ac);
	prev -> next = tmp;
	tmp -> prev = prev;
    } else if ( x && !carry_ac) {
	puts("carry y !x");
	digits_copy (&tmp, x);
	prev -> next = tmp;
	tmp -> prev = prev;

    } else if (carry_ac) {

	puts("carry y !x");
	tmp = digits_new (carry_ac);
	prev -> next = tmp;
	tmp -> prev = prev;

    }
}

struct digit * digits_add (struct digit const * x, struct digit const *y)
{
    struct digit *res, *r;
    T suma, cin, cout, cout2;
    sumador (x -> num, y -> num, &suma, &cout);
    res = digits_new (suma);    
    r = res;
    cin = cout;
    x = x -> next; y = y -> next;
    int debug = 0;
    while (x && y) {
	sumador (x -> num, y -> num, &suma, &cout );
        sumador (suma, cin, &suma, &cout2);
        cin = cout + cout2;
        r -> next = digits_new (suma);
        r -> next -> prev = r;
        r = r -> next;
        x = x -> next; y = y -> next;
    }
    struct digit const * maximo = x ? x : y;
    if (maximo) {
        struct digit  * copia;
        digits_copy ( &copia, maximo );
        r -> next = copia;
        r -> next -> prev = r;
        if (cin) {
            digits_incr(r -> next);
        }
    } else if (cin) {
            r -> next = digits_new (cin);
            r -> next -> prev = r;
    } 
    
    return res;

}
