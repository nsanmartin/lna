#include <stdio.h>
#include "../print.h"
#include "../digit.h"
#include "../arit.h"

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
	puts("Usage: factorial NUMBER\n");
	return 0;
    }

    unsigned long long xll = atoll(argv[1]);
    T x = (T) xll;
            
    endl;
    return 0;
}
