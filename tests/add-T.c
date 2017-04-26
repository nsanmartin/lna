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

void print (char * msg, struct digit * d);

int main(int argc, char ** argv)
{
    if (argc != 3) { puts("Usage: prog NUMBER\n"); return 0; }

    T x, y;
    errno = 0;
    char * tail;
    x = strtoul (argv[1], &tail, 10);
    if (errno) { puts("primer numero demasiado grande"); return 0; }
    y = strtoul (argv[2], &tail, 10);
    if (errno) { puts("segundo numero demasiado grande"); return 0; }

    /* mpz_t a, M, p, mpz_suma; */
    /* mpz_init_set_ui (mpz_suma, x); */
    /* mpz_add_ui (mpz_suma, mpz_suma, y); */
    /* gmp_printf ("resultado %#Zx\n", mpz_suma);  */
    
    /* mpz_init_set_ui(M, ~0); */
    /* mpz_add_ui (M, M, 1); */
    /* //gmp_printf ("2^64: %#Zx\n", M);  */
    
    /* mpz_init_set_str (a, argv[1], 10); */
    /* mpz_add_ui (a, a, y); */

    /* mpz_mod(p, a, M); */
    /* puts("suma % 2^64 - 1:"); */
    /* gmp_printf ("\tgmp: %#Zx\n", p);  */
    

    /* T suma, carry; */
    /* sumador (x, y, 0, &suma, &carry); */
    /* printf ("\tlna: 0x"hexPATTERN, suma); */

    /* if (mpz_cmp(a, M) > 0) { */
    /*     puts("\nsuma > m"); */
    /*     gmp_printf ("\tgmp:M: %#Zx\n", M);  */
        
    /*     mpz_fdiv_q (p, mpz_suma, M); */
    /*     // mpz_sub_ui (p, a, 1); */
    /* } else { */
    /*     puts("\nsuma <= m"); */
    /*     mpz_set_ui (p, 0L); */
    /* } */
    /* puts("\nel carry:"); */
    /* gmp_printf ("\tgmp: %#Zx\n", p);  */
    /* printf ("\tlna: 0x"hexPATTERN, carry); */
    
    return 0;
}
