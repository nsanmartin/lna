#include <arit.h>
#include <stdio.h>
#include <assert.h>
#include <digit.h>


#define set_bit0_with_ith_2wd(R, Nl, Nr, i)                              \
    do {                                                                \
        T *P = i < BITS_OF_T ? &Nr : &Nl;                                 \
        (R) = (R) & (~(T)0 << 1) | (((*P) >> (i % BITS_OF_T )) & 1);   \
    } while (0)                                                         \

#define set_ith_bit_eq1(Q,i)						\
    (Q) = ((Q) & ~((T)1 << i)) | ((T)1<<i)                              \

void div_2wd_num (T left, T right, T d, T *quot, T *rem)
{
    T Q, R;
    Q = R = 0;
    T i;
    for (i = 2*BITS_OF_T - 1; i >= 0 ; i--) {
        R <<= 1;
        set_bit0_with_ith_2wd(R, left, right, i);
        if (R >= d) {
            R -= d;
            set_ith_bit_eq1(Q, i);
        }
    }
    *quot = Q; *rem = R;
}

void digits_set_div_ui (struct digit * ds, T divisor)
{
    assert (divisor && ds -> prev == 0x0);
    if (ds -> next == 0x0) {
	printf("****** len 1. num: %u\n", ds -> num);
	ds -> num /= divisor;
	printf("num div: %u****** \n", ds -> num);
	assert (ds ->prev == 0x0);
	
	return;
    }

    T resto, num, len = 0;
    while (ds -> next) { ds = ds -> next; len++; }
    printf("len: %u\n", len);
    if (ds -> num < divisor) {
	puts("menor$\n");
        resto = ds -> num;
        ds = ds -> prev;
        free_digit (ds -> next);
        ds -> next = 0x0;

    } else {
	puts("mayor$\n");

	resto = ds -> num % divisor;
	ds -> num /= divisor;
	ds = ds -> prev;
    }

    while (ds) {
	num = ds -> num;
	div_2wd_num (resto, ds -> num, divisor, &num, &resto);
	ds -> num = num;
	ds = ds -> prev;
    }
    
}
