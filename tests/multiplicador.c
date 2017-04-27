#include <stdio.h>
#include <gmp.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"
#include <errno.h>
/* compilar con:
 * gcc ../digit/*.c suma.c -o suma -lgmp -lm
 *
 */


int main(int argc, char ** argv)
{
    if (argc != 3) { puts("Usage: prog NUMBER\n"); return 0; }

    T x, y, lb, rb;
    errno = 0;
    char * tail;
    x = strtoul (argv[1], &tail, 10);
    if (errno) { puts("primer numero demasiado grande"); return 0; }
    y = strtoul (argv[2], &tail, 10);
    if (errno) { puts("segundo numero demasiado grande"); return 0; }

    multiplicador (x, y, &lb, &rb);

    T bits = BITS_OF_T;
    
    mpz_t producto, right ,left, M;
    mpz_init (right);
    mpz_init (left);
    
    mpz_init_set_ui (M, 2);
    mpz_pow_ui (M, M, bits);
    
    mpz_init_set_ui (producto, x);
    mpz_mul_ui (producto, producto, y);

    mpz_mod (right, producto, M);
    mpz_fdiv_q (left, producto, M);

    /* printf("bits: %d\t \n~0:\t\t %llx\n", bits, ~(T)0); */
    /* gmp_printf ("2^64:\t\t%Zx",M); */

    gmp_printf ("producto:\t  %Zx", producto);

    /* gmp_printf ("right\n\t gmp:\t%Zx\tlna: %llx\t c: %llx\n", */
    /*             right, rb,(T) ((T)x*(T)y)); */

    gmp_printf (" left\t gmp:\t%Zx\t\tlna: %x",
                left, lb);

    
    return 0;
}
