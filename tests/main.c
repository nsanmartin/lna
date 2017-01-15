#include <stdio.h>
#include "../digit.h"
#include "../print.h"

int main()
{
    puts("Probando decr.\n===================\n");
    unsigned bytes_read;
    size_t nbytes = 100;
    char * input_x = (char *) malloc (nbytes + 1);
    while ( 1 )
    {
        printf("Ingrese un numero: ");
        bytes_read = getline (&input_x, &nbytes, stdin);
        if (bytes_read == -1)
            puts("Error, se produjo un error al leer el numero.");

        else
        {
            T x = atoll(input_x);
	    lnn_t * n = lnn_new_T (x);
	    lnn_print_hex (n );
        }
    }
    return 0;
}

