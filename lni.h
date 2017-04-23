#ifndef _LNI_H
#define _LNI_H

#include "digit.h"

typedef struct lni_t *lni_t;

struct lni_t {
    digit pos; 
    digit neg; 
    lni_t len;
};

#endif
