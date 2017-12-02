#include <stdio.h>
#include <string.h>
#include <print.h>
#include <digit.h>
#include <arit.h>

int main(int argc, char ** argv)
{
  
    if (argc != 3) {
        puts("Usage: mul NUMBER NUMBER\n");return 0;
    }
    char const * fst  = strdup(argv[1]);
    char const * snd  = strdup(argv[2]);
    
    struct digit * d, * e, * lna_mul;
    
    digits_init_set_decimal_string(&d, fst );
    digits_init_set_decimal_string(&e, snd );
    
    lna_mul = digits_mul (d, e);
    digits_print_hex(lna_mul);

}
