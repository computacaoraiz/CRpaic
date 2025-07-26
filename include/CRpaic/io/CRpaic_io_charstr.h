/**
 * File    : crpaic_io_charstr.h
 * Date    : 2025-07-25 21:36 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file creates the "crpaic_io_charstr.h" modeule, an Input/Ouput (I/O)
 * module for char and strings.
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
