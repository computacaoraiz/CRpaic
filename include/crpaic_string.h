/**
 * File    : crpaic_string.h
 * Date    : 0000-00-00 00:00 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file creates the "crpaic_string.h" interface, a module with utilities
 * for string processing.
 */

#ifndef CRPAIC_STRING_H
#define CRPAIC_STRING_H

#include <crpaic_globals.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 4.2.2.1. Function: substring
 * Usage: s = substring(s, p1, p2);
 * --------------------------------
 * Adapted from Robert's cslib: returns a copy of the substring of "s"
 * consisting of the characters between index positions "p1" and "p2",
 * inclusive. The following special cases apply:
 *
 *     1. If p1 < 0, it is assumed to be 0;
 *     2. If p2 > (strlen(s) - 1), it is assumed to be (strlen(s) - 1); and
 *     3. If p2 < p1, the function returns the empty string.
 *
 * The user must provide a valid string s argument (not NULL). If user provides
 * an invalid string (a NULL string), returns NULL. If there is an error on
 * memory allocation for the substring, returns NULL.
 *
 * The user must free the memory of substring after use.
 */

string
substring (const string s, int p1, int p2);

/**
 * 4.2.2.2. Function: ithchar
 * Usage: c = ithchar(s, i);
 * -------------------------
 * Adapted from Robert's cslib: returns the caracter at the position "i" in the
 * string "s". It is included in the library to make the type string a true
 * abstract data type in the sense that all of the necessary operations can be
 * invoked using functions (which means that the client relies only on the
 * operations defined for the type string, and not on the underlying
 * representation). Calling ithchar(s, i) is like selecting s[i], except that
 * ithchar checks to see if "i" is within the range of legal index positions,
 * which extend from 0 to strlen(s). Calling ithchar(s, strlen(s)) returns the
 * null character at the end of string. The following special cases apply:
 *
 *     1. If i < 0, it is assumed to be 0 to point to first character; and
 *     2. If i > strlen(s), it is assumed to be strlen(s) to point to last
 *        character.
 *
 * The function does not accept a NULL string as argument (has the attribute
 * "nonnull"), so the user must provide a valid string "s".
 */

char
ithchar (const string s, int i)
    __attribute__((nonnull(1)));

/**
 * 4.2.2.3. Function: concat
 * Usage: str3 = concat(str1, str2);
 * ---------------------------------
 * Adapted from Robert's cslib: this function concatenates two strings by
 * joining them end to end. The function appends a copy of the string "str2"
 * (including the null character) to the end of a copy of "str1" (the initial
 * character of "str2" overwrites the null character at the end of "str1"),
 * creating a new string that is returned. Both "str1" and "str2" are not
 * altered in any way. The user must provide valid strings terminated by '\0'.
 * The following cases apply:
 *
 *     1. If the user inputs 2 valid strings, the function returns a NEW
 *        string with a copy of "str1" concatenated with a copy of "str2";
 *     2. If the user inputs one or two NULL pointers, the function also
 *        returns NULL;
 *     3. If the user inputs invalid strings (without the terminating '\0', for
 *        example), the behavior is undefined.
 *
 * The user must free the memory for the concatenated string after use.
 */

string
concat (const string restrict str1, const string restrict str2);

/*** 0. End of Interface Boilerplate ***/

#endif
