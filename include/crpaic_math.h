/**
 * File    : crpaic_math.h
 * Date    : 0000-00-00 00:00 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file creates the "crpaic_math.h" interface, a module for general
 * math utilities and functions.
 */

#ifndef CRPAIC_MATH_H
#define CRPAIC_MATH_H

#include <crpaic_globals.h>

/**
 * Symbolic Constant: CRPAIC_PI
 * ----------------------------
 * Just PI with 15 decimal places. For all practical purposes, this is all
 * decimals places that will be necessary. For more information, see:
 * https://www.jpl.nasa.gov/edu/news/how-many-decimals-of-pi-do-we-really-need
 */

#define CRPAIC_PI 3.141592653589793

/**
 * Symbolic Constante: CRPAIC_PHI
 * ------------------------------
 * Just PHI, the golden ratio, with 15 decimal places. Two quantities are in the
 * golden ratio if their ratio is the same as the ratio of their sum to the
 * larger of the two quantities. For quantities "a > b > 0", "a" is in a golden
 * ratio with "b" if
 *                    (a + b) = a = PHI,
 *                    -------   -
 *                       a      b
 * where PHI denotes the golden ratio. The constant PHI satisfies the quadratic
 * equation "PHI^2 = PHI + 1" and is an irrational number with a value of
 *                    PHI = 1 + 5^(1/2)
 *                          -----------
 *                               2
 * For more information, see: https://oeis.org/A001622
 */

#define CRPAIC_PHI 1.618033988749894

/**
 * Predicate: crpaic_is_prime
 * Use: if (crpaic_is_prime(n)) . . .
 * ----------------------------------
 * Receives a non-negative long long int number "n" and returns a boolean value
 * indicating whether "n" is prime (true) or not (false). For n <= 1, always
 * return false.
 */

bool
crpaic_is_prime (const long long int n);

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

#endif
