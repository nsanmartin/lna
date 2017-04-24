#include "lni.h"

lni_i lni_new_T (T x)
{
    lni_t res = malloc (sizeof (lni_t));
    if (!res) {
        fprintf (stderr, "Not enough memory.\n");
        exit (1);
    }
    res -> pos = digit_new (x);
    res -> neg = 0x0;
    lni_len = digit_new (1);
}


lni_t lni_new_digit_list (digit d)
{
    lni_t res = malloc (sizeof (lni_t));
    if (!res) {
        fprintf (stderr, "Not enough memory.\n");
        exit (1);
    }

    res -> pos = digit_list_copy (d);
    res -> neg = 0x0;
    res -> len = digit_list_len (d);
    
}
lni_t lni_copy (lni_t i);
