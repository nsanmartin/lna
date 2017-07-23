#include <digit.h>
#include <stdio.h>
#include <assert.h>
char * digits_get_str_hex (struct digit * d)
{
    assert(d);
    T len = 0;
    while (d -> next) {
        d = d -> next;
        len++;
    }

    len *= 2*BITS_OF_T;//16;
    T tmp = d -> num;
    while (tmp)  { len++; tmp /= 10; }
    char * res = malloc (sizeof(char) * len + 1);
    T i = sprintf (res, hexPATTERN, d -> num);
    d = d-> prev;
    while ( d ) {
        i += sprintf (res + i, hexPATTERNPADDING, d -> num);
        d = d -> prev;
    }
    res [i] = '\0';
    return res;
}
