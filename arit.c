#include "arit.h"

lnn_t * lnn_digit_mul_T(lnn_t * n, T x);



void lnn_incr (lnn_t * n)
{
    while ( n -> next && n -> num == (T)~0 )
    {
	n -> num = 0;
	n = n -> next;
    }
    if ( n -> num < (T)~0 )
    {
	n -> num++;
    }
    else if ( n -> next == 0x0 ) // no queda otra, igual
    {
	n -> num = 0;
	n -> next = lnn_new_T ((T) 1);
    }
}

void lnn_decr (lnn_t * n)
{
    n -> num--;
    if ( n -> num == ~ (T) 0 )
    {
        if ( n -> next )  lnn_decr ( n -> next );
        else
        {
            lnn_digit_clear ( n , 0x0);
            n = 0x0;
        }
    }
}



void lnn_set_add_T (lnn_t * n, T x)
{
    if ( n -> num  <=  (T)~0 - x )  n -> num += x;
    else
    {
	n -> num -= (T)~0 - x + 1;
	if( n -> next) lnn_incr ( n -> next );
	else n -> next = lnn_new_T((T)1);
    }
}

void lnn_set_add (lnn_t * n, lnn_t * x)
{
    lnn_t * copia = lnn_copy(x);
    lnn_t ** pp = &n;
    while ( *pp && copia )
    {
	lnn_set_add_T ( *pp, copia -> num);
	lnn_t * tmp = copia;
	copia = copia -> next;
	free ( tmp );
	pp = &((*pp) -> next);
    }
    if ( copia ) *pp = copia;
}


//antes:mul_un_nodo_by_typeT
lnn_t * lnn_digit_mul_T (lnn_t * n, T x)
{
    T overflow = (T) 0;
    lnn_t * res = lnn_new_T( (x & ((T) 1)) * n -> num);
    unsigned i = 1;
    T multiplo = x >> 1;
    //todo: si no hay overflow hacerlo comun
    while ( multiplo )
    {
        if ( multiplo & (T) 1)
        {
            overflow += (n -> num >> (BITS_OF_T - i));
            lnn_set_add_T (res, n -> num << i);
        }
        multiplo >>= 1; i++;
    }
    if (res -> next)
    {
        res -> next -> num += overflow;
    }
    else if ( overflow )
    {
        res -> next = lnn_new_T (overflow);
    }
    return res;
}

lnn_t * lnn_mul_T (lnn_t * n, T x)
{
    lnn_t * res = lnn_new_zero();
    lnn_t * r = res;
    while ( n )
    {
	if (x != 0 && (n -> num * x) / x != n -> num) // overflow
	{
            T overflow = (T) 0; T multiplo = x; unsigned i = 0;
            
            while ( multiplo )
            {
                if ( multiplo & (T) 1 && i)
                {
                    overflow += (n -> num >> (BITS_OF_T - i));
                    lnn_set_add_T (res, n -> num << i);
                }
                else if ( multiplo & (T) 1)
                {
                    lnn_set_add_T (res, n -> num );
                }   
            
                multiplo >>= 1; i++;
	    }
            if (res -> next)
            {
                res -> next -> num += overflow;
            }
            else if ( overflow )
            {
                res -> next = lnn_new_T (overflow);
            }
        }
        else
        {
          //res -> num = n -> num * x;
          lnn_set_add_T ( res , n -> num * x );
        }
        n = n -> next;
        if ( n == 0x0 ) break;
        if ( res -> next ) res = res -> next;
        else
        {
            res -> next = lnn_new_zero();
            res = res -> next;
        }
        
    }
    return r;
}



lnn_t * lnn_factorial_T (T n)
{
    lnn_t * res = lnn_new_T( n );
    T factor = n - 1;
    //lnn_t * res = lnn_copy ( n );
    while ( factor > 1 )
    {
	lnn_t * tmp = lnn_mul_T ( res, factor );

	lnn_clear ( &res );
	res = tmp;
	factor--;
    }
    return res;
}

lnn_t * lnn_mul (lnn_t * x, lnn_t * y)
{
    lnn_t * r = lnn_new_zero();
    lnn_t * res = r;
    while ( x )
    {
        lnn_t * tmp = lnn_mul_T ( y, x -> num );
        lnn_set_add ( r, tmp );
        lnn_clear (&tmp);
        if ( x -> next == 0x0) break;
        if ( r -> next == 0x0 ) r -> next = lnn_new_zero();
        r = r -> next;
        x = x -> next;
    }
    return res;
}


lnn_t * lnn_pow (lnn_t * x, lnn_t * y)
{
    lnn_t * potencia = lnn_copy (y);
    lnn_t * res = lnn_new_T(1);
    while (potencia -> next || potencia -> num)
    {
        lnn_t * tmp = res;
        res = lnn_mul (res, x);
        lnn_clear (&tmp);
        lnn_decr(potencia);
    }
    return res;
}

int menor (lnn_t * x, lnn_t * y)
{
    unsigned lnn_lenx = lnn_len(x);
    unsigned lnn_leny = lnn_len(y);
    if ( lnn_lenx == lnn_leny ) {
	return lnn_last_digit (x) < lnn_last_digit (y);
    }
    else return lnn_lenx < lnn_leny;
}

int es_positivo (lnn_t * n)
{
    return n -> next || n -> num;
}
