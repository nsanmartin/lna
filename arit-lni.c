#include "lni.h"



lni_t lni_incr (lni_t i)
{
    if ( i -> pos )
        digit_incr ( i -> pos );
    else
    {
        digit_decr (i -> neg);
        if ( ! i -> neg -> next && ! i -> neg -> num  )
        {
            i -> pos = i -> neg;
            i -> neg = 0x0;
        }
    }
}

lni_t lni_decr (lni_t i)
{
    if ( i -> neg )
        digit_incr ( i -> neg );
    else
    {
        if ( ! i -> pos -> next && ! i -> pos -> num  )
        {
            i -> neg = i -> pos;
            i -> pos = 0x0;
        }
        digit_decr ( i -> pos );
    }
}
