/**
 * File    : CRpaic_math.h
 * Date    : 0000-00-00 00:00 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file creates the "CRpaic_math.h" interface, a module for general
 * math utilities and functions used by CRpaic library.
 */

#ifndef CRPAIC_MATH_H
#define CRPAIC_MATH_H

#include <stdbool.h>
#include <stdint.h>
#include <CRpaic_globals.h>

/**
 * Mathematical Constants:
 * -----------------------
 * Several important mathematical constants, defined as symbolic constants. The
 * constants have 30 significant digits (1 integer digit and 29 decimal digits),
 * which is probably much more accurate than you will ever need. For more
 * information about the number of decimals digits, see:
 * https://www.jpl.nasa.gov/edu/news/how-many-decimals-of-pi-do-we-really-need
 *
 * All constants (except PHI) were copied from the GNU Scientific Library (GSL).
 */

#ifndef CRPAIC_PHI
#define CRPAIC_PHI      1.61803398874989484820458683436    /* phi */
#endif

#ifndef CRPAIC_E
#define CRPAIC_E        2.71828182845904523536028747135    /* e */
#endif

#ifndef CRPAIC_LOG2E
#define CRPAIC_LOG2E    1.44269504088896340735992468100    /* log_2 (e) */
#endif

#ifndef CRPAIC_LOG10E
#define CRPAIC_LOG10E   0.43429448190325182765112891892    /* log_10 (e) */
#endif

#ifndef CRPAIC_SQRT2
#define CRPAIC_SQRT2    1.41421356237309504880168872421    /* sqrt(2) */
#endif

#ifndef CRPAIC_SQRT1_2
#define CRPAIC_SQRT1_2  0.70710678118654752440084436210    /* sqrt(1/2) */
#endif

#ifndef CRPAIC_SQRT3
#define CRPAIC_SQRT3    1.73205080756887729352744634151    /* sqrt(3) */
#endif

#ifndef CRPAIC_PI
#define CRPAIC_PI       3.14159265358979323846264338328    /* pi */
#endif

#ifndef CRPAIC_PI_2
#define CRPAIC_PI_2     1.57079632679489661923132169164    /* pi/2 */
#endif

#ifndef CRPAIC_PI_4
#define CRPAIC_PI_4     0.78539816339744830961566084582    /* pi/4 */
#endif

#ifndef CRPAIC_SQRTPI
#define CRPAIC_SQRTPI   1.77245385090551602729816748334    /* sqrt(pi) */
#endif

#ifndef CRPAIC_2_SQRTPI
#define CRPAIC_2_SQRTPI 1.12837916709551257389615890312    /* 2/sqrt(pi) */
#endif

#ifndef CRPAIC_1_PI
#define CRPAIC_1_PI     0.31830988618379067153776752675    /* 1/pi */
#endif

#ifndef CRPAIC_2_PI
#define CRPAIC_2_PI     0.63661977236758134307553505349    /* 2/pi */
#endif

#ifndef CRPAIC_LN10
#define CRPAIC_LN10     2.30258509299404568401799145468    /* ln(10) */
#endif

#ifndef CRPAIC_LN2
#define CRPAIC_LN2      0.69314718055994530941723212146    /* ln(2) */
#endif

#ifndef CRPAIC_LNPI
#define CRPAIC_LNPI     1.14472988584940017414342735135    /* ln(pi) */
#endif

#ifndef CRPAIC_EULER
#define CRPAIC_EULER    0.57721566490153286060651209008    /* Euler constant */
#endif

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

/* Definition of wrappers for other primitive integer types: */
static inline bool crpaic_is_prime_si (short int n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_usi (unsigned short int n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_i (int n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_ui (unsigned int n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_li (long int n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_uli (unsigned long int n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_lli (long long int n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_ulli_safe (unsigned long long int n)
{
    return crpaic_is_prime_ulli(n);
}

/* Definition of wrappers for <stdint.h> integer types: */
static inline bool crpaic_is_prime_i8 (int8_t n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_ui8 (uint8_t n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_i16 (int16_t n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_ui16 (uint16_t n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_i32 (int32_t n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_ui32 (uint32_t n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_i64 (int64_t n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_ui64 (uint64_t n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

/* Generic macro for the dispatch of correct function: */
#define crpaic_is_prime(x) _Generic((x),           \
             /* standard int types */              \
             short int: crpaic_is_prime_si,        \
    unsigned short int: crpaic_is_prime_usi,       \
                   int: crpaic_is_prime_i,         \
          unsigned int: crpaic_is_prime_ui,        \
              long int: crpaic_is_prime_li,        \
     unsigned long int: crpaic_is_prime_uli,       \
         long long int: crpaic_is_prime_lli,       \
unsigned long long int: crpaic_is_prime_ulli_safe, \
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
               default: crpaic_is_prime_ulli_safe)(x)

/**
 * Predicate: crpaic_is_even
 * Use: if (crpaic_is_even(n)) . . .
 * ---------------------------------
 * Receives a long long int number "n" and returns a boolean value indicating
 * whether "n" is even (true) of not (false).
 */

bool
crpaic_is_even (const long long int n);

/**
 * Predicate: crpaic_is_odd
 * Use: if (crpaic_is_odd(n)) . . .
 * --------------------------------
 * Receives a long long int number "n" and returns a boolean value indicating
 * whether "n" is odd (true) of not (false).
 */

bool
crpaic_is_odd (const long long int n);

/**
 * Function: crpaic_gcd
 * Usage: i = crpaic_gcd(a, b);
 * ----------------------------
 * Receives two integers, a and b, and returns the greatest common divisor
 * between them.
 */

int
crpaic_gcd (int a, int b);

#endif
