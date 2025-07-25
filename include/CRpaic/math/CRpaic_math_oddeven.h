/**
 * File    : CRpaic_math_oddeven.h
 * Date    : 2025-07-24 21:57 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * Utilities for identify odd and even numbers.
 */

/* Start of include guard: */
#ifndef CRPAIC_MATH_ODDEVEN_H
#define CRPAIC_MATH_ODDEVEN_H

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * Predicate: crpaic_is_even
 * Usage: if(crpaic_is_even(n)) . . .
 * ----------------------------------
 * A family of predicates (and a _Generic macro) that accept an integer number
 * (of any integer data type) and return true if the number is even or return
 * false otherwise.  The user can pass the following types of arguments:
 *
 *     a) Signed or unsigned integers: char, short int, int, long int,
 *        long long int, int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t,
 *        int64_t, uint64_t;
 */

/* chars */
bool
crpaic_is_even_c (char const n);

bool
crpaic_is_even_uc (unsigned char const n);

/* short ints */
bool
crpaic_is_even_si (short int const n);

bool
crpaic_is_even_usi (unsigned short int const n);

/* ints */
bool
crpaic_is_even_i (int const n);

bool
crpaic_is_even_ui (unsigned int const n);

/* long ints */
bool
crpaic_is_even_li (long int const n);

bool
crpaic_is_even_uli (unsigned long int const n);

/* long long ints */
bool
crpaic_is_even_lli (long long int const n);

bool
crpaic_is_even_ulli (unsigned long long int const n);

/* Generic macro for the dispatch of correct function: */
#define crpaic_is_even(x) \
    ({  \
        __auto_type __x = (x); \
        \
        _Static_assert(                                                        \
        __builtin_types_compatible_p(__typeof__(__x), char)                 || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned char)        || \
        __builtin_types_compatible_p(__typeof__(__x), short int)            || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned short int)   || \
        __builtin_types_compatible_p(__typeof__(__x), int)                  || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned int)         || \
        __builtin_types_compatible_p(__typeof__(__x), long int)             || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned long int)    || \
        __builtin_types_compatible_p(__typeof__(__x), long long int)        || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned long long int), \
                       "ERROR: argument must be an integer type.");            \
        \
        _Generic((__x),                              \
                  char: crpaic_is_even_c,            \
         unsigned char: crpaic_is_even_uc,           \
             short int: crpaic_is_even_si,           \
    unsigned short int: crpaic_is_even_usi,          \
                   int: crpaic_is_even_i,            \
          unsigned int: crpaic_is_even_ui,           \
              long int: crpaic_is_even_li,           \
     unsigned long int: crpaic_is_even_uli,          \
         long long int: crpaic_is_even_lli,          \
unsigned long long int: crpaic_is_even_ulli,         \
               default: crpaic_is_even_ulli)((__x)); \
    })

/**
 * Predicate: crpaic_is_odd
 * Usage: if(crpaic_is_odd(n)) . . .
 * ---------------------------------
 * A family of predicates (and a _Generic macro) that accept an integer number
 * (of any integer data type) and return true if the number is odd or return
 * false otherwise.  The user can pass the following types of arguments:
 *
 *     a) Signed or unsigned integers: char, short int, int, long int,
 *        long long int, int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t,
 *        int64_t, uint64_t;
 */

/* chars */
bool
crpaic_is_odd_c (char const n);

bool
crpaic_is_odd_uc (unsigned char const n);

/* short ints */
bool
crpaic_is_odd_si (short int const n);

bool
crpaic_is_odd_usi (unsigned short int const n);

/* ints */
bool
crpaic_is_odd_i (int const n);

bool
crpaic_is_odd_ui (unsigned int const n);

/* long ints */
bool
crpaic_is_odd_li (long int const n);

bool
crpaic_is_odd_uli (unsigned long int const n);

/* long long ints */
bool
crpaic_is_odd_lli (long long int const n);

bool
crpaic_is_odd_ulli (unsigned long long int const n);

/* Generic macro for the dispatch of correct function: */
#define crpaic_is_odd(x) \
    ({  \
        __auto_type __x = (x); \
        \
        _Static_assert(                                                        \
        __builtin_types_compatible_p(__typeof__(__x), char)                 || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned char)        || \
        __builtin_types_compatible_p(__typeof__(__x), short int)            || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned short int)   || \
        __builtin_types_compatible_p(__typeof__(__x), int)                  || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned int)         || \
        __builtin_types_compatible_p(__typeof__(__x), long int)             || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned long int)    || \
        __builtin_types_compatible_p(__typeof__(__x), long long int)        || \
        __builtin_types_compatible_p(__typeof__(__x), unsigned long long int), \
                       "ERROR: argument must be an integer type.");            \
        \
        _Generic((__x),                             \
                  char: crpaic_is_odd_c,            \
         unsigned char: crpaic_is_odd_uc,           \
             short int: crpaic_is_odd_si,           \
    unsigned short int: crpaic_is_odd_usi,          \
                   int: crpaic_is_odd_i,            \
          unsigned int: crpaic_is_odd_ui,           \
              long int: crpaic_is_odd_li,           \
     unsigned long int: crpaic_is_odd_uli,          \
         long long int: crpaic_is_odd_lli,          \
unsigned long long int: crpaic_is_odd_ulli,         \
               default: crpaic_is_odd_ulli)((__x)); \
    })

/* End of include guard: */
#endif
