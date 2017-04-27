#include "../digit.h"
#include <stdio.h>

char * digits_get_str_hex (struct digit * d)
{
    while (d -> next)
        d = d -> next;
    char const * pattern = "%016llx";
    T len = digits_len (d);
    char * res = malloc (sizeof(char) * 16 + 1);
    int i = sprintf (res, "%llx", d -> num);
    d = d-> prev;
    for (; d ; d = d -> prev) {
        i += sprintf (res + i, pattern, d -> num);
    }
    return res;
}
