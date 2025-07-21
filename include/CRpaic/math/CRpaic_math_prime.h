/**
 * File    : CRpaic_math.h
 * Date    : 0000-00-00 00:00 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * Utilities for prime numbers.
 */

/* Start of include guard: */
#ifndef CRPAIC_MATH_PRIME_H
#define CRPAIC_MATH_PRIME_H

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * Predicate: crpaic_is_prime
 * Usage: if (crpaic_is_prime(n)) . . .
 * ------------------------------------
 * Family of predicates (and a _Generic macro) that receive an integer (of
 * various types), signed or unsigned, and return a boolean value indicating
 * whether the integer is prime (true) or not (false). This family of predicates
 * receives an integer value returns a boolean indicating whether the number is
 * prime (true) or not (false).
 * 
 * The user can pass integers of the following type to the macro:
 *    shor int, int, long int, long lont int
 *    unsigned short int, unsiged int, unsigned long int, unsigned long long int
 *    int8_t, int16_t, int32_t, int64_4
 *    uint8_t, uint16_t, uint32_t, uint64_t
 *
 * The following types are not implemented as they do not appear frequently in
 * teaching environments (if the user uses these types, we can get a situation
 * of undefined behavior):
 *    int_fast8_t, int_fast16_t, int_fast32_t, int_fast64_t
 *    uint_fast8_t, uint_fast16_t, uint_fast32_t, uint_fast64_t
 *    int_least8_t, int_least16_t, int_least32_t, int_least64_t
 *    uint_least8_t, uint_least16_t, uint_least32_t, uint_least64_t
 */

/* Declaration of the base function: */
bool crpaic_is_prime_ulli (unsigned long long int n);

/* Definition of wrappers for integer types: */

/* int8_t */
static inline bool crpaic_is_prime_i8 (int8_t n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

/* uint8_t */
static inline bool crpaic_is_prime_ui8 (uint8_t n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

/* int16_t */
static inline bool crpaic_is_prime_i16 (int16_t n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

/* uint16_t */
static inline bool crpaic_is_prime_ui16 (uint16_t n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

/* int32_t */
static inline bool crpaic_is_prime_i32 (int32_t n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

/* uint32_t */
static inline bool crpaic_is_prime_ui32 (uint32_t n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

/* int64_t */
static inline bool crpaic_is_prime_i64 (int64_t n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

/* uint64_t */
static inline bool crpaic_is_prime_ui64 (uint64_t n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

/* Generic macro for the dispatch of correct function: */
#define crpaic_is_prime(x) _Generic((x),           \
             /* standard int types */              \
                  char: crpaic_is_prime_i8,        \
           signed char: crpaic_is_prime_i8,        \
         unsigned char: crpaic_is_prime_ui8,       \
             short int: crpaic_is_prime_i16,       \
    unsigned short int: crpaic_is_prime_ui16,      \
                   int: crpaic_is_prime_i32,       \
          unsigned int: crpaic_is_prime_ui32,      \
              long int: crpaic_is_prime_i64,       \
     unsigned long int: crpaic_is_prime_ui64,      \
         long long int: crpaic_is_prime_i64,       \
unsigned long long int: crpaic_is_prime_ui64,      \
             /* <stdint.h> int types */            \
                int8_t: crpaic_is_prime_i8,        \
               uint8_t: crpaic_is_prime_ui8,       \
               int16_t: crpaic_is_prime_i16,       \
              uint16_t: crpaic_is_prime_ui16,      \
               int32_t: crpaic_is_prime_i32,       \
              uint32_t: crpaic_is_prime_ui32,      \
               int64_t: crpaic_is_prime_i64,       \
              uint64_t: crpaic_is_prime_ui64,      \
             /* fallback */                        \
               default: crpaic_is_prime_ulli)(x)

/**
 * Predicate: crpaic_next_prime
 * Usage: x = crpaic_next_prime(n);
 * --------------------------------
 * Family of functions (and a _Generic macro) that receives an integer n (of
 * various types), signed or unsigned, and return the next prime number greater
 * than n.
 *
 * If n < 2 (including negative numbers), always return 2 (the first positive
 * prime number).
 *
 * if n is so big that there is no more possibility of a next prime in the
 * data type of n, then the function returns 0 as a sentinel value indicating
 * that there is no next prime.
 */

/* Declaration of the base function: */
/* unsigned long long int */
/* crpaic_next_prime_ulli (unsigned long long int n) */
/* { */
/*     while (n < ULLONG_MAX) { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* Definition of wrappers for other primitive integer types: */
/* static inline short int */
/* crpaic_next_prime_si (short int n) */
/* { */
/*     if (n < 2) */
/*         return 2; */

/*     while (n < SHRT_MAX) { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline unsigned short int */
/* crpaic_next_prime_usi (unsigned short int n) */
/* { */
/*     while (n < USHRT_MAX) { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline int */
/* crpaic_next_prime_i (int n) */
/* { */
/*     if (n < 2) */
/*         return 2; */

/*     while (n < INT_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline unsigned int */
/* crpaic_next_prime_ui (unsigned int n) */
/* { */
/*     while (n < UINT_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline long int */
/* crpaic_next_prime_li (long int n) */
/* { */
/*     if (n < 2) */
/*         return 2; */

/*     while (n < LONG_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline unsigned long int */
/* crpaic_next_prime_uli (unsigned long int n) */
/* { */
/*     while (n < ULONG_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline long long int */
/* crpaic_next_prime_lli (long long int n) */
/* { */
/*     if (n < 2) */
/*         return 2; */

/*     while (n < LLONG_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline unsigned long long int */
/* crpaic_next_prime_ulli_safe (unsigned long long int n) */
/* { */
/*     while (n < ULLONG_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* Definition of wrappers for <stdint.h> integer types: */
/* static inline int8_t */
/* crpaic_next_prime_i8 (int8_t n) */
/* { */
/*     if (n < 2) */
/*         return 2; */

/*     while (n < INT8_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline uint8_t */
/* crpaic_next_prime_ui8 (uint8_t n) */
/* { */
/*     while (n < UINT8_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline int16_t */
/* crpaic_next_prime_i16 (int16_t n) */
/* { */
/*     if (n < 2) */
/*         return 2; */

/*     while (n < INT16_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline uint16_t */
/* crpaic_next_prime_ui16 (uint16_t n) */
/* { */
/*     while (n < UINT16_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline int32_t */
/* crpaic_next_prime_i32 (int32_t n) */
/* { */
/*     if (n < 2) */
/*         return 2; */

/*     while (n < INT32_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline uint32_t */
/* crpaic_next_prime_ui32 (uint32_t n) */
/* { */
/*     while (n < UINT32_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline int64_t */
/* crpaic_next_prime_i64 (int64_t n) */
/* { */
/*     if (n < 2) */
/*         return 2; */

/*     while (n < INT64_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* static inline uint64_t */
/* crpaic_next_prime_ui64 (uint64_t n) */
/* { */
/*     while (n < UINT64_MAX) */
/*     { */
/*         if (crpaic_is_prime(++n)) */
/*             return n; */
/*     } */
    
/*     return 0; */
/* } */

/* Generic macro for the dispatch of correct function: */
/*
#define crpaic_next_prime(x) _Generic((x),           \
             / * standard int types * /                \
             short int: crpaic_next_prime_si,        \
    unsigned short int: crpaic_next_prime_usi,       \
                   int: crpaic_next_prime_i,         \
          unsigned int: crpaic_next_prime_ui,        \
              long int: crpaic_next_prime_li,        \
     unsigned long int: crpaic_next_prime_uli,       \
         long long int: crpaic_next_prime_lli,       \
unsigned long long int: crpaic_next_prime_ulli_safe, \
             / * <stdint.h> int types * /              \
                int8_t: crpaic_next_prime_i8,        \
               uint8_t: crpaic_next_prime_ui8,       \
               int16_t: crpaic_next_prime_i16,       \
              uint16_t: crpaic_next_prime_ui16,      \
               int32_t: crpaic_next_prime_i32,       \
              uint32_t: crpaic_next_prime_ui32,      \
               int64_t: crpaic_next_prime_i64,       \
              uint64_t: crpaic_next_prime_ui64,      \
             / * fallback * /                          \
               default: crpaic_next_prime_ulli_safe)(x)
*/

/* End of include guard: */
#endif
