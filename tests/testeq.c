#include <stdio.h>
#include "../print.h"
#include "../digit-lnn.h"
#include "../arit.h"

int main(int argc, char ** argv)
{
    if (argc != 3)
    {
	puts("Usage: factorial NUMBER_1 NUMBER_2\n");
	return 0;
    }

    T xT = (T) atoll(argv[1]);
    T yT = (T) atoll(argv[2]);
    
    lnn_t x = lnn_new_T( xT );
    lnn_t y = lnn_new_T( yT );

    printf (PATTERN" ,"PATTERN"\n", xT, yT );
    if ( lnn_eq (x , y ) )
      puts ("son iguales");
    else
      puts("son distintos");
	
    endl;
    return 0;
}
