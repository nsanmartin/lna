#include <stdio.h>
#include <gmp.h>
#include <errno.h>
#include <string.h>

#include <print.h>
#include <digit.h>
#include <arit.h>
#include <ctype.h>

/* #include "../print.h" */
/* #include "../digit.h" */
/* #include "../arit.h" */



void gmp_lna_cmp (mpz_t mpz, struct digit * ds);
void gmp_lna_cmp_ask (mpz_t mpz, struct digit * ds, int ok);

void gmp_M (mpz_t z);
void gmp_from_arr (mpz_t z, T * arr, T len);

char * rnd_dec_str (unsigned n_digits);
struct digit * digits_rnd (FILE * urand, T size);
char * filetostr (char const * fname);
