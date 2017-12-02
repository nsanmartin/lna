/* Compile with */
/* gcc -o add-gmp add-gmp.c -lgmp -lm */

#include <stdio.h>			/* for printf */
#include <gmp.h>
 
int main(int argc, char *argv[])
{
  mpz_t a, b;                 		/* working numbers */
  if (argc != 2)
    {					/* not enough words */
    printf("usage: PROG NUM\n");
    return 1;
  }

  char * s = argv[1];
  int i = mpz_init_set_str (a, s, 10);
  gmp_printf ("s: `%s'\ni: %d\n%Zx\n", s, i, a);

  return 0;
}
