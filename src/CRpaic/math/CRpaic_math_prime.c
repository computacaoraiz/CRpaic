/**
 * File    : CRpaic_math_prime.c
 * Date    : 2025-07-24 20:21 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file implements the "CRpaic_math_prime.h" interface, a module for
 * general utilities about prime numbers.
 */

#include <errno.h>
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

/**
 * Functions: crpaic_next_prime_*
 * Usage: n = crpaic_next_prime_*(n);
 * ----------------------------------
 * Functions that receive an integer and returns the first prime number greater
 * than n. If there are no such prime number, returns 0.
 */

char
crpaic_next_prime_c (char n)
{
    if (n < 2)
        return 2;

    while (n < CHAR_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}

unsigned char
crpaic_next_prime_uc (unsigned char n)
{
    while (n < UCHAR_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}

short int
crpaic_next_prime_si (short int n)
{
    if (n < 2)
        return 2;

    while (n < SHRT_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}

unsigned short int
crpaic_next_prime_usi (unsigned short int n)
{
    while (n < USHRT_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}

int
crpaic_next_prime_i (int n)
{
    if (n < 2)
        return 2;

    while (n < INT_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}

unsigned int
crpaic_next_prime_ui (unsigned int n)
{
    while (n < UINT_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}

long int
crpaic_next_prime_li (long int n)
{
    if (n < 2)
        return 2;

    while (n < LONG_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}

unsigned long int
crpaic_next_prime_uli (unsigned long int n)
{
    while (n < ULONG_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}

long long int
crpaic_next_prime_lli (long long int n)
{
    if (n < 2)
        return 2;

    while (n < LLONG_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}

unsigned long long int
crpaic_next_prime_ulli (unsigned long long int n)
{
    while (n < ULLONG_MAX)
    {
        if (crpaic_is_prime(++n))
            return n;
    }

    errno = ERANGE;
    return 0;
}
