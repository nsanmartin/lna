#include <stdio.h>
//#include <gmp.h>
#include <string.h>
#include <print.h>
#include <digit.h>
#include <arit.h>
#include <aux-tests.h>


int main(int argc, char ** argv)
{
  
    if (argc != 2) {
        puts("Usage: prog NUMBER\n");return 0;
    }
    char const * fst  = strdup(argv[1]);
    
    struct digit * d, * copia;
    
    digits_init_set_decimal_string(&d, fst );
    
    /*
    **
    **    Copio:
    **
    */

    digits_copy (&copia, d);
    char * s, *t; 
    s = digits_get_str_hex (d);
    t = digits_get_str_hex (copia);

    if (strcmp(s,t) != 0){
      puts("error en copy");
      puts(s);puts(t);
      exit(1);
    } else
      puts("ok");
    

}
