#ifndef _DIGIT_H
#define _DIGIT_H

#include <stdlib.h>
#include "basetype.h"

#define MUL_OVERFLOW(x, y)				\
  (((T)x) != 0 && (((T)y) * ((T)x)) / ((T)x) != ((T)y))

struct digit {
    T num;
    struct digit * next;
    struct digit * prev;
};


void digits_new_next (struct digit * prev, T num);

struct digit * digits_new (T num);
struct digit * digits_new_array (T num[], unsigned l);
int digits_init_set_decimal_string (struct digit ** d, char const * s);

T digits_copy (struct digit ** dest, struct digit const * src);
T digits_list_len (struct digit * n);

void digits_loop_fwd (struct digit * head, void (*f)(struct digit *));
void digits_loop_bwd (struct digit * last, void (*f)(struct digit *));

/* void digit_list_map_fwd (struct digit *  head, */
/*                          struct digit * (*f)(struct digit *), */
/*                          void * res); */

void digits_clear(struct digit **  lista );
char * digits_get_str_hex (struct digit * d);

T digits_len (struct digit * n);


#endif
