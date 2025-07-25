/**
 * File    : CRpaic_math_oddeven.c
 * Date    : 2025-07-24 21:57 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file implements the "CRpaic_math_oddeven.h" interface, a module for
 * general utilities about even and odd numbers.
 */

#include <stdbool.h>
#include <CRpaic/math/CRpaic_math_oddeven.h>

/**
 * Predicate: crpaic_is_even
 * Usage: if(crpaic_is_even(n)) . . .
 * ----------------------------------
 * Returns true if the integer argument "n" is even, or false otherwise.
 */

/* chars */
bool
crpaic_is_even_c (char const n)
{
    return (n % ((char) 2) == 0) ? true : false;
}

bool
crpaic_is_even_uc (unsigned char const n)
{
    return (n % ((unsigned char) 2) == 0) ? true : false;
}

/* short ints */
bool
crpaic_is_even_si (short int const n)
{
    return (n % ((short) 2) == 0) ? true : false;
}

bool
crpaic_is_even_usi (unsigned short int const n)
{
    return (n % ((unsigned short) 2) == 0) ? true : false;
}

/* ints */
bool
crpaic_is_even_i (int const n)
{
    return (n % 2 == 0) ? true : false;
}

bool
crpaic_is_even_ui (unsigned int const n)
{
    return (n % 2U == 0) ? true : false;
}

/* long ints */
bool
crpaic_is_even_li (long int const n)
{
    return (n % 2L == 0) ? true : false;
}

bool
crpaic_is_even_uli (unsigned long int const n)
{
    return (n % 2LU == 0) ? true : false;
}

/* long long ints */
bool
crpaic_is_even_lli (long long int const n)
{
    return (n % 2LL == 0) ? true : false;
}

bool
crpaic_is_even_ulli (unsigned long long int const n)
{
    return (n % 2LLU == 0) ? true : false;
}

/**
 * Predicate: crpaic_is_odd
 * Usage: if(crpaic_is_odd(n)) . . .
 * ---------------------------------
 * Returns true if the integer argument "n" is odd, or false otherwise.
 */

/* chars */
bool
crpaic_is_odd_c (char const n)
{
    return (n % ((char) 2) != 0) ? true : false;
}

bool
crpaic_is_odd_uc (unsigned char const n)
{
    return (n % ((unsigned char) 2) != 0) ? true : false;
}

/* short ints */
bool
crpaic_is_odd_si (short int const n)
{
    return (n % ((short) 2) != 0) ? true : false;
}

bool
crpaic_is_odd_usi (unsigned short int const n)
{
    return (n % ((unsigned short) 2) != 0) ? true : false;
}

/* ints */
bool
crpaic_is_odd_i (int const n)
{
    return (n % 2 != 0) ? true : false;
}

bool
crpaic_is_odd_ui (unsigned int const n)
{
    return (n % 2U != 0) ? true : false;
}

/* long ints */
bool
crpaic_is_odd_li (long int const n)
{
    return (n % 2L != 0) ? true : false;
}

bool
crpaic_is_odd_uli (unsigned long int const n)
{
    return (n % 2LU != 0) ? true : false;
}

/* long long ints */
bool
crpaic_is_odd_lli (long long int const n)
{
    return (n % 2LL != 0) ? true : false;
}

bool
crpaic_is_odd_ulli (unsigned long long int const n)
{
    return (n % 2LLU != 0) ? true : false;
}
