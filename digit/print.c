#include <print.h>

void digit_node_print_dec_str (struct digit * n);
void digit_node_print_hex (struct digit * n);


void digit_node_print_dec_str (struct digit * n)
{
    PRINT_NUM_DEC ( n -> num);
    printf(" ");
}
void digit_node_print_hex (struct digit * n)
{
    PRINT_NUM_HEX ( n -> num);
}

void digits_print_hex(struct digit * n)
{
    // debug
    if (!n) {
        fprintf(stderr, "digits_print_hex: error: parametro nulo");
        exit(1);
    }
    while(n -> next)
      n = n -> next;
    printf( "0x"hexFORMAT, n -> num );
    digits_loop_bwd (n -> prev, digit_node_print_hex);
    printf("\n");
}

void print_bin (T x)
{
    unsigned i = BITS_OF_T;
    while ( i-- > 0 ) printf ( PATTERN, (x >> i) & (T)1);
}


void digits_list_lnn_print_dec (struct digit * n)
{
    digits_loop_fwd (n,  digit_node_print_dec_str);
}
