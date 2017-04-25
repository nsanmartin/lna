#ifndef _ARIT_H
#define _ARIT_H

#include "lni.h"

void lni_incr (lni_t n);
void lni_decr (lni_t n);
void lni_set_add (lni_t n, lni_t x);
void lni_set_add_T (lni_t n, T x);

void lni_set_sub_minor (lni_t n, lni_t x);

lni_t lni_mul_T (lni_t n, T x);
lni_t lni_mul (lni_t x, lni_t y);
lni_t lni_pow (lni_t x, lni_t y);

lni_t lni_factorial_T (T n);

int lni_minor (lni_t x, lni_t y);
int lni_eq (lni_t x, lni_t y);

//////////////////////////////////////////////////////////////////
/* void lnn_incr (lnn_t n); */
/* void lnn_decr (lnn_t n); */
/* void lnn_set_add (lnn_t n, lnn_t x); */
/* void lnn_set_add_T (lnn_t n, T x); */

/* void lnn_set_sub_minor (lnn_t n, lnn_t x); */

/* lnn_t lnn_mul_T (lnn_t n, T x); */
/* lnn_t lnn_mul (lnn_t x, lnn_t y); */
/* lnn_t lnn_pow (lnn_t x, lnn_t y); */

/* lnn_t lnn_factorial_T (T n); */

/* int lnn_minor (lnn_t x, lnn_t y); */
/* int lnn_eq (lnn_t x, lnn_t y); */


#endif
