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


void digit_print_hex (struct digit * n);
void digit_list_print_hex (struct digit * n);
void print_bin (T x);

void digits_list_lnn_print_dec (struct digit * n);
#endif
