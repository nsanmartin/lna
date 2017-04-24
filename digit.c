#include "digit.h"
#include <stdio.h>


/* void digit_init (digit d, T num) */
/* { */
/*     d -> num = num; d -> next = d -> prev = 0x0; */
/* } */

void digit_clear (struct digit * d) { free ( d ); }

struct digit * digit_new_zero ()
{
    struct digit * res = malloc(sizeof(struct digit));
    if (!res) {
        fprintf (stderr, "Not enough memory.\n");
        exit (1);
    }
    res -> num = (T)0; res -> next = res -> prev = 0x0;
    return res;
};


struct digit * digit_new_T (T num)
{
    struct digit * res = malloc(sizeof(struct digit));
    if (!res) {
        fprintf (stderr, "Not enough memory.\n");
        exit (1);
    }

    res -> num = num;
    res -> next = res -> prev = 0x0; 
    return res;
}


struct digit * digit_new_list_arr (T num[], unsigned l)
{

    struct digit * next_tmp, ** p;
    unsigned i = 0;
    while ( i < l )
    {
	*p = digit_new_T ( num[i] );
        if (i > 0)
            (*p) -> next = next_tmp;
        next_tmp = *p;
	p = &((*p) -> prev);
	i++;
    }
    return next_tmp;
}


struct digit * digit_new_list_arr_invertido (T num[], unsigned l)
{
    struct digit * res; struct digit ** p = &res;
    struct digit * prev_tmp;
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

struct digit * digit_copy (struct digit const * n)
{
    return digit_new_T ( n -> num );
}

T digit_list_copy (struct digit ** dest, struct digit const * src)
{
    T res = 0;
    struct digit * prev, * next;
    while ( src ) {
        next = src -> next;
        * dest = digit_new_T ( src -> num );
        if ( src -> prev )
            (* dest) -> prev = prev;
        prev = * dest;
        dest = &((* dest) -> next);
        src = next;
        res++;
    }

    return res;
}

void digit_list_loop_fwd (struct digit *head, void (*f)(struct digit *))
{
    struct digit * p = head; struct digit * tmp;
    while ( p ) {
	tmp = p -> next;
	f ( p );
	p = tmp;
    }
}
                          


void digit_list_loop_bwd (struct digit * last, void (*f)(struct digit * ))
{
    struct digit * p = last; struct digit * tmp;
    while ( p ) {
	tmp = p -> prev;
	f ( p );
	p = tmp;
    }
}



void digit_list_map_fwd_old (struct digit **head,
                             struct digit * (*f)(struct digit *),
                             void * res)
{
    struct digit * p = * head; struct digit * q;
    struct digit ** r =  (struct digit **) res;
    while ( p ) {
	q = p -> next;
	*r = f ( p );
	r = &((*r) -> next);
	p = q;
    }
}

void digit_list_map_fwd (struct digit *head,
                         struct digit * (*f)(struct digit *),
                         void * res)
{
    struct digit * p =  head;
    struct digit * q;
    struct digit ** r =  (struct digit **) res;
    struct digit * prev_tmp;
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


void digit_list_clear ( struct digit ** lista )
{
    digit_list_loop_fwd ( *lista, digit_clear );
    *lista = 0x0;
}

T digit_list_len (struct digit * n)
{
    T res = 0;
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
