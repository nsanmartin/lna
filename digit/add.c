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
        if (ds -> next) {
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
    T carry = 0; T carry_ac = 0;
    struct digit * prev = n;
    
    while (n && x) {
        // set sum_i = x_i + y_i
	sumador (n -> num, x -> num, &(n -> num), &carry);
        // si en el paso anterior tuve carry,
        // set sum_i += carry_anterior
        if (carry_ac > 0)
          sumador (carry_ac, n -> num, &(n -> num), &carry_ac);
        // seteo carry para proxima iteracion
        // set carry_ac = carry;
        carry_ac = carry;
        //sumador (carry_ac, carry, &carry_ac, &carry);
	prev = n;
	n = n -> next;
	x = x -> next;
    }
    struct digit * tmp;
    if (x && carry_ac) {
        // quedaban sumar digitos mas significativos en const x
        // y tambien hubo un carry
	//puts("carry y x");
	digits_copy (&tmp, x);
	digits_set_add_ui (tmp, carry_ac);
	prev -> next = tmp;
	tmp -> prev = prev;
    } else if ( x && !carry_ac) {
        // quedaban sumar digitos mas significativos en const x
        // pero no hubo un carry
	digits_copy (&tmp, x);
	prev -> next = tmp;
	tmp -> prev = prev;
    } else if (carry_ac && n) {
        // no quedaban digitos que sumar, pero hubo carry,
        // y quedaban digitos en n.
        digits_set_add_ui (n, carry_ac);
    } else if (carry_ac && !n) {
        //hubo carry pero no hay mas digitos en n
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
