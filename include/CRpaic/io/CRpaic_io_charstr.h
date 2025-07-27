/**
 * File    : CRpaic_io_charstr.h
 * Date    : 2025-07-25 21:36 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This interface is part of the I/O module of the CRpaic Library, and declares
 * subprograms and resources useful for obtaining single character and string
 * input from the user.
 */

/* Start of include guard: */
#ifndef CRPAIC_IO_CHARSTR_H
#define CRPAIC_IO_CHARSTR_H

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <CRpaic/CRpaic_globals.h>

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
 * Function: crpaic_vget_string
 * Usage: s = crpaic_vget_string(format, args);
 * --------------------------------------------
 * Receives a constant string representing a format string and a list of
 * arguments (va_list) to prompt the user for a line of text from standard input
 * and returns it as a 'string' type (char *), sans trailing line ending. It is
 * equivalent to crpaic_get_string. Attention: the "args" va_list must already
 * be validated by the user.
 */

string
crpaic_vget_string (char const *format, va_list args);

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

/* End of include guard: */
#endif
