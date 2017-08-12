#ifndef _BASE_TYPE_H
#define _BASE_TYPE_H



#define LENGTH(x) (sizeof(x)/sizeof(*x))
#define endl printf("\n");

typedef unsigned long long T;
#define PRINT_NUM_DEC(num) printf( LONG_PATTERN, (num))
#define PRINT_NUM_HEX(num) printf( LONG_HEX_PATTERN, (num))
#define PATTERN "%lld"
#define hexPATTERN "%llx"
#define hexPATTERNPADDING "%016llx"
#define FORMAT "%lld"
#define hexFORMAT "%llx"

#define  BITS_OF_T (sizeof(T) * 8)


#endif
