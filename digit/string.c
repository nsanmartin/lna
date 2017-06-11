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

    len *= 16;
    T tmp = d -> num;
    while (tmp)  { len++; tmp /=10; }
    char * res = malloc (sizeof(char) * len + 1);
    int i = sprintf (res, hexPATTERN, d -> num);
    d = d-> prev;
    for (; d ; d = d -> prev) {
        i += sprintf (res + i, hexPATTERNPADDING, d -> num);
    }
    res [i] = '\0';
    return res;
}
