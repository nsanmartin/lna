#include "print.h"

void digit_print_dec_str (digit n);


void digit_print_dec_str (digit n)
{
    PRINT_NUM_DEC ( n -> num);
    printf(" ");
}
void digit_print_hex (digit n)
{
    PRINT_NUM_HEX ( n -> num);
}

void digit_list_print_hex(digit n)
{
  //digit p = lnn_reverse_copy ( n );
    puts("TODO: hay que hacer loop_bkw para mostrar esto bien.");
    printf( "0x"hexFORMAT, n -> num );
    if (n -> next)
        digit_list_loop_fwd (&(n -> next), digit_print_hex); 
}

void print_bin (T x)
{
    unsigned i = BITS_OF_T;
    while ( i-- > 0 ) printf ( PATTERN, (x >> i) & (T)1);
}


void digits_list_lnn_print_dec (digit n)
{
    digit_list_loop_fwd (&n,  digit_print_dec_str);
}
