#include "../digit.h"
#include <stdio.h>

char * digits_get_str_hex (struct digit * d)
{
    T len = 0;
    while (d -> next) {
        d = d -> next;
        len++;
    }

    char * res = malloc (sizeof(char) * 16 * len + 1);
    int i = sprintf (res, hexPATTERN, d -> num);
    d = d-> prev;
    for (; d ; d = d -> prev) {
        i += sprintf (res + i, hexPATTERNPADDING, d -> num);
    }
    return res;
}
