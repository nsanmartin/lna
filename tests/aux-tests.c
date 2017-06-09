#include <aux-tests.h>
#include <assert.h>
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

char * rnd_dec_str (unsigned n_digits) {
    FILE * urand = fopen("/dev/urandom", "r");
    unsigned char c;
    char * number_str = malloc (sizeof (char) * n_digits + 1);
    
    for (int i = 0; i < n_digits; i++) {
	c = getc (urand) % 10;
	number_str [i] = '0' + c ;
    }
    number_str [n_digits] = '\0' ;
    fclose(urand);
    return number_str;
}


struct digit * digits_rnd (FILE * urand, T size)
{
    assert (size > 0);
    struct digit * res, * r;
    r = res;
    unsigned char c; // 8 bits
    T x;
    char * p;
    size_t bytes = sizeof(T);
    for (int i = 0; i < size; i++) {
	p = (char *) &x;
       for (int j = 0; j < bytes; j++) {
	   c = getc (urand);
	   p[j] = c;
       }
       if (i == 0) {
	   res = digits_new (x);
	   r = res;
       } else {
	   digits_new_next (r, x);
	   r = r -> next;
       }
       
    }
    
    return res;
}
