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

struct digit * digits_new (T num);
struct digit * digits_new_array (T num[], unsigned l);
struct digit * digits_new_decimal_string (char * s);

T digits_copy (struct digit ** dest, struct digit const * src);
T digits_list_len (struct digit * n);

void digits_loop_fwd (struct digit * head, void (*f)(struct digit *));
void digits_loop_bwd (struct digit * last, void (*f)(struct digit *));

/* void digit_list_map_fwd (struct digit *  head, */
/*                          struct digit * (*f)(struct digit *), */
/*                          void * res); */

void digits_clear(struct digit **  lista );



#endif
