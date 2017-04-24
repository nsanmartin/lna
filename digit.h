#ifndef _DIGIT_H
#define _DIGIT_H

#include <stdlib.h>
#include "basetype.h"

#define MUL_OVERFLOW(x, y)				\
  (((T)x) != 0 && (((T)y) * ((T)x)) / ((T)x) != ((T)y))

//typedef struct digit const * digit;

struct digit {
    T num;
    struct digit * next;
    struct digit * prev;
};


//void digit_init (digit d, T num); 
//void digit_clear();
void digit_clear(struct digit * d); 

struct digit * digit_new_zero();

struct digit * digit_new_T (T num);

struct digit * digit_new_list_arr (T num[], unsigned l);

struct digit * digit_copy(struct digit const * n);
T digit_list_copy (struct digit ** dest, struct digit const * src);

T digit_list_len (struct digit * n);
//digit lnn_reverse_copy(digit n);
T lnn_last_digit (struct digit * n);

void digit_list_loop_fwd (struct digit * head, void (*f)(struct digit *));
void digit_list_map_fwd (struct digit *  head,
                         struct digit * (*f)(struct digit *),
                         void * res);

void digit_list_loop_bwd (struct digit * last, void (*f)(struct digit *));

void digit_list_clear(struct digit **  lista );



#endif
