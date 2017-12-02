#include <stdio.h>
#include <errno.h>

#include "../print.h"
#include "../digit.h"


int main(int argc, char ** argv)
{
    if (argc == 1) {
        puts("Usage: prog NUMBER [NUMBER ...]\n");
        return 0;
    }
    if ( *argv[1] == '0') {
      puts("Primer num tiene q ser > 0");
      return 0;
    }
    
    T * x =  malloc (sizeof(T) * (argc - 1));
    unsigned i;
    errno = 0;
    char * tail;
    printf("argc: %d\n",argc);
    for (i = 0; i < argc - 1; i++) {
      x[i] = strtoul (argv[i+1], &tail, 10);
      if (errno) { puts("Numero demasiado grande"); return 0; }
    }

    struct digit * d = digits_new_array(x, argc - 1);
    char * s = digits_get_str_hex (d);
    puts(s);
    return 0;
}
