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

//void digit_clear(struct digit * d); 

//struct digit * digit_new_zero();
struct digit * digits_new (T num);
struct digit * digits_new_list_arr (T num[], unsigned l);
//struct digit * digits_copy(struct digit const * n);

T digits_copy (struct digit ** dest, struct digit const * src);
T digits_list_len (struct digit * n);
//digit lnn_reverse_copy(digit n);
//T lnn_last_digit (struct digit * n);

void digits_loop_fwd (struct digit * head, void (*f)(void *));
void digits_loop_bwd (struct digit * last, void (*f)(struct digit *));

/* void digit_list_map_fwd (struct digit *  head, */
/*                          struct digit * (*f)(struct digit *), */
/*                          void * res); */

void digits_clear(struct digit **  lista );



#endif
