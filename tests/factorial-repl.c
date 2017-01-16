#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"

T factorial_T (T x);

int main()
{
    puts("Probando factorial.\n===================\n");
    unsigned bytes_read;
    size_t nbytes = 100;
    char * input = (char *) malloc (nbytes + 1);
    
    while ( 1 )
    {
        puts("Ingrese numero: ");
        bytes_read = getline (&input, &nbytes, stdin);

        if (bytes_read == -1)
        {
            puts("Error, se produjo un error al leer el numero.");
        }
        else
        {
            unsigned long long xll = atoll(input);
            T x = (T) xll;
            printf ("Numero ingresado: "hexFORMAT" (hex), "FORMAT "(dec).\n",
		    x, x);
            
            lnn_t * nx = lnn_new_T (x);
            lnn_t * p = lnn_factorial_T(nx);
            puts("Resultado  (en hexadecimal): \n");
            lnn_print_hex (p); endl;
            if (x < 21)
            {
                T valor = factorial_T(x);
                printf("\n"hexPATTERN"\n", valor);
            }
        }
    }
    
    
    return 0;
    
}

T factorial_T (T x)
{
    T res = 1;
    while (x)  res *= x--;
    return res;
}
