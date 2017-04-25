#include "../arit.h"


void digits_incr (struct digit * d)
{
        while ( d -> next && d -> num == (T)~0 )
        {
            d -> num = 0;
            d = d -> next;
        }
        if ( d -> num < (T)~0 )
        {
            d -> num++;
        }
        else if ( d -> next == 0x0 ) // no queda otra, igual
        {
            d -> num = 0;
            d -> next = digits_new ((T) 1);
            d -> next -> prev = d;
        }
}
