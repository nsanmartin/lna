#include "read.h"
#include <ctype.h>
#include "arit.h"
#include <stdio.h>

unsigned words_in_str (char * s)
{
    unsigned nwords = 0;
    char * p = s;

    while ( *p ) {
	while ( isspace(*p) ) p++;
	if ( *p ) nwords++;
	while ( !isspace(*p) && *p )
	p++;
    }
    return nwords;
}

char ** split (char * s, unsigned nwords)
{
    char ** res = malloc (nwords * sizeof(char *) + 1 );
    if (!res) {
        fprintf (stderr, "Not enough memory.\n");
        exit (1);
    }

    char ** r = res;
    char * p = s;
    while ( *p )
    {
        while ( *p && isspace(*p) ) p++;
        if ( *p )
        {
            *r = p;
	    r++;
	    while (*p && !isspace(*p)) p++;
            *p = '\0'; p++;
	}
    }
    *(r + 1) = 0x0;
    return res;
}

lnn_t lnn_new_decimal_string (char * s)
{
    lnn_t res = lnn_new_zero();
    while(*s >= '0' && *s <= '9') {
        lnn_t tmp = res;
        res = lnn_mul_T  ( res, (T) 10 );
        lnn_clear (&tmp);
        lnn_set_add_T ( res, (T) *s - '0');
        s++;
    }
    return res;
}


int string_is_dec (char * s)
{
    while (*s) {
        if (!isdigit(*s)) return 0;
    }
    return 1;
}

int string_is_hex (char * s)
{
    while (*s) {
        if (!isxdigit(*s)) return 0;
    }
    return 1;
}
