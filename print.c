#include "print.h"

// digit_print
/* void pr_num (lnn_t * n, void * p) */
/* { */
/*     PRINT_DIGIT_HEX( n -> num); */
/* } */

// digit_print_hex
void lnn_print_digit_hex (lnn_t * n, void * p)
{
    PRINT_DIGIT_HEX( n -> num);
}


/* void prn0 (char * s, lnn_t * n) */
/* { */
/*     printf( "%s", s); dolist ( &n, pr_num, 0x0); */
/* } */

// nat_print_hex
void lnn_print_hex(lnn_t * n)
{
    lnn_t * p = lnn_reverse_copy ( n );
    printf( "0x"hexFORMAT, p -> num );
    if (p -> next) lnn_dolist (&(p -> next), lnn_print_digit_hex, 0x0); 
}

// nat_print_bin
void lnn_print_bin(T x)
{
    unsigned i = BITS_OF_T;
    while ( i-- > 0 ) printf ( PATTERN, (x >> i) & (T)1);
}

// bint_print_hex
/* void showHex ( lnn_t * n) */
/* { */
    
/* } */
