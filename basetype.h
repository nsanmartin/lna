#ifndef _BASE_TYPE_H
#define _BASE_TYPE_H

#define LENGTH(x) (sizeof(x)/sizeof(*x))
#define endl printf("\n");


#if 0
typedef unsigned char T;
#define PRINT_DIGIT(num) printf( CHAR_PATTERN, (num))
#define PRINT_DIGIT_HEX(num) printf( CHAR_HEX_PATTERN, (num)) 
#define PATTERN "%d"
#define hexPATTERN "%x"
#define FORMAT "%d"
#define hexFORMAT "%x"

#elif 0
typedef unsigned T;
#define PRINT_DIGIT(num) printf( UNSIGNED_PATTERN, (num))
#define PRINT_DIGIT_HEX(num) printf( UNSIGNED_HEX_PATTERN, (num)) 
#define PATTERN "%d"
#define hexPATTERN "%x"
#define FORMAT "%d"
#define hexFORMAT "%x"


#else 
typedef unsigned long long T;
#define PRINT_NUM_DEC(num) printf( LONG_PATTERN, (num))
#define PRINT_NUM_HEX(num) printf( LONG_HEX_PATTERN, (num))
#define PATTERN "%lld"
#define hexPATTERN "%llx"
#define FORMAT "%lld"
#define hexFORMAT "%llx"

#endif 


#define BITS_OF_T sizeof(T) * 8

#endif
