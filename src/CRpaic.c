/**
 * File    : CRpaic.c
 * Version : 1.2.0
 * Date    : 2024-11-24 15:42 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file implements the "CRpaic.h" interface, a C library specifically
 * designed for studying the book "Programming Abstractions in C: A Second
 * Course in Computer Science," published by Eric S. Roberts in 1997. The goal
 * of this library is to provide a basic set of tools and conventions that
 * increase the readability of C programs, particularly as they are used in a
 * teaching environment. Although this library is designed for studying PAIC, it
 * can be applied generically to any C program.
 *
 * This library was based on:
 *    - Eric S. Roberts' cslib (https://github.com/computacaoraiz/Roberts.CS1.C)
 *    - Harvard University libcs50 (https://github.com/cs50/libcs50)
 *
 * CRpaic.h is distributed under MIT License:
 * https://opensource.org/license/mit
 *
 * Copyright (C) 2024, Computação Raiz
 *                     Abrantes Araújo Silva Filho
 *                     (abrantesasf at computacaoraiz dot com dot br)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *     The above copyright notice and this permission notice shall be included
 *     in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Other licences involved:
 *     1. From Eric S. Roberts:
 *        The cslib libraries are in the public domain and may be freely copied
 *        and distributed, although they remain under development.  No
 *        warranties are made concerning their correctness or stability, and no
 *        user support is guaranteed. Bug reports and suggestions, however, are
 *        appreciated and may be sent to Eric Roberts <ericr@aw.com>.
 *
 *     2. From Harvard CS50:
 *        BSD 3-Clause License
 *        http://www.opensource.org/licenses/BSD-3-Clause
 *        Redistribution and use in source and binary forms, with or without
 *        modification, are permitted provided that the following conditions are
 *        met:
 *            * Redistributions of source code must retain the above copyright
 *              notice, this list of conditions and the following disclaimer.
 *            * Redistributions in binary form must reproduce the above
 *              copyright notice, this list of conditions and the following
 *              disclaimer in the documentation and/or other materials provided
 *              with the distribution.
 *            * Neither the name of CS50 nor the names of its contributors may
 *              be used to endorse or promote products derived from this
 *              software without specific prior written permission.
 *        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *        "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *        LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *        A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *        HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *        SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *        LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *        DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *        THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *        (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *        OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*** 1. Feature Macros and Includes ***/

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

#include "CRpaic.h"

/*** 2. Symbolic Constants and Globals ***/

/*** 2.1. Private Constants and Globals ***/

/**
 * 2.1.1. Variable: total_allocations
 * ----------------------------------
 * Keep the total number of strings allocated on HEAP by _get_string.
 */

static size_t total_allocations = 0;

/**
 * 2.1.2. Variable: arr_strings
 * ----------------------------
 * Array of strings allocated on HEAP by get_string.
 */

static string *arr_strings = NULL;

/*** 2.2. Exported Constants and Globals ***/

/*** 3. Data Types ***/

/*** 3.1. Private Data Types ***/

/*** 3.2. Exported Data Types ***/

/*** 4. Subprograms Declarations ***/

/*** 4.1. Private Subprograms Declarations ***/

/**
 * 4.1.1 Function: _get_string
 * Usage: s = _get_string(&args, &format);
 * ---------------------------------------
 * This internal function is used by get_char, get_int, get_float and other
 * functions to avoid passing a non-literal format string to a function with
 * the "format" attribute (get_string) when there are no variadic arguments.
 * All get_* functions in this library use "get_string" to get the line from
 * user to processing, and "get_string" receives a format string and variadic
 * arguments for checking. But when "get_string" is called from inside other
 * funcionts (like get_int) the "format" is repassed as a non-literal string
 * and with no variadic arguments, and so the compiler can't perform the
 * check on the format string. The solution is to separate the functions that
 * use "format" attribute from those that don't. So in this library, the
 * internal _get_string funciont does not use "format", but the external
 * get_string does. As the external get_string uses "format", the compiler
 * does the validity check normally, ensuring that the format is safe.
 *
 * Adapted from Harvard libcs50: prompts user for a line of text from standard
 * input and returns it as a string (char *), sans trailing line ending.
 * Supports CR (\r), LF (\n), and CRLF (\r\n) as line endings. If user inputs
 * only a line ending, return "", not NULL. Return NULL upon error or no input
 * whatsoever (i.e., just EOF). Stores string on HEAP, but library's destructor
 * frees memory on program's exit.
 */

static string
_get_string (va_list *args, const char *format);

/**
 * 4.1.2. Procedure: teardown
 * Usage: teardown( );
 * ---------------------------
 * Iterate on arrays of strings allocated, and free strings.
 */

static void
teardown (void);

/*** 4.2. Exported Subprograms Declarations ***/

/*** 5. Subprograms Definitions ***/

/*** 5.1. Private Subprograms Definitions ***/

/**
 * 5.1.1. Function: _get_string
 * Usage: s = _get_string(&args, &format);
 * ---------------------------------------
 * Implements _get_string internal function. Receives a pointer to an args list
 * and a point to a format string, previously validated by get_string, and
 * return a string.
 */

static string
_get_string (va_list *args, const char *format)
{
    // Checks if the number of allocations has exceeded the theoretical
    // mathematical limit representable in "size_t". This check does not
    // guarantee that memory will be available on the system, but it does ensure
    // that no overflow will occur in calculations related to memory allocation.
    if (total_allocations == SIZE_MAX / sizeof(string))
    {
        return NULL;
    }

    // Prompt user:
    if (format)
    {
        // Initialize variadic argument list:
        va_list ap;

        // Client code will pass in printf-like arguments as variadic
        // parameters. The client-facing get_string macro always set args to
        // NULL. In this case, we initialize the list of variadic parameters
        // the standard way with va_start.
        if (!args)
        {
            fprintf(stderr, "Error: args cannot be null.\n");
            return NULL;
        }

        // When functions in this library call get_string, they will have
        // already stored their variadic parameters in a "va_list" and so they
        // just pass that in by pointer:
        else
        {
            // Put a copy of argument list in ap so it's not consumed by vprintf
            va_copy(ap, *args);
        }

        // Print prompt:
        vprintf(format, ap);

        // Clean up argument list:
        va_end(ap);
    }

    // Creates a dynamic character buffer, controling the allocated size
    // (buffer_capacity) and effective size (buffer_size) of the buffer:
    string buffer = NULL;
    size_t buffer_capacity = 0;
    size_t buffer_size = 0;

    // Character (or EOF) read:
    int c;

    // Iteratively get characters from standard input, checking for CR (Mac OS),
    // LF (Linux), CRLF (Windows), and EOF:
    while ((c = fgetc(stdin)) != '\r' && c != '\n' && c != EOF)
    {
        // Grow buffer if necessary
        if (buffer_size + 1 > buffer_capacity)
        {
            // Increment buffer's capacity size variable if possible
            if (buffer_capacity < SIZE_MAX)
            {
                buffer_capacity++;
            }
            else
            {
                free(buffer);
                return NULL;
            }

            // Extend buffer's allocated size using the new buffer capacity:
            string temp = realloc(buffer, buffer_capacity);
            if (!temp)
            {
                free(buffer);
                return NULL;
            }

            // "New" buffer:
            buffer = temp;
        }

        // Append current character to buffer, incrementing the buffer effective
        // size variable (buffer_size):
        buffer[buffer_size++] = c;
    }

    // Check whether user provided no input:
    if (buffer_size == 0 && c == EOF)
    {
        return NULL;
    }

    // Check whether user provided too much input (leaving no room for trailing
    // NULL character):
    if (buffer_size == SIZE_MAX)
    {
        free(buffer);
        return NULL;
    }

    // If last character read was CR, try to read LF as well:
    if (c == '\r' && (c = fgetc(stdin)) != '\n')
    {
        // Return NULL if character can't be pushed back onto standard input
        if (c != EOF && ungetc(c, stdin) == EOF)
        {
            free(buffer);
            return NULL;
        }
    }

    // Reallocate buffer to a "new" string, plus 1 byte (for '\0'):
    string s = realloc(buffer, buffer_size + 1);
    if (!s)
    {
        free(buffer);
        return NULL;
    }
    s[buffer_size] = '\0';

    // Resize the array of strings to open space for future inclusion of the
    // new string:
    string *temp = realloc(arr_strings,
                           sizeof(string) * (total_allocations + 1));
    if (!temp)
    {
        free(s);
        return NULL;
    }
    arr_strings = temp;

    // Append the new string into the new space opened on the arrays of strings
    // (and increment total allocations count):
    arr_strings[total_allocations++] = s;

    // Finally, return the pointer to the new string:
    return s;    
}

/**
 * 5.1.2. Procedure: teardown
 * Usage: teardown( );
 * --------------------------
 * Called automatically after execution exits main.
 */

static void
teardown (void)
{
    if (arr_strings)
    {
        for (size_t i = 0; i < total_allocations; i++)
        {
            free(arr_strings[i]);
            arr_strings[i] = NULL;
        }
        free(arr_strings);
        arr_strings = NULL;
    }
}

/*** 5.2. Exported Subprograms Definitions ***/

/*** 5.2.1. I/O Subprograms Definitions ***/

/**
 * 5.2.1.1 Function: get_string
 * Usage: s = get_string(format, args);
 * ------------------------------------
 * This function is a wrapper to pass the format string ("format") and variadic
 * arguments ("ap") to _get_string, who really does the processing of getting a
 * string from the user.
 */

string
get_string (const char *format, ...)
{
    // Initializes argument list:
    va_list ap;
    va_start(ap, format);

    // Process the input from user, putting the string in result:
    string result = _get_string(&ap, format);

    // Finalizes argument list and return result:
    va_end(ap);
    return result;
}

/**
 * 5.2.1.2. Function: get_char
 * Usage: c = get_char(format, args);
 * ----------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text from standard
 * input and returns the equivalent char; if text is not a single char, user is
 * prompt to retry. If line can't be read, return CHAR_MAX.
 */

char
get_char (const char *format, ...)
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a char from user
    while (true)
    {
        // Get line of text, returning CHAR_MAX on failure
        string line = _get_string(&ap,  format);
        if (!line)
        {
            va_end(ap);
            return CHAR_MAX;
        }

        // Return a char if only a char was provided
        char c, d;
        if (sscanf(line, "%c%c", &c, &d) == 1)
        {
            va_end(ap);
            return c;
        }
    }
}

/**
 * 5.2.1.3. Function: get_int
 * Usage: i = get_int(format, args);
 * ---------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from standard input and scans it as an integer. The integer value is
 * returned. If text does not represent an integer in [-2^31, 2^31 - 1), or
 * would cause underflow or overflow, or if more characters follow the numer,
 * the user is given a prompt and a chance to retry. If line can't be read,
 * returns INT_MAX.
 */

int
get_int (const char *format, ...)
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get an int from user
    while (true)
    {
        // Get line of text, returning INT_MAX on failure
        string line = _get_string(&ap,  format);
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
 * 5.2.1.4. Function: get_long
 * Usage: l = get_long(format, args);
 * ----------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from standard input and scans it as an long integer. The long integer
 * value is returned. If text does not represent a long integer in
 * [-2^63, 2^63 - 1), or would cause underflow or overflow, or if more
 * characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, returns LONG_MAX.
 */

long int
get_long (const char *format, ...)
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a long int from user
    while (true)
    {
        // Get line of text, returning LONG_MAX on failure
        string line = _get_string(&ap,  format);
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
 * 5.2.1.5. Function: get_long_long
 * Usage: ll = get_long_long(format, args);
 * ----------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from standard input and scans it as an long long integer. The long
 * long integer value is returned. If text does not represent a long long
 * integer in [-2^63, 2^63 - 1), or would cause underflow or overflow, or if
 * more characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, returns LLONG_MAX.
 */

long long int
get_long_long (const char *format, ...)
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a long long int from user
    while (true)
    {
        // Get line of text, returning LLONG_MAX on failure
        string line = _get_string(&ap,  format);
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
 * 5.2.1.6. Function: get_float
 * Usage: f = get_float(format, args);
 * -----------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from stanard input and scans it as a flot. The float value is
 * returned. If text does not represent a float, or would cause underflow or
 * overflow, or if more characters follow the number, the user is given a prompt
 * and a chance to retry. If line can't be read, return FLT_MAX.
 */

float
get_float (const char *format, ...)
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a float from user
    while (true)
    {
        // Get line of text, returning FLT_MAX on failure
        string line = _get_string(&ap,  format);
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
 * 5.2.1.7. Function: get_double
 * Usage: d = get_double(format, args);
 * -----------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from stanard input and scans it as a double. The double value is
 * returned. If text does not represent a double, or would cause underflow or
 * overflow, or if more characters follow the number, the user is given a prompt
 * and a chance to retry. If line can't be read, return DBL_MAX.
 */

double
get_double (const char *format, ...)
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a double from user
    while (true)
    {
        // Get line of text, returning DBL_MAX on failure
        string line = _get_string(&ap,  format);
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
 * 5.2.1.8. Function: get_long_double
 * Usage: d = get_long_double(format, args);
 * -----------------------------------------
 * Prompts user for a line of text, reads the line of text from stanard input
 * and scans it as a long double. The long double value is returned. If text
 * does not represent a long double, or would cause underflow or overflow, or if
 * more characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, return LDBL_MAX.
 */

long double
get_long_double (const char *format, ...)
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a long double from user
    while (true)
    {
        // Get line of text, returning LDBL_MAX on failure
        string line = _get_string(&ap,  format);
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

/*** 5.2.2. String Subprograms Declarations ***/

/**
 * 5.2.2.1. Function: substring
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
substring (const string s, int p1, int p2)
{
    // If user does not provides a valid string, return NULL:
    if (!s)
    {
        return NULL;
    }

    // Adjust p1 and p2 to conform to limits of string length:
    int n = strlen(s);
    if (p1 < 0)
        p1 = 0;
    if (p2 >= n)
        p2 = n - 1;

    // Calculates how much space we'll need to alocate (not counting final \0)
    // for the new substring. If p1 > p2 we keep tam = 0 (the user provides
    // erroneous input and we'll return just an empty string).
    int tam = 0;
    if (p1 <= p2)
        tam = p2 - p1 + 1;

    // Alocates the new substring, adding 1 for final \0:
    string temp = malloc(sizeof(char) * (tam + 1));
    if (!temp)
    {
        return NULL;
    }

    // Makes a copy of the substring between p1 and p2, inclusive. After the
    // copy, include final \0.
    int i = p1, j = 0;
    while (i <= p2)
    {
        temp[j++] = s[i++];
    }
    temp[j] = '\0';

    // Return the substring:
    return temp;
}


/*** 6. Miscelaneus ***/

/**
 * Preprocessor magic
 * ------------------
 * Makes initializers work somewhat portably. Modified from:
 * stackoverflow.com/questions/1113409/attribute-constructor-equivalent-in-vc
 */

#if defined (_MSC_VER) // MSVC
    #pragma section(".CRT$XCU",read)
    #define INITIALIZER_(FUNC,PREFIX) \
        static void FUNC(void); \
        __declspec(allocate(".CRT$XCU")) void (*FUNC##_)(void) = FUNC; \
        __pragma(comment(linker,"/include:" PREFIX #FUNC "_")) \
        static void FUNC(void)
    #ifdef _WIN64
        #define INITIALIZER(FUNC) INITIALIZER_(FUNC,"")
    #else
        #define INITIALIZER(FUNC) INITIALIZER_(FUNC,"_")
    #endif
#elif defined (__GNUC__) // GCC, Clang, MinGW
    #define INITIALIZER(FUNC) \
        static void FUNC (void) __attribute__((constructor)); \
        static void FUNC (void)
#else
    #error The CRpaic library requires some compiler-specific features, \
           but we do not recognize this compiler/version. Please file an issue \
           at https://github.com/computacaoraiz/CRpaic
#endif

/**
 * Initializer
 * -----------
 * Called automatically before execution enters main.
 */

INITIALIZER(setup)
{
    // Disable buffering for standard output:
    setvbuf(stdout, NULL, _IONBF, 0);

    // At main exit, free allocated strings:
    atexit(teardown);
}
