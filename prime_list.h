#ifndef _LNI_H
#define _LNI_H

typedef struct prime_list *prime_list;

struct prime_list {
    digit first;
    digit last;
    lni_t len;
};

#endif
