#include <arit.h>
#include <stdio.h>

void sumador (const T x, const T y, T * sum, T * carry)
{
    * carry = ( x > (T)~0 - y ) ? 1 : 0;
    * sum = x + y;
}

void digits_set_add_T (struct digit * ds, T const y)
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
