#include <digit.h>
#include <arit.h>
#include <stdio.h>
#include <ctype.h>
#include <print.h>

void digits_new_next (struct digit * prev, T num)
{
    struct digit * new = malloc(sizeof(struct digit));
    if (!new) { fprintf (stderr, "Not enough memory.\n"); exit (1); }
    new -> num = num;
    new -> next = 0x0;
    new -> prev = prev;
    prev -> next = new;
}


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


int digits_init_set_decimal_string (struct digit ** d, char const * s)
{
    T decimal_digit = 0;
    struct digit * newd = digits_new (decimal_digit);
    *d = newd;
    if (!s) 
        return -1;
    
    while (isspace (*s))
        s++;

    if (*s < '0' || '9' < *s)
        return -1;

    decimal_digit = ((T) *s - '0');
    s++;
    newd -> num = decimal_digit;
    struct digit * dd, *tmp2, *suma;
    while(('0' <= *s && *s <= '9') || *s == ' ' ) {
        while (isspace (*s))
            s++;

        digits_set_mul_ui ( newd, (T) 10 );
        digits_set_add_ui ( newd, ((T) *s - '0'));
        s++;
    }
    return *s == '\0' ?
        0 : -1;
}

int digits_init_set_decimal_string___ (struct digit ** d, char const * s)
{
  puts("___");
  
  struct digit * p = digits_new(0);
  *d = p;
  char numstr [21];
  unsigned long long num;
  while (*s != '\0') {
    for (int i = 0; i < 21; i++) {
      
      numstr [i] = s [i];
    }
    s += 21;
    num = strtoull(numstr, 0x0, 10);
    digits_set_add_ui (p, num );
    
  }
}


void digits_init_array (struct digit ** d, T const * a, unsigned len)
{
    if (!len) {
        fprintf (stderr, "digits_init_array: len == 0");
        exit(1);
    }
    *d = digits_new (a [0]);
    unsigned i = 1;
    while (i < len) {
        (*d) -> prev = digits_new ( a [i]);
        (*d) -> prev -> next = *d;
        *d = (*d) -> prev;
        i++;
    }
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


/* struct digit * digits_new_array (T num[], unsigned l) */
/* { */
/*     struct digit * res; struct digit * next_tmp, ** p = &res; */
/*     unsigned i = 0; */
    
/*     while ( i < l ) { */
/* 	*p = digits_new ( num[i] ); */
/*         if (i > 0) */
/*             (*p) -> next = next_tmp; */
/*         next_tmp = *p; */
/* 	p = &((*p) -> prev); */
/* 	i++; */
/*     } */
/*     return next_tmp; */
/* } */

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
