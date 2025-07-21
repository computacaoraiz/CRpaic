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

/**
 * Function: crpaic_string_create
 * Usage: s = crpaic_string_create(const s);
 * -----------------------------------------
 * This function takes a string, possibly enclosed in double quotes, checks the
 * length of the string, allocates enough memory on the Heap, copies the
 * received string to the Heap, and returns this new string (the pointer to the
 * string on the Heap). If the string cannot be copied to the Heap, returns
 * NULL. The user cannot pass a NULL string.
 *
 * NOTE: the user must deallocate the string with the 'crpaic_string_destroy'
 * procedure.
 *
 * The purpose of this function is to enable beginning students to dynamically
 * allocate strings without having to worry too much about memory management.
 */

string
crpaic_string_create (const string s)
    __attribute__((nonnull(1)));

/**
 * Procedure: crpaic_string_destroy
 * Usage: crpaic_string_destroy(&s);
 * ---------------------------------
 * Receives (a pointer to) a string and destroy the string by releasing the
 * allocated memory. Also sets the pointer to NULL.
 */

void
crpaic_string_destroy (string *s);

/**
 * Function: crpaic_substring
 * Usage: s = crpaic_substring(s, p1, p2);
 * ---------------------------------------
 * Returns a copy of the substring of "s" consisting of the characters between
 * index positions "p1" and "p2", inclusive. The following special cases apply:
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
crpaic_substring (const string s, int p1, int p2);

/**
 * Function: crpaic_ithchar
 * Usage: c = crpaic_ithchar(s, i);
 * --------------------------------
 * Returns the caracter at the position "i" in the string "s". It is included
 * in the library to make the type string a true abstract data type in the sense
 * that all of the necessary operations can be invoked using functions (which
 * means that the client relies only on the operations defined for the type
 * crpaic_string, and not on the underlying representation). Calling
 * crpaic_ithchar(s, i) is like selecting s[i], except that crpaic_ithchar
 * checks to see if "i" is within the range of legal index positions, which
 * extend from 0 to strlen(s). Calling crpaic_ithchar(s, strlen(s)) returns the
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
crpaic_ithchar (const string s, int i)
    __attribute__((nonnull(1)));

/**
 * Function: crpaic_concat
 * Usage: s3 = crpaic_concat(s1, s2);
 * ----------------------------------
 * This function concatenates two strings by joining them end to end. The
 * function appends a copy of the string "s2" (including the null character)
 * to the end of a copy of "s1" (the initial character of "s2" overwrites
 * the null character at the end of "s1"), creating a new string that is
 * returned. Both "s1" and "s2" are not altered in any way. The user must
 * provide valid strings terminated by '\0'. The following cases apply:
 *
 *     1. If the user inputs 2 valid strings, the function returns a NEW
 *        string with a copy of "s1" concatenated with a copy of "s2";
 *     2. If the user inputs one or two NULL pointers, the function also
 *        returns NULL;
 *     3. If the user inputs invalid strings (without the terminating '\0', for
 *        example), the behavior is undefined.
 *
 * The user must free the memory for the concatenated string after use.
 */

string
crpaic_concat (const string restrict s1, const string restrict s2);

#endif
