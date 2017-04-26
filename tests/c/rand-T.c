#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main ()
{
    srand(time(NULL));  // should only be called once
    unsigned long long r = rand();
    printf("%ull", r);
}
