/**
 * File    : CRpaic_io_numbers.c
 * Date    : 2025-07-26 15:54 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file implements the "CRpaic_io_numbers.h" interface, a module
 * useful for obtaining numeric input from users (integer and floating point).
 */

#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CRpaic/CRpaic_globals.h>
#include <CRpaic/io/CRpaic_io_charstr.h>
#include <CRpaic/io/CRpaic_io_numbers.h>

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
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get an int from user
    while (true)
    {
        // Get line of text, returning INT_MAX on failure
        string line = crpaic_vget_string(format, ap);
        if (!line)
        {
            va_end(ap);
            return INT_MAX;
        }

        // Return an int if only an int (in range) was provided, considering
        // that the user input is in base 10. Force the input to have no
        // leading whitespace or invalid characters, and no trailing whitespace
        // or invalid characters.
        if (strlen(line) > 0 && !isspace((unsigned char) line[0]))
        {
            char *endptr;
            errno = 0;
            long int n = strtol(line, &endptr, 10);
            
            // If there is no error, and if there are no invalid characters
            // after line (nptr), and if n is in [INT_MIN, INT_MAX), return n:
            if (errno == 0 && *endptr == '\0' && n >= INT_MIN && n < INT_MAX)
            {
                va_end(ap);
                return (int) n;
            }
        }
    }
}

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
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a long int from user
    while (true)
    {
        // Get line of text, returning LONG_MAX on failure
        string line = crpaic_vget_string(format, ap);
        if (!line)
        {
            va_end(ap);
            return LONG_MAX;
        }

        // Return a long int if only a long int (in range) was provided,
        // considering that the user input is in base 10. Force the input to
        // have no leading whitespace or invalid characters, and no trailing
        // whitespace or invalid characters.
        if (strlen(line) > 0 && !isspace((unsigned char) line[0]))
        {
            char *endptr;
            errno = 0;
            long int n = strtol(line, &endptr, 10);
            
            // If there is no error, and if there are no invalid characters
            // after line (nptr), and if n is in [LONG_MIN, LONG_MAX), return n:
            if (errno == 0 && *endptr == '\0' && n >= LONG_MIN && n < LONG_MAX)
            {
                va_end(ap);
                return n;
            }
        }
    }
}

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
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a long long int from user
    while (true)
    {
        // Get line of text, returning LLONG_MAX on failure
        string line = crpaic_vget_string(format, ap);
        if (!line)
        {
            va_end(ap);
            return LLONG_MAX;
        }

        // Return a long long int if only a long long int (in range) was
        // provided, considering that the user input is in base 10. Force the
        // input to have no leading whitespace or invalid characters, and no
        // trailing whitespace or invalid characters.
        if (strlen(line) > 0 && !isspace((unsigned char) line[0]))
        {
            char *endptr;
            errno = 0;
            long long int n = strtoll(line, &endptr, 10);
            
            // If there is no error, and if there are no invalid characters
            // after line (nptr), and if n is in [LLONG_MIN, LLONG_MAX),
            // return n:
            if (errno == 0 && *endptr == '\0'
                && n >= LLONG_MIN && n < LLONG_MAX)
            {
                va_end(ap);
                return n;
            }
        }
    }
}

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
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a float from user
    while (true)
    {
        // Get line of text, returning FLT_MAX on failure
        string line = crpaic_vget_string(format, ap);
        if (!line)
        {
            va_end(ap);
            return FLT_MAX;
        }

        // Return a float if only a float was provided. Force the input to have
        // no leading whitespace or invalid characters, and no trailing
        // whitespace or invalid characters.
        if (strlen(line) > 0 && !isspace((unsigned char) line[0]))
        {
            char *endptr;
            errno = 0;
            float f = strtof(line, &endptr);
            
            // If there is no error, and if there are no invalid characters
            // after line (nptr), if float is finite and if float < FLT_MAX
            // and if user does not input hexadecimal or exponentes, return f:
            if (errno == 0 && *endptr == '\0'
                && isfinite(f) != 0 && f < FLT_MAX
                && strcspn(line, "XxEePp") == strlen(line))
            {
                va_end(ap);
                return f;
            }
        }
    }
}

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
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a double from user
    while (true)
    {
        // Get line of text, returning DBL_MAX on failure
        string line = crpaic_vget_string(format, ap);
        if (!line)
        {
            va_end(ap);
            return DBL_MAX;
        }

        // Return a double if only a double was provided. Force the input to
        // have no leading whitespace or invalid characters, and no trailing
        // whitespace or invalid characters.
        if (strlen(line) > 0 && !isspace((unsigned char) line[0]))
        {
            char *endptr;
            errno = 0;
            double d = strtod(line, &endptr);
            
            // If there is no error, and if there are no invalid characters
            // after line (nptr), if double is finite and if double < DBL_MAX
            // and if user does not input hexadecimal or exponentes, return f:
            if (errno == 0 && *endptr == '\0'
                && isfinite(d) != 0 && d < DBL_MAX
                && strcspn(line, "XxEePp") == strlen(line))
            {
                va_end(ap);
                return d;
            }
        }
    }
}

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
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a long double from user
    while (true)
    {
        // Get line of text, returning LDBL_MAX on failure
        string line = crpaic_vget_string(format, ap);
        if (!line)
        {
            va_end(ap);
            return LDBL_MAX;
        }

        // Return a long double if only a long double was provided. Force the
        // input to have no leading whitespace or invalid characters, and no
        // trailing whitespace or invalid characters.
        if (strlen(line) > 0 && !isspace((unsigned char) line[0]))
        {
            char *endptr;
            errno = 0;
            long double ld = strtold(line, &endptr);
            
            // If there is no error, and if there are no invalid characters
            // after line (nptr), if long double is finite and if
            // long double < LDBL_MAX and if user does not input hexadecimal or
            // exponentes, return ld:
            if (errno == 0 && *endptr == '\0'
                && isfinite(ld) != 0 && ld < LDBL_MAX
                && strcspn(line, "XxEePp") == strlen(line))
            {
                va_end(ap);
                return ld;
            }
        }
    }
}
