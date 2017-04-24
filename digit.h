#ifndef _DIGIT_H
#define _DIGIT_H

#include <stdlib.h>
#include "basetype.h"

#define MUL_OVERFLOW(x, y)				\
  (((T)x) != 0 && (((T)y) * ((T)x)) / ((T)x) != ((T)y))

typedef struct digit *digit;

struct digit {
    T num;
    digit next;
    digit prev;
};


//void digit_init (digit d, T num); 
//void digit_clear();
void digit_clear(digit d); 

digit digit_new_zero();

digit digit_new_T (T num);

digit digit_new_list_arr (T num[], unsigned l);

digit digit_copy(digit n);
digit digit_list_copy (digit n);

unsigned digit_list_len (digit n);
//digit lnn_reverse_copy(digit n);
T lnn_last_digit (digit n);

void digit_list_loop_fwd (digit head, void (*f)(digit));
void digit_list_map_fwd (digit  head, digit (*f)(digit), void * res);
void digit_list_loop_bwd (digit last, void (*f)(digit));

void digit_list_clear(digit* lista );



#endif
