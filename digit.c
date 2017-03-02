#include "digit.h"
#include <stdio.h>


void lnn_t_init (lnn_t * n, T num) { n -> num = num; n -> next = 0x0; }

lnn_t * lnn_new_zero ()
{
    lnn_t * res = malloc(sizeof(lnn_t));
    if (!res) {
        fprintf (stderr, "Not enough memory.\n");
        exit (1);
    }
    res -> num = (T)0; res -> next = 0x0;
    return res;
};

void lnn_digit_clear (lnn_t * n, void *p) { free ( n ); }

lnn_t * lnn_new_T (T num)
{
    lnn_t * res = malloc(sizeof(lnn_t));
    if (!res) {
        fprintf (stderr, "Not enough memory.\n");
        exit (1);
    }

    res -> num = num;
    res -> next = 0x0; 
    return res;
}

lnn_t * lnn_new_arr (T num[], unsigned l)
{
    lnn_t * res; lnn_t ** p = &res;
    unsigned i = 0;
    while ( i < l )
    {
	*p = lnn_new_T ( num[i] );
	p = &((*p) -> next);
	i++;
    }
    return res;
}

lnn_t * lnn_copy_digit (lnn_t * n) { return lnn_new_T ( n -> num ); }

lnn_t * lnn_copy (lnn_t * n)
{
    lnn_t * res;
    lnn_map ( &n, lnn_copy_digit, (void *) &res);
    return res;
}

void lnn_dolist (lnn_t **head, void (*f)(lnn_t *, void *), void * res)
{
    lnn_t * p = *head; lnn_t * tmp;
    void * r = res;
    while ( p ) {
	tmp = p -> next;
	f ( p , &r);
	//r = &((*r) -> next);
	p = tmp;
    }
}

void acumular (lnn_t *n, void * p)
{
    T ** t = p;
    ** t +=  n -> num;
    //    ** (T **) p += n -> num;
}

void lnn_map (lnn_t **head, lnn_t * (*f)(lnn_t *), void * res)
{
    lnn_t * p = *head; lnn_t * q;
    lnn_t ** r =  (lnn_t **) res;
    while ( p ) {
	q = p -> next;
	*r = f ( p );
	r = &((*r) -> next);
	p = q;
    }
}

void lnn_clear ( lnn_t ** lista )
{
    lnn_dolist ( lista, lnn_digit_clear, 0x0 ); *lista = 0x0;
}

unsigned lnn_len (lnn_t * n)
{
    unsigned res = 0;
    while ( n ) { res++; n = n -> next; }
    return res;
}

lnn_t * lnn_reverse_copy (lnn_t * n)
{
    lnn_t * res = 0x0;
    while ( n )
    {
	lnn_t * tmp = lnn_new_T ( n -> num );
	tmp -> next = res;
	res = tmp;
	n = n -> next;
    }
    return res;
}

T lnn_last_digit (lnn_t * n)
{
    while (n -> next) n = n -> next;
    return n -> num;
}
