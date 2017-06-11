#ifndef _ARIT_H
#define _ARIT_H

#include "digit.h"

void digits_incr (struct digit * n);
void digits_decr (struct digit * n);
struct digit * digits_add (struct digit const * x, struct digit const *y);
void digits_set_add (struct digit * x, struct digit const *y);

struct digit * digits_mul (struct digit const * x, struct digit const *y);

void sumador (const T x, const T y, T * sum, T * carry);
void digits_set_mul_ui (struct digit * ds, T const x);
void digits_set_add_ui (struct digit * ds, T const y);
void multiplicador (const T x, const T y, T * lbits, T * rbits);


void digits_set_lshift_digits_ui (struct digit * d, T n);


int iszero(struct digit const * d);
//void digit_set_add (struct digit * x, struct digit const  * y);

/* void digit_set_add (digit n, digit x); */
/* void digit_set_add_ui (digit n, T x); */

/* void digit_set_sub_minor (digit n, digit x); */

/* digit digit_mul_T (digit n, T x); */
/* digit digit_mul (digit x, digit y); */
/* digit digit_pow (digit x, digit y); */

/* digit digit_factorial_T (T n); */

/* int digit_minor (digit x, digit y); */
/* int digit_eq (digit x, digit y); */

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
