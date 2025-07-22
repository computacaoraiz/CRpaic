/**
 * File    : CRpaic_math_minmax.c
 * Date    : 2025-07-22 11:40 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file implements the "CRpaic_math_minmax.h" interface, a simple utility
 * for identify the maximum or minimum between two numbers.
 */

#include <CRpaic/math/CRpaic_math_minmax.h>

/**
 * Function: crpaic_max
 * Usage: n = crpaic_max(n1, n2);
 * ------------------------------
 * Return the greater of two arguments.
 */

/* chars */
char
crpaic_max_c (char const n1, char const n2)
{
    return n1 > n2 ? n1 : n2;
}

unsigned char
crpaic_max_uc (unsigned char const n1, unsigned char const n2)
{
    return n1 > n2 ? n1 : n2;
}

/* short ints */
short int
crpaic_max_si (short int const n1, short int const n2)
{
    return n1 > n2 ? n1 : n2;
}

unsigned short int
crpaic_max_usi (unsigned short int const n1, unsigned short int const n2)
{
    return n1 > n2 ? n1 : n2;
}

/* ints */
int
crpaic_max_i (int const n1, int const n2)
{
    return n1 > n2 ? n1 : n2;
}

unsigned int
crpaic_max_ui (unsigned int const n1, unsigned int const n2)
{
    return n1 > n2 ? n1 : n2;
}

/* long ints */
long int
crpaic_max_li (long int const n1, long int const n2)
{
    return n1 > n2 ? n1 : n2;
}

unsigned long int
crpaic_max_uli (unsigned long int const n1, unsigned long int const n2)
{
    return n1 > n2 ? n1 : n2;
}

/* long long ints */
long long int
crpaic_max_lli (long long int const n1, long long int const n2)
{
    return n1 > n2 ? n1 : n2;
}

unsigned long long int
crpaic_max_ulli (unsigned long long int const n1,
                 unsigned long long int const n2)
{
    return n1 > n2 ? n1 : n2;
}

/* floating-point numbers */
float
crpaic_max_f (float const f1, float const f2)
{
    return f1 > f2 ? f1 : f2;
}

double
crpaic_max_d (double const d1, double const d2)
{
    return d1 > d2 ? d1 : d2;
}

long double
crpaic_max_ld (long double const ld1, long double const ld2)
{
    return ld1 > ld2 ? ld1 : ld2;
}

/**
 * Function: crpaic_min
 * Usage: n = crpaic_min(n1, n2);
 * ------------------------------
 * Return the smaller of two arguments.
 */

/* chars */
char
crpaic_min_c (char const n1, char const n2)
{
    return n1 < n2 ? n1 : n2;
}

unsigned char
crpaic_min_uc (unsigned char const n1, unsigned char const n2)
{
    return n1 < n2 ? n1 : n2;
}

/* short ints */
short int
crpaic_min_si (short int const n1, short int const n2)
{
    return n1 < n2 ? n1 : n2;
}

unsigned short int
crpaic_min_usi (unsigned short int const n1, unsigned short int const n2)
{
    return n1 < n2 ? n1 : n2;
}

/* ints */
int
crpaic_min_i (int const n1, int const n2)
{
    return n1 < n2 ? n1 : n2;
}

unsigned int
crpaic_min_ui (unsigned int const n1, unsigned int const n2)
{
    return n1 < n2 ? n1 : n2;
}

/* long ints */
long int
crpaic_min_li (long int const n1, long int const n2)
{
    return n1 < n2 ? n1 : n2;
}

unsigned long int
crpaic_min_uli (unsigned long int const n1, unsigned long int const n2)
{
    return n1 < n2 ? n1 : n2;
}

/* long long ints */
long long int
crpaic_min_lli (long long int const n1, long long int const n2)
{
    return n1 < n2 ? n1 : n2;
}

unsigned long long int
crpaic_min_ulli (unsigned long long int const n1,
                 unsigned long long int const n2)
{
    return n1 < n2 ? n1 : n2;
}

/* floating-point numbers */
float
crpaic_min_f (float const f1, float const f2)
{
    return f1 < f2 ? f1 : f2;
}

double
crpaic_min_d (double const d1, double const d2)
{
    return d1 < d2 ? d1 : d2;
}

long double
crpaic_min_ld (long double const ld1, long double const ld2)
{
    return ld1 < ld2 ? ld1 : ld2;
}
