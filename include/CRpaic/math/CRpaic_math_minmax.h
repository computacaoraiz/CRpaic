/**
 * File    : CRpaic_math_minmax.h
 * Date    : 2025-07-22 11:40 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * Utilities for identify the maximum or minimum between two numbers.
 */

/* Start of include guard: */
#ifndef CRPAIC_MATH_MINMAX_H
#define CRPAIC_MATH_MINMAX_H

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * Function: crpaic_max
 * Usage: n = crpaic_max(n1, n2);
 * ------------------------------
 * A family of functions (and a _Generic macro) that accept two numbers (of any
 * data type) and return the larger of them. The user can pass the following
 * types of arguments:
 *
 *     a) Signed or unsigned integers: char, short int, int, long int,
 *        long long int, int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t,
 *        int64_t, uint64_t;
 *
 *     b) Floating-point numbers: float, double, long double.
 *
 * The user MUST pass two arguments of the same type (or, at least, two
 * arguments of compatible types, eg.: int and int32_t). If the user passed two
 * arguments of different types, the behavior would be undefined and the return
 * value could be wrong (due to C's type promotion and casting rules). To
 * prevent this, the _Generic dispatch macro verify the type compatibility of
 * the arguments and stop the compilation if the types are different (or not
 * compatible).
 *
 * The function will always return the larger of the two numbers received as an
 * argument. The type of the returned value will always be the same type as the
 * first argument; that is, the type of the first argument determines the type
 * of the returned value.
 */

/* chars */
char
crpaic_max_c (char const n1, char const n2);

unsigned char
crpaic_max_uc (unsigned char const n1, unsigned char const n2);

/* short ints */
short int
crpaic_max_si (short int const n1, short int const n2);

unsigned short int
crpaic_max_usi (unsigned short int const n1, unsigned short int const n2);

/* ints */
int
crpaic_max_i (int const n1, int const n2);

unsigned int
crpaic_max_ui (unsigned int const n1, unsigned int const n2);

/* long ints */
long int
crpaic_max_li (long int const n1, long int const n2);

unsigned long int
crpaic_max_uli (unsigned long int const n1, unsigned long int const n2);

/* long long ints */
long long int
crpaic_max_lli (long long int const n1, long long int const n2);

unsigned long long int
crpaic_max_ulli (unsigned long long int const n1,
                 unsigned long long int const n2);

/* floating-point numbers */
float
crpaic_max_f (float const f1, float const f2);

double
crpaic_max_d (double const d1, double const d2);

long double
crpaic_max_ld (long double const ld1, long double const ld2);

/* Generic macro for the dispatch of correct function: */
#define crpaic_max(x, y) \
    ({  \
        __auto_type __x = (x); \
        __auto_type __y = (y); \
        \
        _Static_assert(__builtin_types_compatible_p(                 \
                       __typeof__(__x), __typeof__(__y)),            \
                       "ERROR: arguments must have the same type."); \
        \
        _Generic((__x),                               \
                  char: crpaic_max_c,                 \
         unsigned char: crpaic_max_uc,                \
             short int: crpaic_max_si,                \
    unsigned short int: crpaic_max_usi,               \
                   int: crpaic_max_i,                 \
          unsigned int: crpaic_max_ui,                \
              long int: crpaic_max_li,                \
     unsigned long int: crpaic_max_uli,               \
         long long int: crpaic_max_lli,               \
unsigned long long int: crpaic_max_ulli,              \
                 float: crpaic_max_f,                 \
                double: crpaic_max_d,                 \
           long double: crpaic_max_ld,                \
               default: crpaic_max_ld)((__x), (__y)); \
    })

/**
 * Function: crpaic_min
 * Usage: n = crpaic_min(n1, n2);
 * ------------------------------
 * A family of functions (and a _Generic macro) that accept two numbers (of any
 * data type) and return the smaller of them. The user can pass the following
 * types of arguments:
 *
 *     a) Signed or unsigned integers: char, short int, int, long int,
 *        long long int, int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t,
 *        int64_t, uint64_t;
 *
 *     b) Floating-point numbers: float, double, long double.
 *
 * The user MUST pass two arguments of the same type (or, at least, two
 * arguments of compatible types, eg.: int and int32_t). If the user passed two
 * arguments of different types, the behavior would be undefined and the return
 * value could be wrong (due to C's type promotion and casting rules). To
 * prevent this, the _Generic dispatch macro verify the type compatibility of
 * the arguments and stop the compilation if the types are different (or not
 * compatible).
 *
 * The function will always return the smaller of the two numbers received as an
 * argument. The type of the returned value will always be the same type as the
 * first argument; that is, the type of the first argument determines the type
 * of the returned value.
 */

/* chars */
char
crpaic_min_c (char const n1, char const n2);

unsigned char
crpaic_min_uc (unsigned char const n1, unsigned char const n2);

/* short ints */
short int
crpaic_min_si (short int const n1, short int const n2);

unsigned short int
crpaic_min_usi (unsigned short int const n1, unsigned short int const n2);

/* ints */
int
crpaic_min_i (int const n1, int const n2);

unsigned int
crpaic_min_ui (unsigned int const n1, unsigned int const n2);

/* long ints */
long int
crpaic_min_li (long int const n1, long int const n2);

unsigned long int
crpaic_min_uli (unsigned long int const n1, unsigned long int const n2);

/* long long ints */
long long int
crpaic_min_lli (long long int const n1, long long int const n2);

unsigned long long int
crpaic_min_ulli (unsigned long long int const n1,
                 unsigned long long int const n2);

/* floating-point numbers */
float
crpaic_min_f (float const f1, float const f2);

double
crpaic_min_d (double const d1, double const d2);

long double
crpaic_min_ld (long double const ld1, long double const ld2);

/* Generic macro for the dispatch of correct function: */
#define crpaic_min(x, y) \
    ({  \
        __auto_type __x = (x); \
        __auto_type __y = (y); \
        \
        _Static_assert(__builtin_types_compatible_p(                 \
                       __typeof__(__x), __typeof__(__y)),            \
                       "ERROR: arguments must have the same type."); \
        \
        _Generic((__x),                               \
                  char: crpaic_min_c,                 \
         unsigned char: crpaic_min_uc,                \
             short int: crpaic_min_si,                \
    unsigned short int: crpaic_min_usi,               \
                   int: crpaic_min_i,                 \
          unsigned int: crpaic_min_ui,                \
              long int: crpaic_min_li,                \
     unsigned long int: crpaic_min_uli,               \
         long long int: crpaic_min_lli,               \
unsigned long long int: crpaic_min_ulli,              \
                 float: crpaic_min_f,                 \
                double: crpaic_min_d,                 \
           long double: crpaic_min_ld,                \
               default: crpaic_min_ld)((__x), (__y)); \
    })

/* End of include guard: */
#endif
