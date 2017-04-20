#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"

int main(int argc, char ** argv)
{
    if (argc != 3)
    {
	puts("Usage: parse NUMBER1 NUMBER2\n");
	return 0;
    }

    lnn_t n = lnn_new_decimal_string (  argv[1] );
    lnn_t m = lnn_new_decimal_string (  argv[2] );
    
    printf ("1: "); lnn_print_hex ( n );endl;
    printf ("2: "); lnn_print_hex ( m );

    if ( lnn_eq (n , m) )
      puts("\tiguales");
    else
      puts("\tdistintos");
    
    return 0;
}
