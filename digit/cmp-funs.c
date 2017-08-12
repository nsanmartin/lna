#include <digit.h>
#include <assert.h>

int iszero (struct digit const * d) {
  assert(d);
    return d -> num == 0 && d -> next == 0x0;
}


T length (struct digit * d) {
    T res = 0;
    while (d) {
        res++;
        d = d -> next;
    }
    return res;
}
