#include <arit.h>
#include <stdio.h>
#include <assert.h>
#include <digit.h>


#define set_bit0_with_ith_2wd(R, Nl, Nr, i)                             \
     do {                                                               \
          T *P = i < BITS_OF_T ? &Nr : &Nl;                             \
          (R) = ((R) & (~(T)0 << 1)) | (((*P) >> (i % BITS_OF_T )) & 1); \
     } while (0)                                                        \

#define set_ith_bit_eq1(Q,i)                    \
     (Q) |= ((T)1 << i)                         \


#define set_ith_bit(Q,i)                    \
     (Q) |= ((T)1 << i)                     \


void div2 (T *hbits, T *lbits, T d, T *rem)
{
     T Q, R;
     Q = R = 0;
     int i;
     for (i = 2*BITS_OF_T - 1; i >= 0 ; i--) {
          R <<= 1;
          set_bit0_with_ith_2wd(R, *hbits, *lbits, i);
          if (R >= d) {
               R -= d;
               set_ith_bit(Q, i);
          }
     }
     *hbits /= d; *lbits = Q; *rem = R;
}

void div_2wd_num (T left, T right, T d, T *quot, T *rem)
{
    T Q, R;
    Q = R = 0;
    T i;
    for (i = 2*BITS_OF_T; i > 0 ; i--) {
        R <<= 1;
        set_bit0_with_ith_2wd(R, left, right, (i - 1));
        if (R >= d) {
            R -= d;
            set_ith_bit_eq1(Q, (i - 1));
        }
    }
    *quot = Q; *rem = R;
}

void digits_set_div_ui (struct digit * ds, T divisor)
{
     assert (divisor && ds -> prev == 0x0);
     if (ds -> next == 0x0) {
          ds -> num /= divisor;
          return;
     }

     T resto,/* num,*/ len = 1;
     while (ds -> next) { ds = ds -> next; len++; }

     if (ds -> num < divisor) {
          resto = ds -> num;
          ds = ds -> prev;
          free_digit (ds -> next);
          ds -> next = 0x0;
     } else {
          resto = ds -> num % divisor;
          ds -> num /= divisor;
          ds = ds -> prev;
     }

     while (ds) {
          //num = ds -> num;
          T high = resto;
          //div_2wd_num (resto, ds -> num, divisor, &num, &resto);
          div2 (&high, &(ds -> num), divisor, &resto);
          //ds -> num = num;
          ds = ds -> prev;
     }
    
}

#define lshift_1bit (left, right) \
    (left) = (left) << 1 & (( ~(T)0 << 1 ) | right >> BITS_OF_T - 1)

T base_div_ui (T d)
{// vale pre: d != 0
    T bmenosd = ~(T)0 - (d - 1);
    return 1 + bmenosd / d;
}

/* void digits_set_div (struct digit * u, struct digit * v) */
/* { */
/*     fprintf (stderr, "digits_set_div no implementada\n"); */
/*     T len_u, len_v; */
/*     len_u = length(u); */
/*     len_v = length(v); */
/*     assert (len_u < len_v); */
         
/*     // D1 */
/*     T v_n_1 = v -> num; */
/*     T d = v_n_1 == ~(T)0 ? 1 : base_div_ui(v_n_1); */
/*     digits_set_mul_ui(u, d); */
/*     digits_set_mul_ui(v, d); */
/*     // D2 */
/*     struct digit * up, * vp; */
/*     up = u; vp = v; */
/*     T  q_sombrero, r_sombrero, tmp, u_jn_1, u_jn = 0; */
    
/*     for (T m = len_u - len_v; m; m--) { */
/*          // D3 */
/*          u_jn_1 = u -> num; */
/*          div_2wd_num (u_jn, u_jn_1, v -> num, */
/*                       q_sombrero, r_sombrero); */
/*     } */

    
/*     d = 1; */
/*     if (v -> num != ~(T)0) */
/*         d = base_div_ui (v -> num + 1); */
/*     digits_set_mul_ui (u, d); */
/*     digits_set_mul_ui (v, d); */
/* } */

