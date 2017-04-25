#include "arit-digit.h"
#include <stdio.h>
//struct digit * digit_digit_mul_T (struct digit * n, T x);



void digits_incr (struct digit * d)
{
        while ( d -> next && d -> num == (T)~0 )
        {
            d -> num = 0;
            d = d -> next;
        }
        if ( d -> num < (T)~0 )
        {
            d -> num++;
        }
        else if ( d -> next == 0x0 ) // no queda otra, igual
        {
            d -> num = 0;
            d -> next = digits_new ((T) 1);
            d -> next -> prev = d;
        }
}

void digits_decr (struct digit *d)
{
    //vale d > 0
    while ( d -> num == 0 && d -> next )
    {
        d -> num --;
        d = d -> next;
    }
    if ( d -> num > 1 )
    {
        d -> num --;
    }
    else if ( ! d -> next )//( d -> num == 1 )
    {
        d -> prev -> next = 0x0;
        digits_clear ( &d );
    }
    else
        d -> num --;
}

void T_large_mul (const T x, const T y, T * lbits, T * rbits)
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


struct digit * digits_add (struct digit const * x, struct digit const *y)
{
    struct digit *res, *r;
    T suma, cin, cout;

    sumador (x -> num, y -> num, 0, &suma, &cout);
    printf("suma: %llx\n", suma);
    res = digits_new (suma);    

    r = res;
    cin = cout;
    x = x -> next; y = y -> next;
    while (x && y) {
        puts("en el while");
        sumador (x -> num, y -> num, 0, &suma, &cout );
        r -> next = digits_new (suma);
        cin = cout;
        r -> next -> prev = r;
        r = r -> next;
        x = x -> next; y = y -> next;
    }


//    printf ("x: %llu\n", x);
    if (x || y) {
        puts("x||y");
        struct digit const * maximo;// = x ? x : y;
        if (x) {
            maximo = x;
        } else {
            maximo = y;
        }
            
        struct digit  * copia;
        digits_copy ( &copia, maximo );
        r -> next = copia;
        if (cout)
            digits_incr(r -> next);
    }
    else {
        puts("not x||y");
        if (cout) {
            r -> next = digits_new (1);
        }
    }

    return res;

}

/* struct digit *digit_add (struct digit *x, struct digit *y) */
/* { */
/*     digit sum, next_tmp; */
/*     digit s = sum; */
/*     T carry_out = 0; */
/*     T carri_in, suma_T; */

/*     while ( x && y ) */
/*     { */
/*         carry_in = carry_out; */
/*         T_large_sum ( x -> num, y -> num, carry_in, &suma_T, &carry_out); */
/*         s = digit_new ( suma_T ); */


/*         s = s -> next; */
/*     } */

    
    
/* }  */

/* void digit_set_add_T (digit n, T x) */
/* { */
/*     if ( n -> num  <=  (T)~0 - x )  n -> num += x; */
/*     else */
/*     { */
/*       n -> num -= (T)~0 - x + 1;// se puede usar n -> num += x */
/* 	if( n -> next) digit_incr ( n -> next ); */
/* 	else n -> next = digit_new_T((T)1); */
/*     } */
/* } */

/* void digit_set_add (digit n, digit x) */
/* { */
/*     digit copia = digit_copy(x); */
/*     digit * pp = &n; */
/*     while ( *pp && copia ) */
/*     { */
/* 	digit_set_add_T ( *pp, copia -> num); */
/* 	digit tmp = copia; */
/* 	copia = copia -> next; */
/* 	free ( tmp ); */
/* 	pp = &((*pp) -> next); */
/*     } */
/*     if ( copia ) *pp = copia; */
/* } */

/* void digit_set_sub_minor (digit n, digit x) */
/* { */
/*     // precondition: x < n */
/*     while (x) */
/*     { */
/* 	if ( n -> num < x -> num ) */
/* 	    digit_decr ( n -> next ); */
/* 	n -> num -= x -> num; */
/* 	n = n -> next; */
/* 	x = x -> next; */
/*     } */
    
/* } */
/* //antes:mul_un_nodo_by_typeT */
/* digit digit_digit_mul_T (digit n, T x) */
/* { */
/*     T overflow = (T) 0; */
/*     digit res = digit_new_T( (x & ((T) 1)) * n -> num); */
/*     unsigned i = 1; */
/*     T multiplo = x >> 1; */
/*     //todo: si no hay overflow hacerlo comun */
/*     while ( multiplo ) */
/*     { */
/*         if ( multiplo & (T) 1) */
/*         { */
/*             overflow += (n -> num >> (BITS_OF_T - i)); */
/*             digit_set_add_T (res, n -> num << i); */
/*         } */
/*         multiplo >>= 1; i++; */
/*     } */
/*     if (res -> next) */
/*     { */
/*         res -> next -> num += overflow; */
/*     } */
/*     else if ( overflow ) */
/*     { */
/*         res -> next = digit_new_T (overflow); */
/*     } */
/*     return res; */
/* } */

/* digit digit_mul_T (digit n, T x) */
/* { */
/*     digit res = digit_new_zero(); */
/*     digit r = res; */
/*     while ( n ) */
/*     { */
/* 	if (x != 0 && (n -> num * x) / x != n -> num) // overflow */
/* 	{ */
/*             T overflow = (T) 0; T multiplo = x; unsigned i = 0; */
            
/*             while ( multiplo ) */
/*             { */
/*                 if ( multiplo & (T) 1 && i) */
/*                 { */
/*                     overflow += (n -> num >> (BITS_OF_T - i)); */
/*                     digit_set_add_T (res, n -> num << i); */
/*                 } */
/*                 else if ( multiplo & (T) 1) */
/*                 { */
/*                     digit_set_add_T (res, n -> num ); */
/*                 }    */
            
/*                 multiplo >>= 1; i++; */
/* 	    } */
/*             if (res -> next) */
/*             { */
/*                 res -> next -> num += overflow; */
/*             } */
/*             else if ( overflow ) */
/*             { */
/*                 res -> next = digit_new_T (overflow); */
/*             } */
/*         } */
/*         else */
/*         { */
/*           //res -> num = n -> num * x; */
/*           digit_set_add_T ( res , n -> num * x ); */
/*         } */
/*         n = n -> next; */
/*         if ( n == 0x0 ) break; */
/*         if ( res -> next ) res = res -> next; */
/*         else */
/*         { */
/*             res -> next = digit_new_zero(); */
/*             res = res -> next; */
/*         } */
        
/*     } */
/*     return r; */
/* } */



/* digit digit_factorial_T (T n) */
/* { */
/*     digit res = digit_new_T( n ); */
/*     T factor = n - 1; */
/*     //digit res = digit_copy ( n ); */
/*     while ( factor > 1 ) */
/*     { */
/* 	digit tmp = digit_mul_T ( res, factor ); */

/* 	digit_clear ( &res ); */
/* 	res = tmp; */
/* 	factor--; */
/*     } */
/*     return res; */
/* } */

/* digit digit_mul (digit x, digit y) */
/* { */
/*     digit r = digit_new_zero(); */
/*     digit res = r; */
/*     while ( x ) */
/*     { */
/*         digit tmp = digit_mul_T ( y, x -> num ); */
/*         digit_set_add ( r, tmp ); */
/*         digit_clear (&tmp); */
/*         if ( x -> next == 0x0) break; */
/*         if ( r -> next == 0x0 ) r -> next = digit_new_zero(); */
/*         r = r -> next; */
/*         x = x -> next; */
/*     } */
/*     return res; */
/* } */


/* digit digit_pow (digit x, digit y) */
/* { */
/*     digit potencia = digit_copy (y); */
/*     digit res = digit_new_T(1); */
/*     while (potencia -> next || potencia -> num) */
/*     { */
/*         digit tmp = res; */
/*         res = digit_mul (res, x); */
/*         digit_clear (&tmp); */
/*         digit_decr(potencia); */
/*     } */
/*     return res; */
/* } */

/* int digit_minor (digit x, digit y) */
/* { */
/*     unsigned digit_lenx = digit_len(x); */
/*     unsigned digit_leny = digit_len(y); */
/*     if ( digit_lenx == digit_leny ) { */
/* 	return digit_last_digit (x) < digit_last_digit (y); */
/*     } */
/*     else return digit_lenx < digit_leny; */
/* } */

/* int digit_eq (digit x, digit y) */
/* { */
/*     while ( x && y ) */
/*     { */
/* 	if ( x -> num != y -> num ) */
/* 	    return 0; */
/* 	x = x -> next; */
/* 	y = y -> next; */
/*     } */
/*     return !x && !y; */
/* } */

/* int es_positivo (digit n) */
/* { */
/*     return n -> next || n -> num; */
/* } */

/* digit digit_mod (digit n, digit m) */
/* { */
/*     if ( m -> next == 0x0 ) */
/* 	return digit_new_T ( n -> num % m -> num ); */
/*     if ( digit_eq ( n , m )) */
/* 	return digit_new_zero(); */
/*     if ( digit_minor ( n , m ) ) */
/* 	return digit_copy ( n ); */

/*     digit resto = digit_copy ( n ); */

/*     while ( digit_minor ( m , resto ) ) */
/*     { */
/* 	digit mmul = digit_copy ( m ); */
/* 	while ( digit_minor ( mmul, resto) ) */
/* 	{ */
/* 	    digit tmp = mmul; */
/* 	    mmul = digit_mul ( m , m ); */
/* 	    digit_clear (&tmp); */
/* 	} */
/* // */
/*     } */
/* } */
