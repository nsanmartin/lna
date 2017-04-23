#ifndef _READ_H
#define _READ_H

#include "digit-lnn.h"

lnn_t lnn_t_read_hex (char * s);



unsigned words_in_str (char * s);

char ** split (char * s, unsigned nwords);

lnn_t lnn_new_decimal_string (char * s);

#endif
