#ifndef _PRINT_H
#define _PRINT_H

#include "basetype.h"
#include "digit.h"
#include <stdio.h>

#define LONG_HEX_PATTERN "%016llx"
#define CHAR_HEX_PATTERN "%02x"
#define UNSIGNED_HEX_PATTERN "%08x"

#define LONG_PATTERN "%016lld "
#define UNSIGNED_PATTERN "%08d "
#define CHAR_PATTERN "%02d "

//void pr_num (lnn_t * n, void * p) ;//void pr_num (lnn_t * n, void * p) ;

void lnn_print_digit_hex (lnn_t * n, void * p);
//void pr_num_hex (lnn_t * n, void * p);

//void prn0 (char * s, lnn_t * n);

void lnn_print_hex(lnn_t * n);
//void prhex(lnn_t * n);

void lnn_print_bin(T x);
//void prbin(T x);


//void showHex ( lnn_t * n);
#endif
