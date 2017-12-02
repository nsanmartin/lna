#include <stdio.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <errno.h>
#include <gmp.h>
#include <aux-tests.h>

int main(int argc, char ** argv)
{
    if (argc != 1) { puts("Usage: prog\n"); return 0; }


    /*
    **
    **   div:
    **
    */

    printf ("size of T : %llu\n", sizeof(T));
    
    struct digit * d;
    char const * numero = strdup("257");
    
    digits_init_set_decimal_string(&d, numero);
    T x = 2;
    digits_print_hex(d);
    T len = 0;
    struct digit *p = d;
    int i=0;
    while (p) {
      len++;
      printf("i: %d  num: %u", i++, p->num);
      p=p->next;
    }

    printf("\nlen: %u\t la cuenta\n", len);

    digits_set_div_ui (d, x);
    digits_print_hex(d);
    
    return 0;
}
