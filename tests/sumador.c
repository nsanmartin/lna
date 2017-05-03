#include "aux-tests.h"
/* compilar con:
 * gcc ../digit/*.c suma.c -o suma -lgmp -lm
 *
 */


int main(int argc, char ** argv)
{
    if (argc != 3) {
      puts("Usage: prog NUMBER X NUMBER Y NUMBER CARRY\n");
      return 0; }

    T x, y, sum, carry;

    errno = 0;
    char * tail;
    x = strtoul (argv[1], &tail, 10);
    if (errno) { puts("primer numero demasiado grande"); return 0; }
    y = strtoul (argv[2], &tail, 10);
    if (errno) { puts("segundo numero demasiado grande"); return 0; }

    /*
    **  | el sumador
    **  V
    */
    sumador (x, y, &sum, &carry);

    T bits = BITS_OF_T;
    
    mpz_t mpz_suma, mpz_carry, M, suma_posta;

    mpz_init (mpz_suma); 
    mpz_init (mpz_carry);
    
    mpz_init_set_ui (M, 2);
    mpz_pow_ui (M, M, bits);
    
    mpz_init_set_ui (suma_posta, x);
    mpz_add_ui (suma_posta, suma_posta, y);
    
    mpz_mod (mpz_suma, suma_posta, M);
    mpz_fdiv_q (mpz_carry, suma_posta, M);


    /* printf("lna: sum: \t%llx\tcarry:\t\t%llx\n", sum, carry); */
    /* gmp_printf ("gmp: mpz_suma:\t%Zx\tmpz_carry:\t%Zx\n", */
    /*             mpz_suma, mpz_carry); */

    if (!mpz_cmp_ui (mpz_suma, sum))
      puts("ok.");
    else {
      fprintf(stderr, "error con suma!!\n");
    }
    if (!mpz_cmp_ui (mpz_carry, carry))
      puts("ok.");
    else {
      fprintf(stderr, "error con carry!!\n");
    }
        
    
    return 0;
}


