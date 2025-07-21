/**
 * File    : CRpaic_math_prime.c
 * Date    : 0000-00-00 00:00 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file implements the "CRpaic_math_prime.h" interface, a module for
 * general utilities about prime numbers.
 */

#include <CRpaic/math/CRpaic_math_prime.h>

/**
 * Predicate: crpaic_is_prime_ulli
 * Usage: if (crpaic_is_prime_ulli(n)) . . .
 * -----------------------------------------
 * This predicate receives an unsigned long long int (uint64_t) "n" and returns
 * TRUE if n is prime, and FALSE otherwise. The prime verification uses the
 * "6k +- 1" algorithm.
 */
 
bool crpaic_is_prime_ulli (unsigned long long int n)
{
    if (n < 2)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (unsigned long long int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
