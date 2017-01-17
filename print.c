#include "print.h"

void lnn_print_digit_dec_str (lnn_t * n, void * p);


void lnn_print_digit_dec_str (lnn_t * n, void * p)
{
    PRINT_DIGIT( n -> num);
    printf(" ");
}
void lnn_print_digit_hex (lnn_t * n, void * p)
{
    PRINT_DIGIT_HEX( n -> num);
}

void lnn_print_hex(lnn_t * n)
{
    lnn_t * p = lnn_reverse_copy ( n );
    printf( "0x"hexFORMAT, p -> num );
    if (p -> next) lnn_dolist (&(p -> next), lnn_print_digit_hex, 0x0); 
}

void lnn_print_bin(T x)
{
    unsigned i = BITS_OF_T;
    while ( i-- > 0 ) printf ( PATTERN, (x >> i) & (T)1);
}


void lnn_print_digits_list_dec (lnn_t * n)
{
    lnn_dolist (&n, lnn_print_digit_dec_str, 0x0);
}
