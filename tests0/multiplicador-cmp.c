#include "tests.h"
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

    /*
    **  | el multiplicador
    **  V
    */
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


    int left_error = mpz_cmp_ui (left, lb);
    int right_error = mpz_cmp_ui (right, rb);

    if (!left_error || !right_error) {
        printf("%x * %x: ok.\n", x, y);
        exit (1);
    }
    else {
        if (left_error) {
            printf("error en left bits. Parametros: %x, %y", x, y);
        }
        if (right_error) {
        printf("error en right bits. Parametros: %x, %y", x, y);
        }
    }
    
    return 0;
}


