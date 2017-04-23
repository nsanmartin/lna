#include "digit.h"
#include <stdio.h>


/* void digit_init (digit d, T num) */
/* { */
/*     d -> num = num; d -> next = d -> prev = 0x0; */
/* } */

void digit_clear (digit d) { free ( d ); }

digit digit_new_zero ()
{
    digit res = malloc(sizeof(digit));
    if (!res) {
        fprintf (stderr, "Not enough memory.\n");
        exit (1);
    }
    res -> num = (T)0; res -> next = res -> prev = 0x0;
    return res;
};


digit digit_new_T (T num)
{
    digit res = malloc(sizeof(digit));
    if (!res) {
        fprintf (stderr, "Not enough memory.\n");
        exit (1);
    }

    res -> num = num;
    res -> next = res -> prev = 0x0; 
    return res;
}

digit digit_new_list_arr (T num[], unsigned l)
{
    digit res; digit * p = &res;
    digit prev_tmp;
    unsigned i = 0;
    while ( i < l )
    {
	*p = digit_new_T ( num[i] );
        if (i > 0)
            (*p) -> prev = prev_tmp;
        prev_tmp = *p;
	p = &((*p) -> next);
        
	i++;
    }
    return res;
}

digit digit_copy (digit n) { return digit_new_T ( n -> num ); }

digit digit_list_copy (digit n)
{
    digit res;
    digit_list_map_fwd ( &n, digit_copy, (void *) &res);
    return res;
}

void digit_list_loop_fwd (digit * head, void (*f)(digit))
{
    digit p = *head; digit tmp;
    while ( p ) {
	tmp = p -> next;
	f ( p );
	p = tmp;
    }
}



void digit_list_loop_bwd (digit last, void (*f)(digit))
{
    digit p = last; digit tmp;
    while ( p ) {
	tmp = p -> prev;
	f ( p );
	p = tmp;
    }
}



void digit_list_map_fwd (digit * head, digit (*f)(digit), void * res)
{
    digit p = * head; digit q;
    digit * r =  (digit *) res;
    while ( p ) {
	q = p -> next;
	*r = f ( p );
	r = &((*r) -> next);
	p = q;
    }
}

void digit_list_map_fwd2 (digit head, digit (*f)(digit), digit * res)
{
    digit p =  head; digit q;
    digit * r =  (digit *) res;
    digit prev_tmp;
    while ( p ) {
	q = p -> next;
	*r = f ( p );
        if (p -> prev)
            (*r) -> prev = prev_tmp;
        prev_tmp = *r;
	r = &((*r) -> next);
	p = q;
    }
}



void digit_list_clear ( digit * lista )
{
    digit_list_loop_fwd ( lista, digit_clear );
    *lista = 0x0;
}

unsigned digit_list_len (digit n)
{
    unsigned res = 0;
    while ( n ) { res++; n = n -> next; }
    return res;
}

/* lnn_t lnn_reverse_copy (lnn_t n) */
/* { */
/*     lnn_t res = 0x0; */
/*     while ( n ) */
/*     { */
/* 	lnn_t tmp = lnn_new_T ( n -> num ); */
/* 	tmp -> next = res; */
/* 	res = tmp; */
/* 	n = n -> next; */
/*     } */
/*     return res; */
/* } */

/* T last_digit (digit d) */
/* { */
    
/*     while (n -> next) n = n -> next; */
/*     return n -> num; */
/* } */
