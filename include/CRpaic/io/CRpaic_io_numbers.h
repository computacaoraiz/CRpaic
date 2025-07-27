/**
 * File    : CRpaic_io_numbers.h
 * Date    : 2025-07-26 15:44 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This interface is part of the I/O module of the CRpaic library, and declares
 * subprograms and resources useful for obtaining numeric input from users
 * (integer and floating point).
 */

/* Start of include guard: */
#ifndef CRPAIC_IO_NUMBERS_H
#define CRPAIC_IO_NUMBERS_H

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <CRpaic/CRpaic_globals.h>

/**
 * Function: crpaic_get_int
 * Usage: i = crpaic_get_int(format, args);
 * ----------------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from standard input and scans it as an integer. The integer value is
 * returned. If text does not represent an integer in [-2^31, 2^31 - 1), or
 * would cause underflow or overflow, or if more characters follow the numer,
 * the user is given a prompt and a chance to retry. If line can't be read,
 * returns INT_MAX.
 */

int
crpaic_get_int (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_long
 * Usage: l = crpaic_get_long(format, args);
 * -----------------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from standard input and scans it as an long integer. The long integer
 * value is returned. If text does not represent a long integer in
 * [-2^63, 2^63 - 1), or would cause underflow or overflow, or if more
 * characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, returns LONG_MAX.
 */

long int
crpaic_get_long (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_long_long
 * Usage: ll = crpaic_get_long_long(format, args);
 * -----------------------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from standard input and scans it as an long long integer. The long
 * long integer value is returned. If text does not represent a long long
 * integer in [-2^63, 2^63 - 1), or would cause underflow or overflow, or if
 * more characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, returns LLONG_MAX.
 */

long long int
crpaic_get_long_long (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_float
 * Usage: f = crpaic_get_float(format, args);
 * ------------------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from stanard input and scans it as a flot. The float value is
 * returned. If text does not represent a float, or would cause underflow or
 * overflow, or if more characters follow the number, the user is given a prompt
 * and a chance to retry. If line can't be read, return FLT_MAX.
 */

float
crpaic_get_float (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_double
 * Usage: d = crpaic_get_double(format, args);
 * -------------------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from stanard input and scans it as a double. The double value is
 * returned. If text does not represent a double, or would cause underflow or
 * overflow, or if more characters follow the number, the user is given a prompt
 * and a chance to retry. If line can't be read, return DBL_MAX.
 */

double
crpaic_get_double (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_long_double
 * Usage: d = crpaic_get_long_double(format, args);
 * ------------------------------------------------
 * Prompts user for a line of text, reads the line of text from stanard input
 * and scans it as a long double. The long double value is returned. If text
 * does not represent a long double, or would cause underflow or overflow, or if
 * more characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, return LDBL_MAX.
 */

long double
crpaic_get_long_double (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/* End of include guard: */
#endif
