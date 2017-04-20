#include <stdio.h>
#include "../print.h"
#include "../read.h"
#include "../digit.h"
#include "../arit.h"

int main(int argc, char ** argv)
{
    if (argc != 3)
    {
	puts("Usage: add UMBER1 NUMBER2\n");
	return 0;
    }

    lnn_t n = lnn_new_decimal_string (  argv[1] );
    lnn_t m = lnn_new_decimal_string (  argv[2] );
    
    lnn_set_add ( n, m );

    lnn_print_hex ( n );endl;
    
    return 0;
}
