/**
 * File    : CRpaic_math.h
 * Date    : 0000-00-00 00:00 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file creates the "CRpaic_math.h" interface, a module for general
 * math utilities and functions used by CRpaic library. The main objective of
 * this header is to include other math headers.
 */

/* Start of include guard: */
#ifndef CRPAIC_MATH_H
#define CRPAIC_MATH_H

#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#include <CRpaic/math/CRpaic_math_const.h>
#include <CRpaic/math/CRpaic_math_prime.h>

/**
 * Function: crpaic_max
 * Usage: n = (crpaic_max(a, b));
 * ------------------------------
 * Family of functions (and a _Generic macro) that receive two numbers of the
 * same type and returns the greatest number between these two.
 * 
 * The user can pass integers of the following type to the macro:
 *    shor int, int, long int, long lont int
 *    unsigned short int, unsiged int, unsigned long int, unsigned long long int
 *    int8_t, int16_t, int32_t, int64_4
 *    uint8_t, uint16_t, uint32_t, uint64_t
 *
 * The user can pass floating pointing numbers of the following type to the
 * macro:
 *    float, double, long double
 *
 * The following types are not implemented as they do not appear frequently in
 * teaching environments (if the user uses these types, we can get a situation
 * of undefined behavior):
 *    complex, imaginary
 */

/* Declaration of the base function for integer types: */
long long
crpaic_max_i (long long int n1, long long int n2);

unsigned long long
crpaic_max_ui (unsigned long long int n1, unsigned long long int n2);

/* Declaration of the base function for floating types: */
long double crpaic_max_f (long double d1, long double d2);

/* Definition of wrappers for other primitive integer types: */
static inline bool crpaic_max_prime_si (short int n)
{
    return n < 2 ? false : crpaic_is_prime_ulli((unsigned long long int) n);
}

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

/* End of include guard: */
#endif
