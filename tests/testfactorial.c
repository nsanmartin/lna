#include <stdio.h>
#include "../print.h"
#include "../digit-lnn.h"
#include "../arit.h"

T factorial_T (T x);

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
	puts("Usage: factorial NUMBER\n");
	return 0;
    }

    unsigned long long xll = atoll(argv[1]);
    T x = (T) xll;
            
    //lnn_t nx = lnn_new_T (x);
    lnn_t p = lnn_factorial_T(x);
    lnn_print_hex (p);
    if (x > 20) printf("L");
    endl;
    return 0;
}

T factorial_T (T x)
{
    T res = 1;
    while (x)  res *= x--;
    return res;
}
