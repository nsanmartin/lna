#ifndef _LNI_H
#define _LNI_H

#include "digit.h"

typedef struct lni_t *lni_t;

struct lni_t {
    digit pos; 
    digit neg; 
    T len;//todo: hacer lnn_t
};


lni_i lni_new_T (T x);
lni_t lni_new_digit_list (digit d);
lni_t lni_copy (lni_t i);

#endif
