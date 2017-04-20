#ifndef _LNN_T_H
#define _LNN_T_H

#include <stdlib.h>
#include "basetype.h"

#define MUL_OVERFLOW(x, y)				\
  (((T)x) != 0 && (((T)y) * ((T)x)) / ((T)x) != ((T)y))

typedef struct lnn_t *lnn_t;

struct lnn_t {
    T num;
    lnn_t next;
};


void lnn_init (lnn_t n); 
void lnn_digit_clrear();

lnn_t lnn_new_zero();
lnn_t lnn_new_T (T num);
lnn_t lnn_new_arr (T num[], unsigned l);
lnn_t lnn_copy_digit(lnn_t n);
lnn_t lnn_copy (lnn_t n);

unsigned lnn_len (lnn_t n);
lnn_t lnn_reverse_copy(lnn_t n);
T lnn_last_digit(lnn_t n);

void lnn_dolist(lnn_t*head, void (*f)(lnn_t, void *), void * res);
void lnn_map (lnn_t*head, lnn_t (*f)(lnn_t), void * res);

void lnn_digit_clear( lnn_t n, void * p); 
void lnn_clear(lnn_t* lista );



#endif
