#include "../arit.h"
#include <stdio.h>

void sumador (const T x, const T y, const T carry_in, T * sum, T * carry)
{
    * carry = ( x > (T)~0 - y ) ? 1 : 0;
    * sum = x + y;
    if ( carry_in ) {
        if (* sum == ~(T)0) {
            * carry ++;
        }
        * sum ++;
    }
}

void digits_set_add_T (struct digit * ds, T const y)
{
    T suma, carry;
    sumador (ds -> num, y, 0, &suma, &carry);
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

struct digit * __digits_add__ (struct digit const * x, struct digit const *y)
{
    printf ("digits_add, debug\t");
    struct digit *res, *r;
    T suma, cin, cout;
    sumador (x -> num, y -> num, 0, &suma, &cout);
    res = digits_new (suma);    
    r = res;
    cin = cout;
    x = x -> next; y = y -> next;
    while (x && y) {
        printf ("long de ambos > 1\t");
	sumador (x -> num, y -> num, cin, &suma, &cout );
        r -> next = digits_new (suma);
        cin = cout;
        r -> next -> prev = r;
        r = r -> next;
        x = x -> next; y = y -> next;
    }
    struct digit const * maximo = x ? x : y;
    if (maximo) {
        printf ("hubo uno mas largo que el otro\t");
        struct digit  * copia;
        digits_copy ( &copia, maximo );
        r -> next = copia;
        r -> next -> prev = r;
        if (cin) {
            printf ("hubo cout final\t");
            digits_incr(r -> next);
        }
    } else if (cin) {
            printf ("hubo cout final\t");

            r -> next = digits_new (cin);
            r -> next -> prev = r;
    } else {
        printf ("no hubo maximo ni cout final\t");
    }
    
    return res;

}

struct digit * digits_add (struct digit const * x, struct digit const *y)
{
    printf ("digits_add, debug\t");
    struct digit *res, *r;
    T suma, cin, cout, cout2;
    sumador (x -> num, y -> num, 0, &suma, &cout);
    res = digits_new (suma);    
    r = res;
    cin = cout;
    x = x -> next; y = y -> next;
    int debug = 0;
    while (x && y) {
        if (!debug++)
            printf ("long de ambos > 1\t");
	sumador (x -> num, y -> num, 0, &suma, &cout );
        sumador (suma, cin, 0, &suma, &cout2);
        r -> next = digits_new (suma);
        cin = cout + cout2;
        r -> next -> prev = r;
        r = r -> next;
        x = x -> next; y = y -> next;
    }
    struct digit const * maximo = x ? x : y;
    if (maximo) {
        printf ("hubo uno mas largo que el otro\t");
        struct digit  * copia;
        digits_copy ( &copia, maximo );
        r -> next = copia;
        r -> next -> prev = r;
        if (cin) {
            printf ("hubo cout final\t");
            digits_incr(r -> next);
        }
    } else if (cin) {
            printf ("hubo cout final\t");

            r -> next = digits_new (cin);
            r -> next -> prev = r;
    } else {
        printf ("no hubo maximo ni cout final\t");
    }
    
    return res;

}
