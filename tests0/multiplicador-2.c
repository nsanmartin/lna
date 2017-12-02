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


    T x, y, lb, rb;
    T bits = BITS_OF_T;
    mpz_t producto, right ,left, M;
    mpz_init (right);
    mpz_init (left);
    
      mpz_init_set_ui (M, 2);
      mpz_pow_ui (M, M, bits);
    
      for (x = 255, y = 255; x > 0 && y > 0; x--, y--) {
        multiplicador (x, y, &lb, &rb);
        mpz_init_set_ui (producto, x);
        mpz_mul_ui (producto, producto, y);

        mpz_mod (right, producto, M);
        mpz_fdiv_q (left, producto, M);

        printf("\nx: %x, y: %x\t", x, y);

        gmp_printf ("producto: %Zx ", producto);

        gmp_printf ("left\t gmp:\t%Zx\t\tlna: %x",
                    left, lb);
      }
      return 0;
}
