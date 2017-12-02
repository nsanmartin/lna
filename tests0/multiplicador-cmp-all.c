#include "tests.h"
/* compilar con:
 * gcc ../digit/*.c suma.c -o suma -lgmp -lm
 *
 */


int main(int argc, char ** argv)
{
    if (argc > 1) { puts("Usage: prog\n"); return 0; }

    T x, y, lb, rb;
    /* errno = 0; */
    /* char * tail; */
    /* x = strtoul (argv[1], &tail, 10); */
    /* if (errno) { puts("primer numero demasiado grande"); return 0; } */
    /* y = strtoul (argv[2], &tail, 10); */
    /* if (errno) { puts("segundo numero demasiado grande"); return 0; } */
    T bits = BITS_OF_T;

    mpz_t producto, right ,left, M;
    //    T x, y;
    int left_error, right_error;

    mpz_init_set_ui (M, 2);
    mpz_pow_ui (M, M, bits);

    for (x = (T)~0; 0 != x ; x--) {
      for (y = (T)~0; 0 != y; y--) {
        
        multiplicador (x, y, &lb, &rb);

        mpz_init (right); 
        mpz_init (left);
    
    
        mpz_init_set_ui (producto, x);
        mpz_mul_ui (producto, producto, y);
    
        mpz_mod (right, producto, M);
        mpz_fdiv_q (left, producto, M);


        left_error = mpz_cmp_ui (left, lb);
        right_error = mpz_cmp_ui (right, rb);

        mpz_clear (right);
        mpz_clear (left);
        mpz_clear (producto);
        
        if (!left_error || !right_error) {
          printf("%x * %x: ok.\n", x, y);
        }
        else {
          if (left_error) {
            printf("error en left bits. Parametros: %x, %y", x, y);
          }
          if (right_error) {
            printf("error en right bits. Parametros: %x, %y", x, y);
          }
          exit(1);
        }
      }
    }
    puts ("Fin de multiplicador-cmp-all.c. Todos los casos ok.");
    return 0;
}


