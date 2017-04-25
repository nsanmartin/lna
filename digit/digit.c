#include "../digit.h"
#include "../arit.h"
#include <stdio.h>


struct digit * digits_new (T num)
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


struct digit * digits_new_decimal_string (char * s)
{
    struct digit * res = digits_new (0);
    while(*s >= '0' && *s <= '9') {
        struct digit * tmp = res;
        digits_set_mul_T ( res, (T) 10 );
        digits_set_add_T ( res, (T) *s - '0');
        s++;
    }
    return res;
}


struct digit * digits_new_array (T num[], unsigned l)
{
    struct digit * res; struct digit * next_tmp, ** p = &res;
    unsigned i = 0;
    while ( i < l ) {
	*p = digits_new ( num[i] );
        if (i > 0)
            (*p) -> next = next_tmp;
        next_tmp = *p;
	p = &((*p) -> prev);
	i++;
    }
    return next_tmp;
}

struct digit * digits_new_list_arr_invertido (T num[], unsigned l)
{
    struct digit * res; struct digit ** p = &res;
    struct digit * prev_tmp;
    unsigned i = 0;
    while ( i < l )
    {
	*p = digits_new ( num[i] );
        if (i > 0)
            (*p) -> prev = prev_tmp;
        prev_tmp = *p;
	p = &((*p) -> next);
	i++;
    }
    return res;
}

T digits_copy (struct digit ** dest, struct digit const * src)
{
    T res = 0; unsigned first = 0;
    struct digit * prev, * next;
    while ( src ) {
        next = src -> next;
        * dest = digits_new ( src -> num );
        if ( first++ > 0 )
            (* dest) -> prev = prev;
        prev = * dest;
        dest = &((* dest) -> next);
        src = next;
        res++;
    }
    return res;
}

void digits_loop_fwd (struct digit *head, void (*f)(struct digit *))
{
    struct digit * p = head; struct digit * tmp;
    while ( p ) {
	tmp = p -> next;
	f ( p );
	p = tmp;
    }
}

void digits_loop_bwd (struct digit * last, void (*f)(struct digit * ))
{
    struct digit * p = last; struct digit * tmp;
    while ( p ) {
	tmp = p -> prev;
	f ( p );
	p = tmp;
    }
}

void digits_map_fwd_old (struct digit **head,
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

void digits_map_fwd (struct digit *head,
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

void free_digit (struct digit * d) { free ( d ); }

void digits_clear ( struct digit ** lista )
{
    digits_loop_fwd ( *lista, &free_digit );
    *lista = 0x0;
}

T digits_len (struct digit * n)
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
