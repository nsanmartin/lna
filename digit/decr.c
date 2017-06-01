#include <arit.h>

void digits_decr (struct digit *d)
{
    //vale d > 0
    while ( d -> num == 0 && d -> next )
    {
        d -> num --;
        d = d -> next;
    }
    if ( d -> num > 1 )
    {
        d -> num --;
    }
    else if ( ! d -> next )//( d -> num == 1 )
    {
        d -> prev -> next = 0x0;
        digits_clear ( &d );
    }
    else
        d -> num --;
}
