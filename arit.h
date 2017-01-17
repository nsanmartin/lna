#ifndef _ARIT_H
#define _ARIT_H

#include "digit.h"

void lnn_incr (lnn_t * n);
void lnn_decr (lnn_t * n);
void lnn_set_add (lnn_t * n, lnn_t * x);
void lnn_set_add_T (lnn_t * n, T x);
lnn_t * lnn_mul_T (lnn_t * n, T x);
lnn_t * lnn_mul (lnn_t * x, lnn_t * y);
lnn_t * lnn_pow (lnn_t * x, lnn_t * y);

lnn_t * lnn_factorial_T (T n);


#endif
