/**
 * File    : crpaic_io.h
 * Date    : 0000-00-00 00:00 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file creates the "crpaic_io.h" interface, an Input/Ouput (I/O) module
 * for CRpaic library.
 */

#ifndef CRPAIC_IO_H
#define CRPAIC_IO_H

#include <CRpaic_globals.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Function: crpaic_get_string
 * Usage: s = crpaic_get_string(format, args);
 * -------------------------------------------
 * Prompts user for a line of text from standard input and returns it as a
 * 'string' type (char *), sans trailing line ending. Supports CR (\r), LF (\n),
 * and CRLF (\r\n) as line endings. If user inputs only a line ending,
 * return "" (the empty string), not NULL. Return NULL upon error or no input
 * whatsoever (i.e., just EOF). Stores string on HEAP, but library's destructor
 * frees memory on program's exit, making this function very friendly for
 * beginner's programmers.
 */

string
crpaic_get_string (const char *format, ...)
    __attribute__((format (printf, 1, 2)));

/**
 * Function: crpaic_get_char
 * Usage: c = crpaic_get_char(format, args);
 * -----------------------------------------
 * Prompts user for a line of text from standard input and returns the
 * equivalent char; if text is not a single char, user is prompt to retry. If
 * line can't be read, return CHAR_MAX.
 */

char
crpaic_get_char (const char *format, ...)
    __attribute__((format (printf, 1, 2)));

/**
 * Function: crpaic_get_int
 * Usage: i = crpaic_get_int(format, args);
 * ----------------------------------------
 * Prompts user for a line of text, reads the line of text from standard input
 * and scans it as an integer. The integer value is returned. If text does not
 * represent an integer in [-2^31, 2^31 - 1), or would cause underflow or
 * overflow, or if more characters follow the numer, the user is given a prompt
 * and a chance to retry. If line can't be read, returns INT_MAX.
 */

int
crpaic_get_int (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_long
 * Usage: l = crpaic_get_long(format, args);
 * -----------------------------------------
 * Prompts user for a line of text, reads the line of text from standard input
 * and scans it as a long integer. The long integer value is returned. If text
 * does not represent a long integer in [-2^63, 2^63 - 1), or would cause
 * underflow or overflow, or if more characters follow the number, the user is
 * given a prompt and a chance to retry. If line can't be read, returns
 * LONG_MAX.
 */

long int
crpaic_get_long (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_long_long
 * Usage: ll = crpaic_get_long_long(format, args);
 * -----------------------------------------------
 * Prompts user for a line of text, reads the line of text from standard input
 * and scans it as a long long integer. The long long integer value is returned.
 * If text does not represent a long long integer in [-2^63, 2^63 - 1), or would
 * cause underflow or overflow, or if more characters follow the number, the
 * user is given a prompt and a chance to retry. If line can't be read, returns
 * LLONG_MAX.
 */

long long int
crpaic_get_long_long (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_float
 * Usage: f = crpaic_get_float(format, args);
 * ------------------------------------------
 * Prompts user for a line of text, reads the line of text from stanard input
 * and scans it as a flot. The float value is returned. If text does not
 * represent a float, or would cause underflow or overflow, or if more
 * characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, return FLT_MAX.
 */

float
crpaic_get_float (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_double
 * Usage: d = crpaic_get_double(format, args);
 * -------------------------------------------
 * Prompts user for a line of text, reads the line of text from stanard input
 * and scans it as a double. The double value is returned. If text does not
 * represent a double, or would cause underflow or overflow, or if more
 * characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, return DBL_MAX.
 */

double
crpaic_get_double (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: crpaic_get_long_double
 * Usage: ld = crpaic_get_long_double(format, args);
 * -------------------------------------------------
 * Prompts user for a line of text, reads the line of text from stanard input
 * and scans it as a long double. The long double value is returned. If text
 * does not represent a long double, or would cause underflow or overflow, or if
 * more characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, return LDBL_MAX.
 */

long double
crpaic_get_long_double (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

#endif
