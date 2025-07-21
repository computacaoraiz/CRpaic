/**
 * File    : CRpaic_math.h
 * Date    : 2025-07-21 14:12 -0300
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
#include <stdio.h>

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

/* chars */
static inline bool crpaic_is_prime_c (char n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_uc (unsigned char n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

/* short ints */
static inline bool crpaic_is_prime_si (short int n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_usi (unsigned short int n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

/* ints */
static inline bool crpaic_is_prime_i (int n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_ui (unsigned int n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

/* long ints */
static inline bool crpaic_is_prime_li (long int n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

static inline bool crpaic_is_prime_uli (unsigned long int n)
{
    return crpaic_is_prime_ulli((unsigned long long int) n);
}

/* long long ints */
static inline bool crpaic_is_prime_lli (unsigned long long int n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

/* Generic macro for the dispatch of correct function: */
#define crpaic_is_prime(x) _Generic((x),           \
                  char: crpaic_is_prime_c,         \
         unsigned char: crpaic_is_prime_uc,        \
             short int: crpaic_is_prime_si,        \
    unsigned short int: crpaic_is_prime_usi,       \
                   int: crpaic_is_prime_i,         \
          unsigned int: crpaic_is_prime_ui,        \
              long int: crpaic_is_prime_li,        \
     unsigned long int: crpaic_is_prime_uli,       \
         long long int: crpaic_is_prime_lli,       \
unsigned long long int: crpaic_is_prime_ulli,      \
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
 * If n is so big that there is no more possibility of a next prime in the
 * data type range of n, then the function returns 0 as a sentinel value
 * indicating that there is no next prime.
 */

/* chars */
char crpaic_next_prime_c (char n);
unsigned char crpaic_next_prime_uc (unsigned char n);

/* short ints */
short int crpaic_next_prime_si (short int n);
unsigned short int crpaic_next_prime_usi (unsigned short int n);

/* ints */
int crpaic_next_prime_i (int n);
unsigned int crpaic_next_prime_ui (unsigned int n);

/* long ints */
long int crpaic_next_prime_li (long int n);
unsigned long int crpaic_next_prime_uli (unsigned long int n);

/* long long ints */
long long int crpaic_next_prime_lli (long long int n);
unsigned long long int crpaic_next_prime_ulli (unsigned long long int n);

/* Generic macro for the dispatch of correct function: */
#define crpaic_next_prime(x) _Generic((x),         \
                  char: crpaic_next_prime_c,       \
         unsigned char: crpaic_next_prime_uc,      \
             short int: crpaic_next_prime_si,      \
    unsigned short int: crpaic_next_prime_usi,     \
                   int: crpaic_next_prime_i,       \
          unsigned int: crpaic_next_prime_ui,      \
              long int: crpaic_next_prime_li,      \
     unsigned long int: crpaic_next_prime_uli,     \
         long long int: crpaic_next_prime_lli,     \
unsigned long long int: crpaic_next_prime_ulli,    \
               default: crpaic_next_prime_ulli)(x)

/* End of include guard: */
#endif
