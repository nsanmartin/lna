#include <aux-tests.h>
#include <gmp.h>
void gmp_lna_cmp (mpz_t mpz, struct digit * ds)
{
    char * s, * t;
    
    t = mpz_get_str (NULL, 16, mpz);
    s = digits_get_str_hex (ds);
    
    if ( strcmp ( s, t )  == 0) {
      printf ("ok\n");
    }
    else {
      fprintf (stderr, "error en test\n");
      fprintf(stderr, "lna: %s\n", s);
      fprintf(stderr, "gmp: %s\n", t);
      exit(1);
    }
}


    
void gmp_M (mpz_t z)
{
    //mpz_t * z;
    T bits = BITS_OF_T;
    mpz_init_set_ui (z, 2);
    mpz_pow_ui (z, z, bits);
}
  

    
void gmp_from_arr (mpz_t z, T * arr, T len)
{
    if (!len) {
        fprintf(stderr, "gmp_from_arr: error: arr nulo");
        exit(1);
    }
        
    mpz_t M;
    gmp_M(M);
    mpz_init_set_ui (z, arr [0]);
    int i = 1;
    
    for (; i < len; i++) {
        mpz_mul (z, z, M);
        mpz_add_ui (z, z, arr[i]);
    }
}
